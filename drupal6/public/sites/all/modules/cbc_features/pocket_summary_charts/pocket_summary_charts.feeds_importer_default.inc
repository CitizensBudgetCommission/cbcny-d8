<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function pocket_summary_charts_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'pocket_summary_chart_data';
  $feeds_importer->config = array(
    'name' => 'Pocket Summary NYC Expenses',
    'description' => 'Data for pocket summary NYC Expenses charts',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'expense',
        'input_format' => '0',
        'update_existing' => '1',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'Value',
            'target' => 'field_expense_value',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Year',
            'target' => 'field_expense_year:start',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Name',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'ID',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'Name',
            'target' => 'taxonomy:features_nyc_expense',
            'unique' => FALSE,
          ),
        ),
        'author' => '1',
        'authorize' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );
  $export['pocket_summary_chart_data'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'pocket_summary_nyc_revenue';
  $feeds_importer->config = array(
    'name' => 'Pocket Summary NYC Revenue',
    'description' => 'Data for pocket summary NYC Revenue charts',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'expense',
        'input_format' => '0',
        'update_existing' => '1',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'Value',
            'target' => 'field_expense_value',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Year',
            'target' => 'field_expense_year:start',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Name',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'ID',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'Name',
            'target' => 'taxonomy:9',
            'unique' => FALSE,
          ),
        ),
        'author' => '1',
        'authorize' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );
  $export['pocket_summary_nyc_revenue'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'pocket_summary_nys_expense';
  $feeds_importer->config = array(
    'name' => 'Pocket Summary NYS Expense',
    'description' => 'Data for pocket summary NYS Expense charts',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'expense',
        'input_format' => '0',
        'update_existing' => '1',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'Value',
            'target' => 'field_expense_value',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Year',
            'target' => 'field_expense_year:start',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Name',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'ID',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'Name',
            'target' => 'taxonomy:10',
            'unique' => FALSE,
          ),
        ),
        'author' => '1',
        'authorize' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );
  $export['pocket_summary_nys_expense'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'pocket_summary_nys_revenue';
  $feeds_importer->config = array(
    'name' => 'Pocket Summary NYS Revenue',
    'description' => 'Data for pocket summary NYS Revenue charts',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'expense',
        'input_format' => '0',
        'update_existing' => '1',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'Value',
            'target' => 'field_expense_value',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Year',
            'target' => 'field_expense_year:start',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Name',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'ID',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'Name',
            'target' => 'taxonomy:11',
            'unique' => FALSE,
          ),
        ),
        'author' => '1',
        'authorize' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );
  $export['pocket_summary_nys_revenue'] = $feeds_importer;

  return $export;
}
