<?php
/**
 * @file
 * youth_membership_product.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function youth_membership_product_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_license_line_item_types';
  $strongarm->value = array(
    'product' => 'product',
    'custom_price' => 0,
  );
  $export['commerce_license_line_item_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_license_product_types';
  $strongarm->value = array(
    'membership_product' => 'membership_product',
    'product' => 0,
  );
  $export['commerce_license_product_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_license_refresh_rate';
  $strongarm->value = '2';
  $export['commerce_license_refresh_rate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_license_refresh_timeout';
  $strongarm->value = '60';
  $export['commerce_license_refresh_timeout'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_license_role_product_types';
  $strongarm->value = array(
    'membership_product' => 'membership_product',
  );
  $export['commerce_license_role_product_types'] = $strongarm;

  return $export;
}
