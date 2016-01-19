<?php
/**
 * @file
 * youth_pages.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function youth_pages_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__page';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'show_product_with_custom_price' => array(
        'custom_settings' => TRUE,
      ),
      'hidden' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'custom_sidebar' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '2',
        ),
      ),
      'display' => array(
        'product:sku' => array(
          'default' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
          'show_product_with_custom_price' => array(
            'weight' => '14',
            'visible' => FALSE,
          ),
          'hidden' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'custom_sidebar' => array(
            'weight' => '18',
            'visible' => FALSE,
          ),
        ),
        'product:title' => array(
          'default' => array(
            'weight' => '16',
            'visible' => FALSE,
          ),
          'show_product_with_custom_price' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
          'hidden' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'custom_sidebar' => array(
            'weight' => '19',
            'visible' => FALSE,
          ),
        ),
        'product:status' => array(
          'default' => array(
            'weight' => '19',
            'visible' => FALSE,
          ),
          'show_product_with_custom_price' => array(
            'weight' => '20',
            'visible' => FALSE,
          ),
          'hidden' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'custom_sidebar' => array(
            'weight' => '21',
            'visible' => FALSE,
          ),
        ),
        'product:commerce_price' => array(
          'default' => array(
            'weight' => '18',
            'visible' => FALSE,
          ),
          'show_product_with_custom_price' => array(
            'weight' => '17',
            'visible' => FALSE,
          ),
          'hidden' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'custom_sidebar' => array(
            'weight' => '20',
            'visible' => FALSE,
          ),
        ),
        'product:commerce_recurring_ini_price' => array(
          'default' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
          'show_product_with_custom_price' => array(
            'weight' => '18',
            'visible' => FALSE,
          ),
          'hidden' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'custom_sidebar' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
        ),
        'product:commerce_recurring_rec_price' => array(
          'default' => array(
            'weight' => '17',
            'visible' => FALSE,
          ),
          'show_product_with_custom_price' => array(
            'weight' => '19',
            'visible' => FALSE,
          ),
          'hidden' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'custom_sidebar' => array(
            'weight' => '17',
            'visible' => FALSE,
          ),
        ),
        'product:commerce_recurring_ini_period' => array(
          'default' => array(
            'weight' => '23',
            'visible' => FALSE,
          ),
          'show_product_with_custom_price' => array(
            'weight' => '21',
            'visible' => FALSE,
          ),
          'hidden' => array(
            'weight' => '13',
            'visible' => FALSE,
          ),
          'custom_sidebar' => array(
            'weight' => '23',
            'visible' => FALSE,
          ),
        ),
        'product:commerce_recurring_rec_period' => array(
          'default' => array(
            'weight' => '25',
            'visible' => FALSE,
          ),
          'show_product_with_custom_price' => array(
            'weight' => '22',
            'visible' => FALSE,
          ),
          'hidden' => array(
            'weight' => '14',
            'visible' => FALSE,
          ),
          'custom_sidebar' => array(
            'weight' => '25',
            'visible' => FALSE,
          ),
        ),
        'product:commerce_recurring_end_period' => array(
          'default' => array(
            'weight' => '26',
            'visible' => FALSE,
          ),
          'show_product_with_custom_price' => array(
            'weight' => '23',
            'visible' => FALSE,
          ),
          'hidden' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
          'custom_sidebar' => array(
            'weight' => '26',
            'visible' => FALSE,
          ),
        ),
        'product:cl_billing_cycle_type' => array(
          'default' => array(
            'weight' => '23',
            'visible' => FALSE,
          ),
          'custom_sidebar' => array(
            'weight' => '25',
            'visible' => FALSE,
          ),
        ),
        'product:cl_billing_type' => array(
          'default' => array(
            'weight' => '24',
            'visible' => FALSE,
          ),
          'custom_sidebar' => array(
            'weight' => '26',
            'visible' => FALSE,
          ),
        ),
        'product:cl_schedule_changes' => array(
          'default' => array(
            'weight' => '25',
            'visible' => FALSE,
          ),
          'custom_sidebar' => array(
            'weight' => '27',
            'visible' => FALSE,
          ),
        ),
        'product:commerce_license_duration' => array(
          'default' => array(
            'weight' => '22',
            'visible' => FALSE,
          ),
          'custom_sidebar' => array(
            'weight' => '24',
            'visible' => FALSE,
          ),
        ),
        'product:commerce_license_role' => array(
          'default' => array(
            'weight' => '20',
            'visible' => FALSE,
          ),
          'custom_sidebar' => array(
            'weight' => '22',
            'visible' => FALSE,
          ),
        ),
        'product:commerce_license_type' => array(
          'default' => array(
            'weight' => '21',
            'visible' => FALSE,
          ),
          'custom_sidebar' => array(
            'weight' => '23',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_page';
  $strongarm->value = array(
    0 => 'menu-about',
    1 => 'menu-allies',
    2 => 'menu-initiatives',
    3 => 'menu-membership',
    4 => 'menu-programs',
    5 => 'menu-voice',
  );
  $export['menu_options_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_page';
  $strongarm->value = 'menu-about:0';
  $export['menu_parent_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_page';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_page';
  $strongarm->value = '1';
  $export['node_preview_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_page';
  $strongarm->value = 0;
  $export['node_submitted_page'] = $strongarm;

  return $export;
}
