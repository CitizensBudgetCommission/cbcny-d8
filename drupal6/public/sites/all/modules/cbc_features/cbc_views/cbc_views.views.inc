<?php

/**
 * @file
 * Views integration of CBC Views module.
 */

function cbc_views_views_default_views_alter(&$views) {
  if (isset($views['calendar'])) {
    $view = new view;
    $view->name = 'calendar';
    $view->description = 'A multi-dimensional calendar view with back/next navigation.';
    $view->tag = 'Calendar';
    $view->base_table = 'node';
    $view->human_name = '';
    $view->core = 0;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Defaults */
    $handler = $view->new_display('default', 'Defaults', 'default');
    $handler->display->display_options['title'] = 'Calendar';
    $handler->display->display_options['use_ajax'] = TRUE;
    $handler->display->display_options['items_per_page'] = 0;
    $handler->display->display_options['access']['type'] = 'none';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['style_plugin'] = 'calendar_style';
    /* Field: Node: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['link_to_node'] = 1;
    /* Field: Content: time (field_time) */
    $handler->display->display_options['fields']['field_time_value']['id'] = 'field_time_value';
    $handler->display->display_options['fields']['field_time_value']['table'] = 'node_data_field_time';
    $handler->display->display_options['fields']['field_time_value']['field'] = 'field_time_value';
    $handler->display->display_options['fields']['field_time_value']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['field_time_value']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['field_time_value']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['field_time_value']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['field_time_value']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['field_time_value']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['field_time_value']['alter']['html'] = 0;
    $handler->display->display_options['fields']['field_time_value']['link_to_node'] = 0;
    $handler->display->display_options['fields']['field_time_value']['label_type'] = 'none';
    $handler->display->display_options['fields']['field_time_value']['fromto']['fromto'] = 'value';
    /* Field: Node: Type */
    $handler->display->display_options['fields']['type']['id'] = 'type';
    $handler->display->display_options['fields']['type']['table'] = 'node';
    $handler->display->display_options['fields']['type']['field'] = 'type';
    $handler->display->display_options['fields']['type']['exclude'] = TRUE;
    $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['type']['alter']['html'] = 0;
    $handler->display->display_options['fields']['type']['link_to_node'] = 0;
    /* Sort criterion: Content: time (field_time) */
    $handler->display->display_options['sorts']['field_time_value']['id'] = 'field_time_value';
    $handler->display->display_options['sorts']['field_time_value']['table'] = 'node_data_field_time';
    $handler->display->display_options['sorts']['field_time_value']['field'] = 'field_time_value';
    /* Argument: Date: Date (node) */
    $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
    $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
    $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
    $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
    $handler->display->display_options['arguments']['date_argument']['style_plugin'] = 'default_summary';
    $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
    $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
      'node_data_field_time.field_time_value' => 'node_data_field_time.field_time_value',
    );
    $handler->display->display_options['arguments']['date_argument']['year_range'] = '-3:+3';
    $handler->display->display_options['arguments']['date_argument']['date_method'] = 'OR';
    $handler->display->display_options['arguments']['date_argument']['granularity'] = 'month';
    /* Filter: Node: Type */
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'node';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
      'event' => 'event',
      'event_trustee' => 'event_trustee',
    );
    $handler->display->display_options['filters']['type']['group'] = '0';
    $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;

    /* Display: Calendar page */
    $handler = $view->new_display('calendar', 'Calendar page', 'calendar_1');
    $handler->display->display_options['items_per_page'] = 0;
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['style_plugin'] = 'calendar_nav';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['path'] = 'calendar';
    $handler->display->display_options['calendar_colors'] = array(
      'blog' => '#ffffff',
      'committee' => '#ffffff',
      'date' => '#ffffff',
      'event' => '#004e6b',
      'fastfact' => '#ffffff',
      'inthenews' => '#ffffff',
      'letter' => '#ffffff',
      'oped' => '#ffffff',
      'page' => '#ffffff',
      'pocketsummary' => '#ffffff',
      'presentation' => '#ffffff',
      'presscitation' => '#ffffff',
      'pressrelease' => '#ffffff',
      'quote' => '#ffffff',
      'report' => '#ffffff',
      'reportsummary' => '#ffffff',
      'statement' => '#ffffff',
      'testimony' => '#ffffff',
      'event_trustee' => '#679146',
      'video' => '#ffffff',
      'webform' => '#ffffff',
      'workinprogress' => '#ffffff',
    );

    /* Display: Calendar block */
    $handler = $view->new_display('calendar_block', 'Calendar block', 'calendar_block_1');
    $handler->display->display_options['items_per_page'] = 0;
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['style_plugin'] = 'calendar_nav';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['block_description'] = 'Calendar';

    /* Display: Year view */
    $handler = $view->new_display('calendar_period', 'Year view', 'calendar_period_1');
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'calendar_style';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['attachment_position'] = 'after';
    $handler->display->display_options['inherit_exposed_filters'] = TRUE;
    $handler->display->display_options['displays'] = array(
      'calendar_1' => 'calendar_1',
      'default' => 0,
      'calendar_block_1' => 0,
    );

    /* Display: Month view */
    $handler = $view->new_display('calendar_period', 'Month view', 'calendar_period_2');
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'calendar_style';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['attachment_position'] = 'after';
    $handler->display->display_options['inherit_exposed_filters'] = TRUE;
    $handler->display->display_options['displays'] = array(
      'calendar_1' => 'calendar_1',
      'default' => 0,
      'calendar_block_1' => 0,
    );

    /* Display: Day view */
    $handler = $view->new_display('calendar_period', 'Day view', 'calendar_period_3');
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'calendar_style';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['attachment_position'] = 'after';
    $handler->display->display_options['inherit_exposed_filters'] = TRUE;
    $handler->display->display_options['displays'] = array(
      'calendar_1' => 'calendar_1',
      'default' => 0,
      'calendar_block_1' => 0,
    );

    /* Display: Block view */
    $handler = $view->new_display('calendar_period', 'Block view', 'calendar_period_5');
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'calendar_style';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['attachment_position'] = 'after';
    $handler->display->display_options['inherit_exposed_filters'] = TRUE;
    $handler->display->display_options['displays'] = array(
      'calendar_1' => 0,
      'default' => 0,
      'calendar_block_1' => 'calendar_block_1',
    );

    /* Display: iCal feed */
    $handler = $view->new_display('calendar_ical', 'iCal feed', 'calendar_ical_1');
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['style_plugin'] = 'ical';
    $handler->display->display_options['style_options']['mission_description'] = FALSE;
    $handler->display->display_options['style_options']['summary_field'] = 'node_title';
    $handler->display->display_options['defaults']['filters'] = FALSE;
    /* Filter: Node: Type */
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'node';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
      'event' => 'event',
      'event_trustee' => 'event_trustee',
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
    $handler->display->display_options['path'] = 'calendar/ical';
    $handler->display->display_options['displays'] = array(
      'calendar_1' => 'calendar_1',
      'default' => 0,
      'calendar_block_1' => 'calendar_block_1',
    );

    /* Display: Upcoming */
    $handler = $view->new_display('block', 'Upcoming', 'block_1');
    $handler->display->display_options['defaults']['title'] = FALSE;
    $handler->display->display_options['title'] = 'Upcoming';
    $handler->display->display_options['defaults']['use_more'] = FALSE;
    $handler->display->display_options['use_more'] = TRUE;
    $handler->display->display_options['defaults']['pager'] = FALSE;
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['pager']['options']['items_per_page'] = 5;
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'list';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'fields';
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Node: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['link_to_node'] = 1;
    /* Field: Node: Updated date */
    $handler->display->display_options['fields']['changed']['id'] = 'changed';
    $handler->display->display_options['fields']['changed']['table'] = 'node';
    $handler->display->display_options['fields']['changed']['field'] = 'changed';
    $handler->display->display_options['fields']['changed']['label'] = '';
    /* Field: Content: time (field_time) */
    $handler->display->display_options['fields']['field_time_value']['id'] = 'field_time_value';
    $handler->display->display_options['fields']['field_time_value']['table'] = 'node_data_field_time';
    $handler->display->display_options['fields']['field_time_value']['field'] = 'field_time_value';
    $handler->display->display_options['fields']['field_time_value']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['field_time_value']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['field_time_value']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['field_time_value']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['field_time_value']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['field_time_value']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['field_time_value']['alter']['html'] = 0;
    $handler->display->display_options['fields']['field_time_value']['link_to_node'] = 0;
    $handler->display->display_options['fields']['field_time_value']['label_type'] = 'custom';
    $handler->display->display_options['fields']['field_time_value']['format'] = 'medium';
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    $handler->display->display_options['defaults']['filters'] = FALSE;
    /* Filter: Node: Published */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'node';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = 1;
    $handler->display->display_options['filters']['status']['group'] = '0';
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
    /* Filter: Date: Date (node) */
    $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
    $handler->display->display_options['filters']['date_filter']['table'] = 'node';
    $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
    $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
    $handler->display->display_options['filters']['date_filter']['group'] = '0';
    $handler->display->display_options['filters']['date_filter']['expose']['operator'] = FALSE;
    $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
      'node.changed' => 'node.changed',
    );
    $handler->display->display_options['filters']['date_filter']['date_method'] = 'OR';
    $handler->display->display_options['filters']['date_filter']['granularity'] = 'day';
    $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_select';
    $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
    $handler->display->display_options['filters']['date_filter']['default_to_date'] = '';
    $handler->display->display_options['filters']['date_filter']['year_range'] = '-3:+3';
    /* Filter: Node: Type */
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'node';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
      'event' => 'event',
    );
    $handler->display->display_options['filters']['type']['group'] = '0';
    $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
    $handler->display->display_options['block_description'] = 'Upcoming';

    $views[$view->name] = $view;
  }

  if (isset($views['calendar_date'])) {
    $view = new view;
    $view->name = 'calendar_date';
    $view->description = 'An event calendar for Date';
    $view->tag = 'Calendar';
    $view->base_table = 'node';
    $view->human_name = '';
    $view->core = 0;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Defaults */
    $handler = $view->new_display('default', 'Defaults', 'default');
    $handler->display->display_options['title'] = 'Calendar';
    $handler->display->display_options['items_per_page'] = 0;
    $handler->display->display_options['access']['type'] = 'none';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['style_plugin'] = 'calendar_nav';
    /* Field: Node: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['link_to_node'] = 1;
    /* Field: Broken/missing handler */
    $handler->display->display_options['fields']['field_date']['id'] = 'field_date_value';
    $handler->display->display_options['fields']['field_date']['table'] = 'node_data_field_date';
    $handler->display->display_options['fields']['field_date']['field'] = 'field_date_value';
    $handler->display->display_options['fields']['field_date']['label'] = '';
    /* Sort criterion: Broken/missing handler */
    $handler->display->display_options['sorts']['field_date']['id'] = 'field_date_value';
    $handler->display->display_options['sorts']['field_date']['table'] = 'node_data_field_date';
    $handler->display->display_options['sorts']['field_date']['field'] = 'field_date_value';
    /* Argument: Date: Date (node) */
    $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
    $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
    $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
    $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
    $handler->display->display_options['arguments']['date_argument']['style_plugin'] = 'default_summary';
    $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
    $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
      'node_data_field_date.field_date_value' => 'node_data_field_date.field_date_value',
    );
    $handler->display->display_options['arguments']['date_argument']['year_range'] = '-3:+3';
    $handler->display->display_options['arguments']['date_argument']['date_method'] = 'OR';
    $handler->display->display_options['arguments']['date_argument']['granularity'] = 'month';
    /* Filter: Node: Published */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'node';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = 1;
    $handler->display->display_options['filters']['status']['group'] = '0';
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
    /* Filter: Node: Type */
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'node';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
      'date' => 'date',
    );
    $handler->display->display_options['filters']['type']['group'] = '0';
    $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;

    /* Display: Calendar page */
    $handler = $view->new_display('calendar', 'Calendar page', 'calendar_1');
    $handler->display->display_options['items_per_page'] = 0;
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['style_plugin'] = 'calendar_nav';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['path'] = 'calendar-date';
    $handler->display->display_options['calendar_colors'] = array(
      0 => array(
        0 => array(
          'date' => '#ffffff',
        ),
      ),
    );
    $handler->display->display_options['calendar_date_link'] = 'date';

    /* Display: Calendar block */
    $handler = $view->new_display('calendar_block', 'Calendar block', 'calendar_block_1');
    $handler->display->display_options['items_per_page'] = 0;
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['style_plugin'] = 'calendar_nav';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['block_description'] = 'Calendar';

    /* Display: Year view */
    $handler = $view->new_display('calendar_period', 'Year view', 'calendar_period_1');
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'calendar_style';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['attachment_position'] = 'after';
    $handler->display->display_options['inherit_exposed_filters'] = TRUE;
    $handler->display->display_options['displays'] = array(
      'calendar_1' => 'calendar_1',
      'default' => 0,
      'calendar_block_1' => 0,
    );

    /* Display: Month view */
    $handler = $view->new_display('calendar_period', 'Month view', 'calendar_period_2');
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'calendar_style';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['attachment_position'] = 'after';
    $handler->display->display_options['inherit_exposed_filters'] = TRUE;
    $handler->display->display_options['displays'] = array(
      'calendar_1' => 'calendar_1',
      'default' => 0,
      'calendar_block_1' => 0,
    );

    /* Display: Day view */
    $handler = $view->new_display('calendar_period', 'Day view', 'calendar_period_3');
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'calendar_style';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['attachment_position'] = 'after';
    $handler->display->display_options['inherit_exposed_filters'] = TRUE;
    $handler->display->display_options['displays'] = array(
      'calendar_1' => 'calendar_1',
      'default' => 0,
      'calendar_block_1' => 0,
    );

    /* Display: Block view */
    $handler = $view->new_display('calendar_period', 'Block view', 'calendar_period_5');
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'calendar_style';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['attachment_position'] = 'after';
    $handler->display->display_options['inherit_exposed_filters'] = TRUE;
    $handler->display->display_options['displays'] = array(
      'calendar_1' => 0,
      'default' => 0,
      'calendar_block_1' => 'calendar_block_1',
    );

    /* Display: iCal feed */
    $handler = $view->new_display('calendar_ical', 'iCal feed', 'calendar_ical_1');
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['style_plugin'] = 'ical';
    $handler->display->display_options['style_options']['mission_description'] = FALSE;
    $handler->display->display_options['style_options']['summary_field'] = 'node_title';
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    $handler->display->display_options['defaults']['filters'] = FALSE;
    /* Filter: Node: Published */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'node';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = 1;
    $handler->display->display_options['filters']['status']['group'] = '0';
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
    /* Filter: Node: Type */
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'node';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
      'event' => 'event',
      'event_trustee' => 'event_trustee',
    );
    $handler->display->display_options['filters']['type']['group'] = '0';
    $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
    /* Filter: Date: Date (node) */
    $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
    $handler->display->display_options['filters']['date_filter']['table'] = 'node';
    $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
    $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
    $handler->display->display_options['filters']['date_filter']['group'] = '0';
    $handler->display->display_options['filters']['date_filter']['expose']['operator'] = FALSE;
    $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
      'node_data_field_date.field_date_value' => 'node_data_field_date.field_date_value',
    );
    $handler->display->display_options['filters']['date_filter']['date_method'] = 'OR';
    $handler->display->display_options['filters']['date_filter']['granularity'] = 'day';
    $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_select';
    $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
    $handler->display->display_options['filters']['date_filter']['default_to_date'] = '';
    $handler->display->display_options['filters']['date_filter']['year_range'] = '-3:+3';
    $handler->display->display_options['path'] = 'calendar-date/ical';
    $handler->display->display_options['displays'] = array(
      'calendar_1' => 'calendar_1',
      'default' => 0,
      'calendar_block_1' => 'calendar_block_1',
    );

    /* Display: Upcoming */
    $handler = $view->new_display('block', 'Upcoming', 'block_1');
    $handler->display->display_options['defaults']['title'] = FALSE;
    $handler->display->display_options['title'] = 'Upcoming';
    $handler->display->display_options['defaults']['use_more'] = FALSE;
    $handler->display->display_options['use_more'] = TRUE;
    $handler->display->display_options['defaults']['pager'] = FALSE;
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['pager']['options']['items_per_page'] = 5;
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'list';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'fields';
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Node: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['link_to_node'] = 1;
    /* Field: Broken/missing handler */
    $handler->display->display_options['fields']['field_date']['id'] = 'field_date_value';
    $handler->display->display_options['fields']['field_date']['table'] = 'node_data_field_date';
    $handler->display->display_options['fields']['field_date']['field'] = 'field_date_value';
    $handler->display->display_options['fields']['field_date']['label'] = '';
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    $handler->display->display_options['defaults']['filters'] = FALSE;
    /* Filter: Node: Published */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'node';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = 1;
    $handler->display->display_options['filters']['status']['group'] = '0';
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
    /* Filter: Node: Type */
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'node';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
      'date' => 'date',
    );
    $handler->display->display_options['filters']['type']['group'] = '0';
    $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
    /* Filter: Date: Date (node) */
    $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
    $handler->display->display_options['filters']['date_filter']['table'] = 'node';
    $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
    $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
    $handler->display->display_options['filters']['date_filter']['group'] = '0';
    $handler->display->display_options['filters']['date_filter']['expose']['operator'] = FALSE;
    $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
      'node_data_field_date.field_date_value' => 'node_data_field_date.field_date_value',
    );
    $handler->display->display_options['filters']['date_filter']['date_method'] = 'OR';
    $handler->display->display_options['filters']['date_filter']['granularity'] = 'day';
    $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_select';
    $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
    $handler->display->display_options['filters']['date_filter']['default_to_date'] = '';
    $handler->display->display_options['filters']['date_filter']['year_range'] = '-3:+3';
    $handler->display->display_options['block_description'] = 'Upcoming';

    $views[$view->name] = $view;
  }

  if (isset($views['taxonomy_term'])) {
    $view = new view;
    $view->name = 'taxonomy_term';
    $view->description = 'A view to emulate Drupal core\'s handling of taxonomy/term; it also emulates Views 1\'s handling by having two possible feeds.';
    $view->tag = 'default';
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
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['style_plugin'] = 'default';
    $handler->display->display_options['row_plugin'] = 'node';
    /* Sort criterion: Node: Sticky */
    $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
    $handler->display->display_options['sorts']['sticky']['table'] = 'node';
    $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
    $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
    /* Sort criterion: Content: Publish Date (field_cbc_publish_date) */
    $handler->display->display_options['sorts']['field_cbc_publish_date_value']['id'] = 'field_cbc_publish_date_value';
    $handler->display->display_options['sorts']['field_cbc_publish_date_value']['table'] = 'node_data_field_cbc_publish_date';
    $handler->display->display_options['sorts']['field_cbc_publish_date_value']['field'] = 'field_cbc_publish_date_value';
    $handler->display->display_options['sorts']['field_cbc_publish_date_value']['order'] = 'DESC';
    /* Argument: Taxonomy: Term ID (with depth) */
    $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
    $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
    $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
    $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'not found';
    $handler->display->display_options['arguments']['term_node_tid_depth']['style_plugin'] = 'default_summary';
    $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
    $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['term_node_tid_depth']['validate_type'] = 'taxonomy_term';
    $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vids'] = array(
      3 => 0,
      4 => 0,
      1 => 0,
      5 => 0,
      2 => 0,
    );
    $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['type'] = 'tids';
    $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
    $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = 1;
    /* Argument: Taxonomy: Term ID depth modifier */
    $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['id'] = 'term_node_tid_depth_modifier';
    $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['table'] = 'node';
    $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['field'] = 'term_node_tid_depth_modifier';
    $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['style_plugin'] = 'default_summary';
    $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['default_argument_type'] = 'fixed';
    /* Filter: Node: Published or admin */
    $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
    $handler->display->display_options['filters']['status_extra']['table'] = 'node';
    $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
    $handler->display->display_options['filters']['status_extra']['group'] = 0;
    $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

    /* Display: Page */
    $handler = $view->new_display('page', 'Page', 'page');
    $handler->display->display_options['path'] = 'taxonomy/term/%';

    /* Display: Core feed */
    $handler = $view->new_display('feed', 'Core feed', 'feed');
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = 15;
    $handler->display->display_options['style_plugin'] = 'rss';
    $handler->display->display_options['style_options']['mission_description'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'node_rss';
    $handler->display->display_options['path'] = 'taxonomy/term/%/%/feed';
    $handler->display->display_options['displays'] = array(
      'page' => 'page',
      'default' => 0,
    );

    /* Display: Views 1 feed */
    $handler = $view->new_display('feed', 'Views 1 feed', 'feed_1');
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = 15;
    $handler->display->display_options['style_plugin'] = 'rss';
    $handler->display->display_options['style_options']['mission_description'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'node_rss';
    $handler->display->display_options['path'] = 'taxonomy/term/%/feed';

    $views[$view->name] = $view;
  }
}

