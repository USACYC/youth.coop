<?php
/**
 * @file
 * youth_config.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function youth_config_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_additional_html';
  $strongarm->value = '<a class="a2a_button_facebook"></a>
<a class="a2a_button_twitter"></a>
<a class="a2a_button_linkedin"></a>
<a class="a2a_button_pinterest"></a>';
  $export['addtoany_additional_html'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_additional_html_placement';
  $strongarm->value = 'before';
  $export['addtoany_additional_html_placement'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_additional_js';
  $strongarm->value = 'a2a_config.prioritize = ["google_plus", "reddit", "email", "delicious", "stumbleupon", "tumblr", "wordpress"];
a2a_config.exclude_services = ["facebook", "linkedin", "twitter"];';
  $export['addtoany_additional_js'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_nodetypes';
  $strongarm->value = array(
    'blog_post' => 'blog_post',
    'ally' => 0,
    'page' => 0,
    'webform' => 0,
  );
  $export['addtoany_nodetypes'] = $strongarm;

  return $export;
}
