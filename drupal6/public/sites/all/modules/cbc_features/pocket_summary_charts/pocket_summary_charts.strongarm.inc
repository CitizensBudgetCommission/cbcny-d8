<?php

/**
 * Implementation of hook_strongarm().
 */
function pocket_summary_charts_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_expense';
  $strongarm->value = '0';
  $export['ant_expense'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_expense';
  $strongarm->value = '';
  $export['ant_pattern_expense'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_pocketsum_sponsor';
  $strongarm->value = '';
  $export['ant_pattern_pocketsum_sponsor'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_expense';
  $strongarm->value = 0;
  $export['ant_php_expense'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_pocketsum_sponsor';
  $strongarm->value = 0;
  $export['ant_php_pocketsum_sponsor'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pocketsum_sponsor';
  $strongarm->value = '0';
  $export['ant_pocketsum_sponsor'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_expense';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '0',
    'author' => '-1',
    'options' => '1',
    'menu' => '-2',
    'taxonomy' => '-3',
    'path' => '3',
    'print' => '2',
  );
  $export['content_extra_weights_expense'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_pocketsum_sponsor';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '0',
    'author' => '-1',
    'options' => '1',
    'menu' => '-2',
    'path' => '2',
    'print' => '3',
  );
  $export['content_extra_weights_pocketsum_sponsor'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumbs_adjust_module_weights';
  $strongarm->value = 0;
  $export['custom_breadcrumbs_adjust_module_weights'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumbs_append_bid_class';
  $strongarm->value = 0;
  $export['custom_breadcrumbs_append_bid_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumbs_even_odd_class';
  $strongarm->value = 0;
  $export['custom_breadcrumbs_even_odd_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumbs_exclude_list';
  $strongarm->value = 'admin/user/user,user';
  $export['custom_breadcrumbs_exclude_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumbs_force_active_trail';
  $strongarm->value = 0;
  $export['custom_breadcrumbs_force_active_trail'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumbs_home_id';
  $strongarm->value = 0;
  $export['custom_breadcrumbs_home_id'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumbs_menu_list';
  $strongarm->value = array(
    'primary-links' => 'primary-links',
  );
  $export['custom_breadcrumbs_menu_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumbs_none_span';
  $strongarm->value = 0;
  $export['custom_breadcrumbs_none_span'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumbs_parts_class';
  $strongarm->value = 0;
  $export['custom_breadcrumbs_parts_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumbs_paths_allow_wildcards';
  $strongarm->value = 1;
  $export['custom_breadcrumbs_paths_allow_wildcards'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumbs_set_global_home_breadcrumb';
  $strongarm->value = 0;
  $export['custom_breadcrumbs_set_global_home_breadcrumb'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumbs_set_menu_breadcrumb';
  $strongarm->value = 1;
  $export['custom_breadcrumbs_set_menu_breadcrumb'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumbs_sort';
  $strongarm->value = array(
    'direction' => array(
      'name' => 'asc',
      'breadcrumb_type' => 'asc',
      'language' => 'asc',
    ),
    'column' => 'name',
  );
  $export['custom_breadcrumbs_sort'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumbs_type_class';
  $strongarm->value = 0;
  $export['custom_breadcrumbs_type_class'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumbs_use_exclude_list';
  $strongarm->value = 0;
  $export['custom_breadcrumbs_use_exclude_list'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumbs_use_php_in_titles';
  $strongarm->value = 0;
  $export['custom_breadcrumbs_use_php_in_titles'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_breadcrumb_home';
  $strongarm->value = '';
  $export['custom_breadcrumb_home'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'default_feeds_tamper';
  $strongarm->value = array(
    'pocket_summary_nyc_revenue-year-pad_a_string' => FALSE,
    'pocket_summary_nyc_revenue-year-string_to_unix_timestamp' => FALSE,
    'pocket_summary_nys_expense-year-pad_a_string' => FALSE,
    'pocket_summary_nys_expense-year-string_to_unix_timestamp' => FALSE,
    'pocket_summary_nys_revenue-year-pad_a_string' => FALSE,
    'pocket_summary_nys_revenue-year-string_to_unix_timestamp' => FALSE,
    'pocket_summary_chart_data-year-pad_a_string' => FALSE,
    'pocket_summary_chart_data-year-string_to_unix_timestamp' => FALSE,
  );
  $export['default_feeds_tamper'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hs_config_taxonomy-';
  $strongarm->value = array(
    'config_id' => 'taxonomy-',
    'save_lineage' => '0',
    'enforce_deepest' => '0',
    'entity_count' => '0',
    'require_entity' => '0',
    'level_labels' => array(
      'status' => 0,
      'labels' => array(
        0 => '',
      ),
    ),
    'resizable' => '0',
    'dropbox' => array(
      'status' => 1,
      'title' => 'Committees',
      'limit' => '0',
      'reset_hs' => '1',
    ),
    'editability' => array(
      'status' => 0,
      'item_types' => array(
        0 => '',
      ),
      'allowed_levels' => array(
        0 => 1,
      ),
      'allow_new_levels' => 0,
      'max_levels' => '0',
    ),
  );
  $export['hs_config_taxonomy-'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hs_config_taxonomy-10';
  $strongarm->value = array(
    'config_id' => 'taxonomy-10',
    'save_lineage' => '0',
    'enforce_deepest' => '0',
    'entity_count' => '0',
    'require_entity' => '0',
    'resizable' => '1',
    'level_labels' => array(
      'status' => 0,
    ),
    'dropbox' => array(
      'status' => 0,
      'title' => 'All selections',
      'limit' => '0',
      'reset_hs' => '1',
    ),
    'editability' => array(
      'status' => 1,
      'allow_new_levels' => 1,
      'max_levels' => '0',
    ),
  );
  $export['hs_config_taxonomy-10'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hs_config_taxonomy-11';
  $strongarm->value = array(
    'config_id' => 'taxonomy-11',
    'save_lineage' => '0',
    'enforce_deepest' => '0',
    'entity_count' => '0',
    'require_entity' => '0',
    'resizable' => '1',
    'level_labels' => array(
      'status' => 0,
    ),
    'dropbox' => array(
      'status' => 0,
      'title' => 'All selections',
      'limit' => '0',
      'reset_hs' => '1',
    ),
    'editability' => array(
      'status' => 1,
      'allow_new_levels' => 1,
      'max_levels' => '0',
    ),
  );
  $export['hs_config_taxonomy-11'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hs_config_taxonomy-12';
  $strongarm->value = array(
    'config_id' => 'taxonomy-12',
    'save_lineage' => '0',
    'enforce_deepest' => '0',
    'entity_count' => '0',
    'require_entity' => '0',
    'resizable' => '1',
    'level_labels' => array(
      'status' => 0,
    ),
    'dropbox' => array(
      'status' => 0,
      'title' => 'All selections',
      'limit' => '0',
      'reset_hs' => '1',
    ),
    'editability' => array(
      'status' => 1,
      'allow_new_levels' => 1,
      'max_levels' => '0',
    ),
  );
  $export['hs_config_taxonomy-12'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hs_config_taxonomy-8';
  $strongarm->value = array(
    'config_id' => 'taxonomy-8',
    'save_lineage' => '0',
    'enforce_deepest' => '0',
    'entity_count' => '0',
    'require_entity' => '0',
    'resizable' => '0',
    'level_labels' => array(
      'status' => 0,
      'labels' => array(
        0 => '',
        1 => '',
      ),
    ),
    'dropbox' => array(
      'status' => 1,
      'title' => 'All selections',
      'limit' => '0',
      'reset_hs' => '1',
    ),
    'editability' => array(
      'status' => 1,
      'item_types' => array(
        0 => '',
        1 => '',
      ),
      'allowed_levels' => array(
        0 => 1,
        1 => 1,
      ),
      'allow_new_levels' => 1,
      'max_levels' => '0',
    ),
  );
  $export['hs_config_taxonomy-8'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hs_config_taxonomy-views-pocket_summary_chart-default-term_node_tid_depth';
  $strongarm->value = array(
    'config_id' => 'taxonomy-views-pocket_summary_chart-default-term_node_tid_depth',
    'save_lineage' => '0',
    'enforce_deepest' => '1',
    'entity_count' => '0',
    'require_entity' => '0',
    'resizable' => '1',
    'level_labels' => array(
      'status' => 0,
      'labels' => array(
        0 => '',
        1 => '',
        2 => '',
      ),
    ),
    'dropbox' => array(
      'status' => 1,
      'title' => 'All selections',
      'limit' => '0',
      'reset_hs' => '0',
    ),
  );
  $export['hs_config_taxonomy-views-pocket_summary_chart-default-term_node_tid_depth'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hs_config_taxonomy-views-pocket_summary_chart-page_1-term_node_tid_depth';
  $strongarm->value = array(
    'config_id' => 'taxonomy-views-pocket_summary_chart-page_1-term_node_tid_depth',
    'save_lineage' => '0',
    'enforce_deepest' => '0',
    'entity_count' => '0',
    'require_entity' => '0',
    'resizable' => '1',
    'level_labels' => array(
      'status' => 0,
      'labels' => array(
        0 => '',
        1 => '',
        2 => '',
      ),
    ),
    'dropbox' => array(
      'status' => 0,
      'title' => 'All selections',
      'limit' => '0',
      'reset_hs' => '1',
    ),
  );
  $export['hs_config_taxonomy-views-pocket_summary_chart-page_1-term_node_tid_depth'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hs_config_taxonomy-views-pocket_summary_chart-page_2-term_node_tid_depth';
  $strongarm->value = array(
    'config_id' => 'taxonomy-views-pocket_summary_chart-page_2-term_node_tid_depth',
    'save_lineage' => '0',
    'enforce_deepest' => '0',
    'entity_count' => '1',
    'require_entity' => '1',
    'resizable' => '0',
    'level_labels' => array(
      'status' => 0,
      'labels' => array(
        0 => '',
        1 => '',
        2 => '',
      ),
    ),
    'dropbox' => array(
      'status' => 1,
      'title' => 'All selections',
      'limit' => '0',
      'reset_hs' => '0',
    ),
  );
  $export['hs_config_taxonomy-views-pocket_summary_chart-page_2-term_node_tid_depth'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nat_config';
  $strongarm->value = array(
    'types' => array(
      'webform' => array(),
      'blog' => array(),
      'committee' => array(
        7 => '7',
      ),
      'date' => array(),
      'event' => array(),
      'event_trustee' => array(),
      'fastfact' => array(),
      'inthenews' => array(),
      'letter' => array(),
      'oped' => array(),
      'page' => array(),
      'pocketsummary' => array(),
      'presentation' => array(),
      'presscitation' => array(),
      'pressrelease' => array(),
      'profile' => array(),
      'quote' => array(),
      'report' => array(),
      'reportsummary' => array(),
      'statement' => array(),
      'testimony' => array(),
      'video' => array(),
      'workinprogress' => array(),
    ),
    'body' => array(),
    'delete' => array(
      'committee' => 1,
    ),
    'related' => array(),
    'node_links' => array(
      'committee' => 1,
    ),
  );
  $export['nat_config'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_expense';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_expense'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_pocketsum_sponsor';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_pocketsum_sponsor'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_expense_pattern';
  $strongarm->value = '[node-url]';
  $export['pathauto_node_expense_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_pocketsum_sponsor_pattern';
  $strongarm->value = '';
  $export['pathauto_node_pocketsum_sponsor_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_10_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_10_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_11_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_11_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_12_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_12_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_8_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_8_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_block_not_node_front';
  $strongarm->value = 0;
  $export['service_links_block_not_node_front'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_block_not_node_style';
  $strongarm->value = '2';
  $export['service_links_block_not_node_style'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_block_style';
  $strongarm->value = '2';
  $export['service_links_block_style'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_page_match_for_node';
  $strongarm->value = 'summary
summary/*/navigator';
  $export['service_links_page_match_for_node'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_short_links_type';
  $strongarm->value = '1';
  $export['service_links_short_links_type'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_visibility_for_node';
  $strongarm->value = '0';
  $export['service_links_visibility_for_node'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_hierarchical_select_';
  $strongarm->value = 0;
  $export['taxonomy_hierarchical_select_'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_hierarchical_select_10';
  $strongarm->value = 1;
  $export['taxonomy_hierarchical_select_10'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_hierarchical_select_11';
  $strongarm->value = 1;
  $export['taxonomy_hierarchical_select_11'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_hierarchical_select_12';
  $strongarm->value = 1;
  $export['taxonomy_hierarchical_select_12'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'taxonomy_hierarchical_select_8';
  $strongarm->value = 1;
  $export['taxonomy_hierarchical_select_8'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_expense';
  $strongarm->value = '0';
  $export['upload_expense'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_pocketsum_sponsor';
  $strongarm->value = '0';
  $export['upload_pocketsum_sponsor'] = $strongarm;

  return $export;
}
