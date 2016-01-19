<?php
/**
 * @file
 * youth_membership_product.features.inc
 */

/**
 * Implements hook_default_cl_billing_cycle_type().
 */
function youth_membership_product_default_cl_billing_cycle_type() {
  $items = array();
  $items['monthly'] = entity_import('cl_billing_cycle_type', '{
    "engine" : "periodic",
    "name" : "monthly",
    "title" : "Monthly",
    "prepaid" : null,
    "wrapper" : {},
    "pce_period" : { "und" : [ { "value" : "month" } ] },
    "pce_async" : { "und" : [ { "value" : "0" } ] },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_commerce_line_item_default_types().
 */
function youth_membership_product_commerce_line_item_default_types() {
  $items = array(
    'custom_price' => array(
      'name' => 'Custom Price',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Add product',
      'base' => 'commerce_product_line_item',
    ),
  );
  return $items;
}

/**
 * Implements hook_commerce_product_default_types().
 */
function youth_membership_product_commerce_product_default_types() {
  $items = array(
    'membership_product' => array(
      'type' => 'membership_product',
      'name' => 'Membership Product',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
    'product' => array(
      'type' => 'product',
      'name' => 'Product',
      'description' => 'A basic product type.',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function youth_membership_product_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
