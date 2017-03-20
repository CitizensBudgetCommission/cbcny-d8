<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function pocket_summary_charts_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
  elseif ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => 2);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function pocket_summary_charts_imagecache_default_presets() {
  $items = array(
    'pocketsum_sponsor_logo' => array(
      'presetname' => 'pocketsum_sponsor_logo',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '',
            'height' => '75',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function pocket_summary_charts_node_info() {
  $items = array(
    'expense' => array(
      'name' => t('Expense line item'),
      'module' => 'features',
      'description' => t('A line item for Pocket Summary charts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'pocketsum_sponsor' => array(
      'name' => t('Pocket Summary Sponsor'),
      'module' => 'features',
      'description' => t('A sponsor for the pocket summary navigator'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function pocket_summary_charts_views_api() {
  return array(
    'api' => '3.0',
  );
}
