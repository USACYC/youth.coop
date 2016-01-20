<?php
/**
 * @file
 * youth_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function youth_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
