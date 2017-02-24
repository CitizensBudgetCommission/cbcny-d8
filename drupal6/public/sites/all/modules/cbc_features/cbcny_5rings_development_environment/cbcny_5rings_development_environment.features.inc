<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cbcny_5rings_development_environment_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}
