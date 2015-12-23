<?php
/**
 * @file
 * Contain functions for checkout pane.
 */

/**
 * Implements base_settings_form().
 */
function youth_webform_civi_chkpane_pane_settings_form($checkout_pane) {
  $form['youth_webform_civi_chkpane_pane_nid'] = array(
    '#type' => 'select',
    '#options' => youth_webform_civi_chkpane_get_webforms(),
    '#title' => t('CiviCRM webform node id'),
    '#default_value' => variable_get('youth_webform_civi_chkpane_pane_nid', ''),
    '#required' => TRUE,
  );
  return $form;
}

/**
 * Implements base_checkout_form().
 */
function youth_webform_civi_chkpane_pane_checkout_form(&$form, &$form_state, $checkout_pane, $order) {
  $nid = variable_get('youth_webform_civi_chkpane_pane_nid', '');
  if (empty($nid)) {
    return $checkout_form;
  }
  $node = node_load($nid);
  $form['#node'] = $checkout_form['#node'] = $node;

  $submission = FALSE;
  if (!empty($_SESSION['youth_webform_civi_chkpane_sid'])) {
    module_load_include('inc', 'webform', 'includes/webform.submissions');
    $submission = webform_get_submission($node->nid, $_SESSION['youth_webform_civi_chkpane_sid']);
  }

  $checkout_form['webform'] = webform_client_form($checkout_form, $form_state, $node, $submission);
  unset($checkout_form['webform']['#submit']);
  unset($checkout_form['webform']['#validate']);
  hide($checkout_form['webform']['actions']);

  form_load_include($form_state, 'inc', 'webform_civicrm', 'includes/wf_crm_webform_preprocess');
  $processor = new wf_crm_webform_preprocess($checkout_form['webform'], $form_state);
  $processor->alterForm();

  return $checkout_form;
}

/**
 * Implements base_checkout_form_submit().
 */
function youth_webform_civi_chkpane_pane_checkout_form_submit($form, $form_state, $checkout_pane, $order) {
  global $user;

  module_load_include('inc', 'webform', 'includes/webform.submissions');
  module_load_include('inc', 'webform', 'includes/webform.components');

  $form_state['values']['submitted'] = $form_state['values']['youth_webform_civi_chkpane']['webform']['submitted'];
  $form_state['values']['details'] = $form_state['values']['youth_webform_civi_chkpane']['webform']['details'];

  $node = node_load($form_state['values']['details']['nid']);
  if (!isset($form_state['values']['submitted'])) {
    $form_state['values']['submitted'] = array();
  }

  if (isset($form_state['webform']['component_tree'])) {
    $form_state['storage']['component_tree'] = $form_state['webform']['component_tree'];
    $form_state['storage']['page_count'] = $form_state['webform']['page_count'];
    $form_state['storage']['page_num'] = $form_state['webform']['page_num'];
    $form_state['storage']['preview'] = $form_state['webform']['preview'];
  }

  $form_state['values']['submitted'] = _webform_client_form_submit_flatten($node, $form_state['values']['submitted']);

  _webform_client_form_submit_process($node, $form_state['values']['submitted']);

  $form_state['webform_completed'] = TRUE;

  $original_values = is_array($form_state['values']['submitted']) ? $form_state['values']['submitted'] : array();
  if (isset($form_state['storage']['submitted'])) {
    $original_values += $form_state['storage']['submitted'];
  }

  $form_state['values']['submitted'] = webform_get_conditional_sorter($node)->executeConditionals($original_values);

  $submit_op = !empty($form['actions']['submit']['#value']) ? $form['actions']['submit']['#value'] : t('Submit');

  $node = $form['#node'];
  $sid = $form_state['values']['details']['sid'] ? (int) $form_state['values']['details']['sid'] : NULL;

  // Check if user is submitting as a draft.
  $is_draft = (int) !empty($form_state['save_draft']);

  // To maintain time and user information, load the existing submission.
  // If a draft is deleted while a user is working on completing it, $sid will
  // exist, but webform_get_submission() will not find the draft. So, make a new
  // submission.
  if ($sid && $submission = webform_get_submission($node->webform['nid'], $sid)) {
    // Merge with new submission data. The + operator maintains numeric keys.
    // This maintains existing data with just-submitted data when a user resumes
    // a submission previously saved as a draft.
    // Remove any existing data on this and previous pages.
    // If components are hidden, they may
    // be in the $submission->data but absent entirely from $new_data;
    $page_map = webform_get_conditional_sorter($node)->getPageMap();
    for ($page_nr = 1; $page_nr <= $form_state['webform']['page_num']; $page_nr++) {
      $submission->data = array_diff_key($submission->data, $page_map[$page_nr]);
    }
    $submission->data = webform_submission_data($node, $form_state['values']['submitted']) + $submission->data;
  }
  else {
    // Create a new submission object.
    $submission = webform_submission_create($node, $user, $form_state);
    // Since this is a new submission, a new sid is needed.
    $sid = NULL;
  }

  // Save draft state, and for drafts, save the current page (if clicking next)
  // or the previous page (if not) as the last valid page.
  $submission->is_draft = $is_draft;
  $submission->highest_valid_page = 0;
  if ($is_draft) {
     $submission->highest_valid_page = end($form_state['clicked_button']['#parents']) == 'next' && $form_state['values']['op'] != '__AUTOSAVE__'
                                          ? $form_state['webform']['page_num']
                                          : $form_state['webform']['page_num'] - 1;
  }

  // If there is no data to be saved (such as on a multipage form with no fields
  // on the first page), process no further. Submissions with no data cannot
  // be loaded from the database as efficiently, so we don't save them at all.
  if (empty($submission->data)) {
    return;
  }

  // Save the submission to the database.
  if (!$sid) {
    // No sid was found thus insert it in the dataabase.
    $form_state['values']['details']['sid'] = $sid = webform_submission_insert($node, $submission);
    $form_state['values']['details']['is_new'] = TRUE;

    // Set a cookie including the server's submission time. The cookie expires
    // in the length of the interval plus a day to compensate for timezones.
    $tracking_mode = webform_variable_get('webform_tracking_mode');
    if ($tracking_mode === 'cookie' || $tracking_mode === 'strict') {
      $cookie_name = 'webform-' . $node->nid;
      $time = REQUEST_TIME;
      $params = session_get_cookie_params();
      setcookie($cookie_name . '[' . $time . ']', $time, $time + $node->webform['submit_interval'] + 86400, $params['path'], $params['domain'], $params['secure'], $params['httponly']);
    }

    // Save session information about this submission for anonymous users,
    // allowing them to access or edit their submissions.
    if (!$user->uid && user_access('access own webform submissions')) {
      $_SESSION['webform_submission'][$form_state['values']['details']['sid']] = $node->nid;
    }
  }
  else {
    // Sid was found thus update the existing sid in the database.
    webform_submission_update($node, $submission);
    $form_state['values']['details']['is_new'] = FALSE;
  }

  // Check if this form is sending an email.
  if (!$is_draft && !$form_state['values']['details']['finished']) {
    drupal_static_reset('webform_get_submission');
    $submission = webform_get_submission($node->webform['nid'], $sid);
    webform_submission_send_mail($node, $submission);
  }

  // Strip out empty tags added by WYSIWYG editors if needed.
  $message = strlen(trim(strip_tags($node->webform['confirmation']))) > 0;

  // Check confirmation and redirect_url fields.
  $redirect = NULL;
  $redirect_url = trim($node->webform['redirect_url']);
  if (isset($form['actions']['draft']['#value']) && $form_state['values']['op'] == $form['actions']['draft']['#value']) {
    $message = t('Submission saved. You may return to this form later and it will restore the current values.');
  }
  elseif ($is_draft) {
    // No redirect needed. No confirmation message needed.
    $message = FALSE;
  }
  elseif (!empty($form_state['values']['details']['finished'])) {
    $message = t('Submission updated.');
    $redirect = "node/{$node->nid}/submission/$sid";
  }
  elseif (!empty($node->webform['confirmation_block'])) {
    $message = FALSE;
    // Webform was submitted in a block and the confirmation message is to be
    // displayed in the block.
    $_SESSION['webform_confirmation'][$node->nid] = array(
      'sid' => $sid,
      'confirmation_page' => $redirect_url == '<confirmation>',
    );
    drupal_page_is_cacheable(FALSE);
  }
  elseif ($redirect_url == '<confirmation>') {
    // No confirmation message needed because it will be shown on the
    // confirmation page.
    $message = FALSE;
    $query = array('sid' => $sid);
    if ((int) $user->uid === 0) {
      $query['token'] = webform_get_submission_access_token($submission);
    }
    $redirect = array('node/' . $node->nid . '/done', array('query' => $query));
  }
  else {
    // Clean up the redirect URL, filter it for tokens and detect external
    // domains. If the redirect is to an external URL, then don't show the
    // confirmation message.
    $redirect = webform_replace_url_tokens($redirect_url, $node, $submission);
    if ($redirect[1]['#webform_external']) {
      $message = FALSE;
    }
  }

  if (!empty($sid)) {
    $_SESSION['youth_webform_civi_chkpane_sid'] = $sid;
  }

  // Show a message if manually set.
  if (is_string($message)) {
    drupal_set_message($message);
  }
  // If redirecting and we have a confirmation message, show it as a message.
  elseif ($message) {
    drupal_set_message(webform_replace_tokens($node->webform['confirmation'], $node, $submission, NULL, $node->webform['confirmation_format']));
  }

}
