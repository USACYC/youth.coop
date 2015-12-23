<?php

/**
 * @file
 * Manages webform external administration UI
 */

/**
 * Callback function to edit options
 */
function wssf_config($form, &$form_state) {

	$form = array();

	/* Twitter authorization variables */
	$form['twitter_auth'] = array(
		'#type' => 'fieldset',
		'#title' => t('Twitter App Settings'),
		'#collapsible' => TRUE,
		'#collapsed' => FALSE,
	);

	$form['twitter_auth']['wssf_consumer_key'] = array(
		'#type' => 'textfield',
		'#title' => t('Twitter App Consumer Key'),
		'#default_value' => variable_get('wssf_consumer_key', ''),
	);

	$form['twitter_auth']['wssf_consumer_secret'] = array(
		'#type' => 'textfield',
		'#title' => t('Twitter App Consumer Secret'),
		'#default_value' => variable_get('wssf_consumer_secret', ''),
	);

	$form['twitter_auth']['wssf_user_token'] = array(
		'#type' => 'textfield',
		'#title' => t('Twitter App User Token'),
		'#default_value' => variable_get('wssf_user_token', ''),
	);

	$form['twitter_auth']['wssf_user_secret'] = array(
		'#type' => 'textfield',
		'#title' => t('Twitter App User Secret'),
		'#default_value' => variable_get('wssf_user_secret', ''),
	);

	/* Facebook authorization variables */
	$form['fb_auth'] = array(
		'#type' => 'fieldset',
		'#title' => t('Facebook App Settings'),
		'#collapsible' => TRUE,
		'#collapsed' => FALSE,
	);

	$form['fb_auth']['wssf_fb_app_id'] = array(
		'#type' => 'textfield',
		'#title' => t('Facebook App ID'),
		'#default_value' => variable_get('wssf_fb_app_id', ''),
	);

	$form['fb_auth']['wssf_fb_app_secret'] = array(
		'#type' => 'textfield',
		'#title' => t('Facebook App Secret'),
		'#default_value' => variable_get('wssf_fb_app_secret', ''),
	);

	/* Twitter block */
	$form['twitter'] = array(
		'#type' => 'fieldset',
		'#title' => t('Twitter Block'),
		'#collapsible' => TRUE,
		'#collapsed' => (variable_get('wssf_enabled_block_0', 0) == 0),
	);

	$form['twitter']['wssf_enabled_block_0'] = array(
		'#type' => 'checkbox',
		'#title' => t('Enabled'),
		'#default_value' => variable_get('wssf_enabled_block_0', 0),
	);

	$form['twitter']['wssf_title_block_0'] = array(
		'#type' => 'textfield',
		'#title' => t('Block Title'),
		'#default_value' => variable_get('wssf_title_block_0', 'Twitter'),
	);

	$form['twitter']['wssf_id_block_0'] = array(
		'#type' => 'textfield',
		'#title' => t('Twitter ID'),
		'#default_value' => variable_get('wssf_id_block_0', ''),
	);

	$form['twitter']['wssf_posts_block_0'] = array(
		'#type' => 'textfield',
		'#title' => t('Number of Tweets'),
		'#default_value' => variable_get('wssf_posts_block_0', 3),
		'#size' => 2,
		'#maxlength' => 2,
		'#required' => TRUE,
	);

	$form['twitter']['wssf_date_format_block_0'] = array(
		'#type' => 'textfield',
		'#title' => t('Date format for published date'),
		'#default_value' => variable_get('wssf_date_format_block_0', ''),
		'#description' => t('Leave blank for Twitter default (mins or hours ago for same day, j M for earlier), or use php <a href="http://us1.php.net/manual/en/function.date.php">date</a> format.'),
	);

	$form['twitter']['wssf_cache_block_0'] = array(
		'#type' => 'textfield',
		'#title' => t('Cache timing (in minutes)'),
		'#default_value' => variable_get('wssf_cache_block_0', 15),
		'#size' => 2,
		'#maxlength' => 2,
		'#required' => TRUE,
	);

	/* Facebook block */
	$form['facebook'] = array(
		'#type' => 'fieldset',
		'#title' => t('Facebook Block'),
		'#collapsible' => TRUE,
		'#collapsed' => (variable_get('wssf_enabled_block_1', 0) == 0),
	);

	$form['facebook']['wssf_enabled_block_1'] = array(
		'#type' => 'checkbox',
		'#title' => t('Enabled'),
		'#default_value' => variable_get('wssf_enabled_block_1', 0),
	);

	$form['facebook']['wssf_title_block_1'] = array(
		'#type' => 'textfield',
		'#title' => t('Block Title'),
		'#default_value' => variable_get('wssf_title_block_1', 'Facebook'),
	);

	$form['facebook']['wssf_id_block_1'] = array(
		'#type' => 'textfield',
		'#title' => t('Facebook Page ID'),
		'#default_value' => variable_get('wssf_id_block_1', ''),
	);

	$form['facebook']['wssf_posts_block_1'] = array(
		'#type' => 'textfield',
		'#title' => t('Number of Posts'),
		'#default_value' => variable_get('wssf_posts_block_1', 3),
		'#size' => 2,
		'#maxlength' => 2,
		'#required' => TRUE,
	);

	$form['facebook']['wssf_date_format_block_1'] = array(
		'#type' => 'textfield',
		'#title' => t('Date format for published date'),
		'#default_value' => variable_get('wssf_date_format_block_1', ''),
		'#description' => t('Use php <a href="http://us1.php.net/manual/en/function.date.php">date</a> format'),
	);

	$form['facebook']['wssf_morelink_text_block_1'] = array(
		'#type' => 'textfield',
		'#title' => t('Text for link to Facebook page'),
		'#default_value' => variable_get('wssf_morelink_text_block_1', t('More on Facebook')),
	);

	$form['facebook']['wssf_cache_block_1'] = array(
		'#type' => 'textfield',
		'#title' => t('Cache timing (in minutes)'),
		'#default_value' => variable_get('wssf_cache_block_1', 15),
		'#size' => 2,
		'#maxlength' => 2,
		'#required' => TRUE,
	);

	/* Mixed Twitter/FB block */
	$form['mixed'] = array(
		'#type' => 'fieldset',
		'#title' => t('Mixed FB/Twitter Block'),
		'#collapsible' => TRUE,
		'#collapsed' => (variable_get('wssf_enabled_block_3', 0) == 0),
	);

	$form['mixed']['wssf_enabled_block_3'] = array(
		'#type' => 'checkbox',
		'#title' => t('Enabled'),
		'#default_value' => variable_get('wssf_enabled_block_3', 0),
	);

	$form['mixed']['wssf_title_block_3'] = array(
		'#type' => 'textfield',
		'#title' => t('Block Title'),
		'#default_value' => variable_get('wssf_title_block_3', 'Social Media'),
	);

	$form['mixed']['wssf_posts_block_3'] = array(
		'#type' => 'textfield',
		'#title' => t('Number of Posts/Tweets'),
		'#default_value' => variable_get('wssf_posts_block_3', 3),
		'#size' => 2,
		'#maxlength' => 2,
		'#required' => TRUE,
	);

	$form['mixed']['wssf_mixed_min_fb'] = array(
		'#type' => 'textfield',
		'#title' => t('Minimum Facebook Posts'),
		'#default_value' => variable_get('wssf_mixed_min_fb', 1),
		'#size' => 2,
		'#maxlength' => 2,
		'#description' => t('The minimum number of Facebook posts to display (if you tweet more frequently than you post on Facebook)'),
		'#required' => TRUE,
	);

	$form['mixed']['wssf_cache_block_3'] = array(
		'#type' => 'textfield',
		'#title' => t('Cache timing (in minutes)'),
		'#default_value' => variable_get('wssf_cache_block_3', 15),
		'#size' => 2,
		'#maxlength' => 2,
		'#required' => TRUE,
	);

	return system_settings_form($form);
}

function wssf_config_validate($form, &$form_state) {
	$values = $form_state['values'];

	// number-of-post settings must be numbers
	for($i=0;$i<4;$i++) {
		if ($i == 2) { continue; }
		$posts = $values['wssf_posts_block_'.$i];
		if ((!is_numeric($posts) || intval($posts) != $posts)) {
			form_set_error('wssf_posts_block_'.$i,t('Number of posts must be an integer.'));
		}
	}
	$posts = $values['wssf_mixed_min_fb'];
	if ((!is_numeric($posts) || intval($posts) != $posts)) {
		form_set_error('wssf_mixed_min_fb',t('Minimum Facebook posts must be an integer.'));
	}

	// all blocks require id's to be set
	for($i=0;$i<2;$i++) {
		if ($values['wssf_enabled_block_'.$i] && !$values['wssf_id_block_'.$i]) {
			form_set_error('wssf_id_block_'.$i,t('Must provide username or id for all enabled blocks'));
		}
	}
	if ($values['wssf_enabled_block_3'] && !$values['wssf_id_block_0']) {
		form_set_error('wssf_id_block_0',t('Mixed block can only be enabled if you provide a Twitter ID in the Twitter block'));
	}
	if ($values['wssf_enabled_block_3'] && !$values['wssf_id_block_1']) {
		form_set_error('wssf_id_block_1',t('Mixed block can only be enabled if you provide a Facebook Page ID in the Facebook block'));
	}

	// if twitter or mixed blocks are enabled, twitter auth has to be entered
	if ($values['wssf_enabled_block_0'] || $values['wssf_enabled_block_3']) {
		$twitter_auth_fields = array('wssf_consumer_key','wssf_consumer_secret','wssf_user_token','wssf_user_secret');
		foreach ($twitter_auth_fields as $f) {
			if (!$values[$f]) { form_set_error($f,t('Twitter and Mixed Blocks cannot be enabled unless Twitter App authorization information is entered.')); }
		}
	}

	// if FB or mixed blocks are enabled, FB auth has to be entered
	if ($values['wssf_enabled_block_1'] || $values['wssf_enabled_block_3']) {
		$fb_auth_fields = array('wssf_fb_app_id','wssf_fb_app_secret');
		foreach ($fb_auth_fields as $f) {
			if (!$values[$f]) { form_set_error($f,t('Facebook and Mixed Blocks cannot be enabled unless Facebook App authorization information is entered.')); }
		}
	}
}


