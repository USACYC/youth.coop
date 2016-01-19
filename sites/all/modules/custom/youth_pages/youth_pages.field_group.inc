<?php
/**
 * @file
 * youth_pages.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function youth_pages_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cta|node|page|form';
  $field_group->group_name = 'group_cta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'CTA',
    'weight' => '4',
    'children' => array(
      0 => 'field_cta_title',
      1 => 'field_cta_description',
      2 => 'field_button_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'CTA',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-cta field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_cta|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product_group|node|page|form';
  $field_group->group_name = 'group_product_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Product Fields',
    'weight' => '5',
    'children' => array(
      0 => 'field_product',
      1 => 'field_product_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Product Fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-product-group field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_product_group|node|page|form'] = $field_group;

  return $export;
}
