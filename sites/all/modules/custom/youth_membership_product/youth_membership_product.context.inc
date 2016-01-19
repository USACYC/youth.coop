<?php
/**
 * @file
 * youth_membership_product.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function youth_membership_product_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'checkout_completion_page';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'checkout/*/complete' => 'checkout/*/complete',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'addtoany-addtoany_button' => array(
          'module' => 'addtoany',
          'delta' => 'addtoany_button',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['checkout_completion_page'] = $context;

  return $export;
}
