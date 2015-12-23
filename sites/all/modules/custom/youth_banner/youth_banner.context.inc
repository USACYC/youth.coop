<?php
/**
 * @file
 * youth_banner.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function youth_banner_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'banner';
  $context->description = 'add logo and blocks to all public non-admin pages';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~admin*' => '~admin*',
        '~block/add*' => '~block/add*',
        '~node/add*' => '~node/add*',
        '~civicrm*' => '~civicrm*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bean-logo' => array(
          'module' => 'bean',
          'delta' => 'logo',
          'region' => 'logo',
          'weight' => '-10',
        ),
        'block-2' => array(
          'module' => 'block',
          'delta' => '2',
          'region' => 'header',
          'weight' => '-10',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'header',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('add logo and blocks to all public non-admin pages');
  $export['banner'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'login_link';
  $context->description = 'adds log in link to banner';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~user*' => '~user*',
        '~civicrm*' => '~civicrm*',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'header',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('adds log in link to banner');
  $export['login_link'] = $context;

  return $export;
}
