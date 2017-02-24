<?php

/**
 * Implementation of hook_views_default_views().
 */
function pocket_summary_charts_views_default_views() {
  $views = array();

  // Exported view: pocket_summary_chart
  $view = new view;
  $view->name = 'pocket_summary_chart';
  $view->description = 'A chart describing pocket summary information';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Budget Navigator';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Empty text: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['label'] = '';
  $handler->display->display_options['empty']['text']['empty'] = FALSE;
  $handler->display->display_options['empty']['text']['content'] = 'No expense categories selected.';
  /* Field: Taxonomy: Term */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Expense';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 0;
  /* Field: Content: Year (field_expense_year) */
  $handler->display->display_options['fields']['field_expense_year_value']['id'] = 'field_expense_year_value';
  $handler->display->display_options['fields']['field_expense_year_value']['table'] = 'node_data_field_expense_year';
  $handler->display->display_options['fields']['field_expense_year_value']['field'] = 'field_expense_year_value';
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_expense_year_value']['multiple']['group'] = '';
  /* Field: Content: Value (field_expense_value) */
  $handler->display->display_options['fields']['field_expense_value_value']['id'] = 'field_expense_value_value';
  $handler->display->display_options['fields']['field_expense_value_value']['table'] = 'node_data_field_expense_value';
  $handler->display->display_options['fields']['field_expense_value_value']['field'] = 'field_expense_value_value';
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['link_to_node'] = 1;
  $handler->display->display_options['fields']['field_expense_value_value']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_expense_value_value']['format'] = 'us_0';
  /* Sort criterion: Content: Year (field_expense_year) */
  $handler->display->display_options['sorts']['field_expense_year_value']['id'] = 'field_expense_year_value';
  $handler->display->display_options['sorts']['field_expense_year_value']['table'] = 'node_data_field_expense_year';
  $handler->display->display_options['sorts']['field_expense_year_value']['field'] = 'field_expense_year_value';
  /* Sort criterion: Taxonomy: Term ID */
  $handler->display->display_options['sorts']['tid']['id'] = 'tid';
  $handler->display->display_options['sorts']['tid']['table'] = 'term_data';
  $handler->display->display_options['sorts']['tid']['field'] = 'tid';
  /* Argument: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['must_not_be'] = 0;
  /* Argument: Global: Null */
  $handler->display->display_options['arguments']['null_1']['id'] = 'null_1';
  $handler->display->display_options['arguments']['null_1']['table'] = 'views';
  $handler->display->display_options['arguments']['null_1']['field'] = 'null';
  $handler->display->display_options['arguments']['null_1']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['null_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null_1']['must_not_be'] = 0;
  /* Argument: Taxonomy: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'term_node';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['term_page'] = 0;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['node'] = 0;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['limit'] = 0;
  $handler->display->display_options['arguments']['tid']['default_argument_options']['vids'] = array(
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    6 => 0,
    4 => 0,
  );
  $handler->display->display_options['arguments']['tid']['validate_type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vids'] = array(
    8 => 8,
    9 => 9,
    10 => 10,
    11 => 11,
    6 => 0,
    4 => 0,
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'tids';
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = 0;
  $handler->display->display_options['arguments']['tid']['validate_fail'] = 'empty';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['tid']['add_table'] = 0;
  $handler->display->display_options['arguments']['tid']['require_value'] = 1;
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['arguments']['tid']['set_breadcrumb'] = 0;
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'expense' => 'expense',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;

  /* Display: NYC Expense */
  $handler = $view->new_display('page', 'NYC Expense', 'page_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Value (field_expense_value) */
  $handler->display->display_options['fields']['field_expense_value_value']['id'] = 'field_expense_value_value';
  $handler->display->display_options['fields']['field_expense_value_value']['table'] = 'node_data_field_expense_value';
  $handler->display->display_options['fields']['field_expense_value_value']['field'] = 'field_expense_value_value';
  $handler->display->display_options['fields']['field_expense_value_value']['label'] = 'Millions of dollars';
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['link_to_node'] = 1;
  $handler->display->display_options['fields']['field_expense_value_value']['label_type'] = 'custom';
  /* Field: Taxonomy: Term */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Expense';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 0;
  /* Field: Content: Year (field_expense_year) */
  $handler->display->display_options['fields']['field_expense_year_value']['id'] = 'field_expense_year_value';
  $handler->display->display_options['fields']['field_expense_year_value']['table'] = 'node_data_field_expense_year';
  $handler->display->display_options['fields']['field_expense_year_value']['field'] = 'field_expense_year_value';
  $handler->display->display_options['fields']['field_expense_year_value']['label'] = 'Year';
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['multiple']['group'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Year (field_expense_year) */
  $handler->display->display_options['sorts']['field_expense_year_value']['id'] = 'field_expense_year_value';
  $handler->display->display_options['sorts']['field_expense_year_value']['table'] = 'node_data_field_expense_year';
  $handler->display->display_options['sorts']['field_expense_year_value']['field'] = 'field_expense_year_value';
  /* Sort criterion: Taxonomy: Term ID */
  $handler->display->display_options['sorts']['tid']['id'] = 'tid';
  $handler->display->display_options['sorts']['tid']['table'] = 'term_data';
  $handler->display->display_options['sorts']['tid']['field'] = 'tid';
  $handler->display->display_options['path'] = 'summary/%/%/navigator/%';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'pocket-summary.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy: Term */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Expense';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 0;
  /* Field: Content: Year (field_expense_year) */
  $handler->display->display_options['fields']['field_expense_year_value']['id'] = 'field_expense_year_value';
  $handler->display->display_options['fields']['field_expense_year_value']['table'] = 'node_data_field_expense_year';
  $handler->display->display_options['fields']['field_expense_year_value']['field'] = 'field_expense_year_value';
  $handler->display->display_options['fields']['field_expense_year_value']['label'] = 'Year';
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['multiple']['group'] = '';
  /* Field: Content: Value (field_expense_value) */
  $handler->display->display_options['fields']['field_expense_value_value']['id'] = 'field_expense_value_value';
  $handler->display->display_options['fields']['field_expense_value_value']['table'] = 'node_data_field_expense_value';
  $handler->display->display_options['fields']['field_expense_value_value']['field'] = 'field_expense_value_value';
  $handler->display->display_options['fields']['field_expense_value_value']['label'] = 'Value';
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['link_to_node'] = 1;
  $handler->display->display_options['fields']['field_expense_value_value']['format'] = 'us_0';
  $handler->display->display_options['path'] = 'summary/%/%/navigator/%/xls';

  $views[$view->name] = $view;

  // Exported view: pocket_summary_piechart
  $view = new view;
  $view->name = 'pocket_summary_piechart';
  $view->description = 'Piechart for the pocket summary sidebar';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['exposed_block'] = TRUE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['text']['id'] = 'area';
  $handler->display->display_options['header']['text']['table'] = 'views';
  $handler->display->display_options['header']['text']['field'] = 'area';
  $handler->display->display_options['header']['text']['label'] = '';
  $handler->display->display_options['header']['text']['empty'] = TRUE;
  $handler->display->display_options['header']['text']['content'] = 'The CBC Budget Navigator lets you explore the New York budgets on your own terms. Compare figures from past years, spot trends and relationships, and help us keep a close eye on New York\'s finances!

Select your categories and click Add to create a list of categories to compare. When you\'re done, click Apply to update the chart.';
  /* Empty text: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['label'] = '';
  $handler->display->display_options['empty']['text']['empty'] = FALSE;
  $handler->display->display_options['empty']['text']['content'] = 'Total Budget figures for this year are not released yet.';
  /* Field: Content: Value (field_expense_value) */
  $handler->display->display_options['fields']['field_expense_value_value']['id'] = 'field_expense_value_value';
  $handler->display->display_options['fields']['field_expense_value_value']['table'] = 'node_data_field_expense_value';
  $handler->display->display_options['fields']['field_expense_value_value']['field'] = 'field_expense_value_value';
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_expense_value_value']['link_to_node'] = 1;
  $handler->display->display_options['fields']['field_expense_value_value']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_expense_value_value']['format'] = 'us_0';
  /* Field: Taxonomy: Term */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Expense';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 0;
  /* Field: Content: Year (field_expense_year) */
  $handler->display->display_options['fields']['field_expense_year_value']['id'] = 'field_expense_year_value';
  $handler->display->display_options['fields']['field_expense_year_value']['table'] = 'node_data_field_expense_year';
  $handler->display->display_options['fields']['field_expense_year_value']['field'] = 'field_expense_year_value';
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_expense_year_value']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_expense_year_value']['multiple']['group'] = '';
  /* Sort criterion: Taxonomy: Term ID */
  $handler->display->display_options['sorts']['tid']['id'] = 'tid';
  $handler->display->display_options['sorts']['tid']['table'] = 'term_data';
  $handler->display->display_options['sorts']['tid']['field'] = 'tid';
  /* Argument: Taxonomy: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'term_node';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['code'] = 'if (arg(0) == \'summary\' && arg(3) == \'navigator\' && arg(4) != \'\') {

// Set Total Budget TIDs
$nycexp = \'727\';
$nycrev = \'728\';
$nysexp = \'729\';
$nysrev = \'730\';

$pos = strpos(arg(4),$nycexp);
$pos = strpos(arg(4),$nycrev);
$pos = strpos(arg(4),$nysexp);
$pos = strpos(arg(4),$nysrev);

if ($pos !== \'FALSE\') {

if (arg(1) . "/" . arg(2) == \'nyc/expense\') return arg(4) . "+" . $nycexp;
elseif (arg(1) . "/" . arg(2) == \'nyc/revenue\') return arg(4) . "+" . $nycrev;
elseif (arg(1) . "/" . arg(2) == \'nys/expense\') return arg(4) . "+" . $nysexp;
elseif (arg(1) . "/" . arg(2) == \'nys/revenue\') return arg(4) . "+" . $nysrev;
}
}';
  $handler->display->display_options['arguments']['tid']['validate_fail'] = 'empty';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['tid']['add_table'] = 0;
  $handler->display->display_options['arguments']['tid']['require_value'] = 1;
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['arguments']['tid']['set_breadcrumb'] = 0;
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'expense' => 'expense',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['value']['min'] = '2015-01-01 00:00:00';
  $handler->display->display_options['filters']['date_filter']['value']['max'] = '2015-01-01 00:00:00';
  $handler->display->display_options['filters']['date_filter']['value']['value'] = '2014-01-01 00:00:00';
  $handler->display->display_options['filters']['date_filter']['group'] = '0';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date: Date (node)';
  $handler->display->display_options['filters']['date_filter']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['optional'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['remember'] = FALSE;
  $handler->display->display_options['filters']['date_filter']['expose']['single'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['allow_null'] = 1;
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node_data_field_expense_year.field_expense_year_value' => 'node_data_field_expense_year.field_expense_year_value',
  );
  $handler->display->display_options['filters']['date_filter']['date_method'] = 'OR';
  $handler->display->display_options['filters']['date_filter']['granularity'] = 'year';
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['date_filter']['default_date'] = '';
  $handler->display->display_options['filters']['date_filter']['default_to_date'] = '';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-6:+2';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Taxonomy: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'term_node';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['code'] = 'if (arg(0) == \'summary\' && arg(3) == \'navigator\' && arg(4) != \'\') {

// Set Total Budget TIDs
$nycexp = \'306\';
$nycrev = \'319\';
$nysexp = \'344\';
$nysrev = \'347\';

if (arg(1) . "/" . arg(2) == \'nyc/expense\') return arg(4) . "+" . $nycexp;
elseif (arg(1) . "/" . arg(2) == \'nyc/revenue\') return arg(4) . "+" . $nycrev;
elseif (arg(1) . "/" . arg(2) == \'nys/expense\') return arg(4) . "+" . $nysexp;
elseif (arg(1) . "/" . arg(2) == \'nys/revenue\') return arg(4) . "+" . $nysrev;
}';
  $handler->display->display_options['arguments']['tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['tid']['validate_fail'] = 'empty';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['tid']['add_table'] = 0;
  $handler->display->display_options['arguments']['tid']['require_value'] = 1;
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['arguments']['tid']['set_breadcrumb'] = 0;
  $handler->display->display_options['arguments']['tid']['use_synonym_for_summary_links'] = 0;

  $views[$view->name] = $view;

  // Exported view: pocket_summary_sponsors
  $view = new view;
  $view->name = 'pocket_summary_sponsors';
  $view->description = 'Sponsors carousel for the pocket summary front page';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Logo Image (field_sponsor_logo) */
  $handler->display->display_options['fields']['field_sponsor_logo_fid']['id'] = 'field_sponsor_logo_fid';
  $handler->display->display_options['fields']['field_sponsor_logo_fid']['table'] = 'node_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo_fid']['field'] = 'field_sponsor_logo_fid';
  $handler->display->display_options['fields']['field_sponsor_logo_fid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_logo_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_sponsor_logo_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_sponsor_logo_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_sponsor_logo_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_sponsor_logo_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_sponsor_logo_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_sponsor_logo_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_sponsor_logo_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_sponsor_logo_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_sponsor_logo_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_sponsor_logo_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_sponsor_logo_fid']['format'] = 'pocketsum_sponsor_logo_default';
  /* Field: Content: Sponsor link (field_sponsor_link) */
  $handler->display->display_options['fields']['field_sponsor_link_url']['id'] = 'field_sponsor_link_url';
  $handler->display->display_options['fields']['field_sponsor_link_url']['table'] = 'node_data_field_sponsor_link';
  $handler->display->display_options['fields']['field_sponsor_link_url']['field'] = 'field_sponsor_link_url';
  $handler->display->display_options['fields']['field_sponsor_link_url']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_sponsor_link_url']['alter']['text'] = '[field_sponsor_logo_fid]';
  $handler->display->display_options['fields']['field_sponsor_link_url']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_sponsor_link_url']['alter']['path'] = '[field_sponsor_link_url]';
  $handler->display->display_options['fields']['field_sponsor_link_url']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_sponsor_link_url']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['field_sponsor_link_url']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['field_sponsor_link_url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_sponsor_link_url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_sponsor_link_url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_sponsor_link_url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_sponsor_link_url']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_sponsor_link_url']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_sponsor_link_url']['label_type'] = 'none';
  /* Filter: Node: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'pocketsum_sponsor' => 'pocketsum_sponsor',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter: Node: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = '0';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';

  $views[$view->name] = $view;

  return $views;
}
