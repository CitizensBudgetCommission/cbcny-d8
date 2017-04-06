<?php

/**
 * Implementation of hook_feeds_tamper_default().
 */
function pocket_summary_charts_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'pocket_summary_chart_data-year-pad_a_string';
  $feeds_tamper->importer = 'pocket_summary_chart_data';
  $feeds_tamper->source = 'Year';
  $feeds_tamper->plugin_id = 'str_pad';
  $feeds_tamper->settings = array(
    'pad_length' => 10,
    'pad_string' => '-01-01',
    'pad_type' => '1',
    'real_pad_string' => '-01-01',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Pad a string';
  $export['pocket_summary_chart_data-year-pad_a_string'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'pocket_summary_chart_data-year-string_to_unix_timestamp';
  $feeds_tamper->importer = 'pocket_summary_chart_data';
  $feeds_tamper->source = 'Year';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = FALSE;
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['pocket_summary_chart_data-year-string_to_unix_timestamp'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'pocket_summary_nyc_revenue-year-pad_a_string';
  $feeds_tamper->importer = 'pocket_summary_nyc_revenue';
  $feeds_tamper->source = 'Year';
  $feeds_tamper->plugin_id = 'str_pad';
  $feeds_tamper->settings = array(
    'pad_length' => 10,
    'pad_string' => '-01-01',
    'pad_type' => '1',
    'real_pad_string' => '-01-01',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Pad a string';
  $export['pocket_summary_nyc_revenue-year-pad_a_string'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'pocket_summary_nyc_revenue-year-string_to_unix_timestamp';
  $feeds_tamper->importer = 'pocket_summary_nyc_revenue';
  $feeds_tamper->source = 'Year';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = FALSE;
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['pocket_summary_nyc_revenue-year-string_to_unix_timestamp'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'pocket_summary_nys_expense-year-pad_a_string';
  $feeds_tamper->importer = 'pocket_summary_nys_expense';
  $feeds_tamper->source = 'Year';
  $feeds_tamper->plugin_id = 'str_pad';
  $feeds_tamper->settings = array(
    'pad_length' => 10,
    'pad_string' => '-01-01',
    'pad_type' => '1',
    'real_pad_string' => '-01-01',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Pad a string';
  $export['pocket_summary_nys_expense-year-pad_a_string'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'pocket_summary_nys_expense-year-string_to_unix_timestamp';
  $feeds_tamper->importer = 'pocket_summary_nys_expense';
  $feeds_tamper->source = 'Year';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = FALSE;
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['pocket_summary_nys_expense-year-string_to_unix_timestamp'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'pocket_summary_nys_revenue-year-pad_a_string';
  $feeds_tamper->importer = 'pocket_summary_nys_revenue';
  $feeds_tamper->source = 'Year';
  $feeds_tamper->plugin_id = 'str_pad';
  $feeds_tamper->settings = array(
    'pad_length' => 10,
    'pad_string' => '-01-01',
    'pad_type' => '1',
    'real_pad_string' => '-01-01',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Pad a string';
  $export['pocket_summary_nys_revenue-year-pad_a_string'] = $feeds_tamper;

  $feeds_tamper = new stdClass;
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'pocket_summary_nys_revenue-year-string_to_unix_timestamp';
  $feeds_tamper->importer = 'pocket_summary_nys_revenue';
  $feeds_tamper->source = 'Year';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = FALSE;
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['pocket_summary_nys_revenue-year-string_to_unix_timestamp'] = $feeds_tamper;

  return $export;
}
