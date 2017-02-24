<?php
// $Id: template.php,v 1.17 2008/09/11 10:52:54 johnalbin Exp $

/**
 * @file
 * Contains theme override functions and preprocess functions for the theme.
 *
 * ABOUT THE TEMPLATE.PHP FILE
 *
 *   The template.php file is one of the most useful files when creating or
 *   modifying Drupal themes. You can add new regions for block content, modify
 *   or override Drupal's theme functions, intercept or make additional
 *   variables available to your theme, and create custom PHP logic. For more
 *   information, please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/theme-guide
 *
 * OVERRIDING THEME FUNCTIONS
 *
 *   The Drupal theme system uses special theme functions to generate HTML
 *   output automatically. Often we wish to customize this HTML output. To do
 *   this, we have to override the theme function. You have to first find the
 *   theme function that generates the output, and then "catch" it and modify it
 *   here. The easiest way to do it is to copy the original function in its
 *   entirety and paste it here, changing the prefix from theme_ to STARTERKIT_.
 *   For example:
 *
 *     original: theme_breadcrumb()
 *     theme override: STARTERKIT_breadcrumb()
 *
 *   where STARTERKIT is the name of your sub-theme. For example, the
 *   cbcny theme would define a cbcny_breadcrumb() function.
 *
 *   If you would like to override any of the theme functions used in Zen core,
 *   you should first look at how Zen core implements those functions:
 *     theme_breadcrumbs()      in zen/template.php
 *     theme_menu_item_link()   in zen/template.php
 *     theme_menu_local_tasks() in zen/template.php
 *
 *   For more information, please visit the Theme Developer's Guide on
 *   Drupal.org: http://drupal.org/node/173880
 *
 * CREATE OR MODIFY VARIABLES FOR YOUR THEME
 *
 *   Each tpl.php template file has several variables which hold various pieces
 *   of content. You can modify those variables (or add new ones) before they
 *   are used in the template files by using preprocess functions.
 *
 *   This makes THEME_preprocess_HOOK() functions the most powerful functions
 *   available to themers.
 *
 *   It works by having one preprocess function for each template file or its
 *   derivatives (called template suggestions). For example:
 *     THEME_preprocess_page    alters the variables for page.tpl.php
 *     THEME_preprocess_node    alters the variables for node.tpl.php or
 *                              for node-forum.tpl.php
 *     THEME_preprocess_comment alters the variables for comment.tpl.php
 *     THEME_preprocess_block   alters the variables for block.tpl.php
 *
 *   For more information on preprocess functions, please visit the Theme
 *   Developer's Guide on Drupal.org: http://drupal.org/node/223430
 *   For more information on template suggestions, please visit the Theme
 *   Developer's Guide on Drupal.org: http://drupal.org/node/223440 and
 *   http://drupal.org/node/190815#template-suggestions
 */


/*
 * Add any conditional stylesheets you will need for this sub-theme.
 *
 * To add stylesheets that ALWAYS need to be included, you should add them to
 * your .info file instead. Only use this section if you are including
 * stylesheets based on certain conditions.
 */
// Optionally add the fixed width CSS file.
if (theme_get_setting('cbcny_fixed')) {
  drupal_add_css(path_to_theme() . '/zen-fixed.css', 'theme', 'all');
}


/**
 * Implementation of HOOK_theme().
 */
function cbcny_theme(&$existing, $type, $theme, $path) {
  return zen_theme($existing, $type, $theme, $path);
}

/**
 * Override or insert variables into all templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered (name of the .tpl.php file.)
 */
/* -- Delete this line if you want to use this function
function cbcny_preprocess(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the page templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function cbcny_preprocess_page(&$vars, $hook) {
  global $base_url, $user;
  $vars['page_theme_path'] = "$base_url/" . path_to_theme();
  $tree = menu_tree_page_data(variable_get('menu_primary_links_source', 'primary-links'));
  $vars['primary_links'] = menu_tree('primary-links');

  // Remove the sidebar-left class from pages. This is added by core, but has a namespace conflict with Zen theme's left sidebar.
  if (strpos($vars['body_classes'], 'sidebar-left')) {
    $classes = explode(' ', $vars['body_classes']);
    $target_key = reset(array_keys($classes, 'sidebar-left'));
    unset($classes[$target_key]);
    $vars['body_classes'] = implode(' ', $classes); // Concatenate with spaces.

  }



  if (arg(0) == 'user'){
    if (!$user->uid) { //check to see if the user is logged in. If not display the special login page layout
      $vars['template_file'] = 'page-login';
    }
    elseif (arg(1) == 'login' || arg(1) == 'register' || arg(1) == 'password' ) {
      $vars['template_file'] = 'page-login';
    }
  }
  if (arg(0) == 'search' && arg(1) == 'site') {
    $vars['template_file'] = 'page-search';
  }

  //$vars['menu_links'] = $menu_links;
  //$vars['menu_links'] = phptemplate_cbc_primary_nav($tree);
  // switch to page tempalte if a browse by
  $reg_pages = array(
    'page-browseby',
    'page-cbc-blogs',
    'page-cbc-events',
    'page-cbc-home',
    'page-taxonomy',
    'page-workinprogress',
    'page-committees',
  );
  $found = array_intersect($reg_pages, $vars['template_files']);
  if(!empty($found) || $vars['is_front']) {
    $vars['template_file'] = 'page-node';
  }

  if ($user->uid) {
    $user_links = array(
      theme('username', $user),
      l('log out', 'logout'),
    );
  }
  else {
    $user_links = array(
      l('log in', 'user/login'),
    );
  }

  $vars['user_links'] = '<div id="user-links">' . implode(' | ', $user_links) . '</div>';

  // template file just for pocket summaries
  if (arg(0) == 'summary' && arg(3) == 'navigator') {
    $vars['template_file'] = 'view-navigator-page';
  };
  if (arg(0) == 'node' && arg(1) == variable_get('POCKETSUM_NAVIGATOR_LANDING_NODE', '1858')) {
    $vars['template_file'] = 'page-navigator-landing';
  };
};

/**
 * Implements theme_apachesolr_search_suggestions()
 * Wrap search suggestions in a card layout.
 */
function phptemplate_apachesolr_search_suggestions($variables) {
  // Add card div openers.
  $output = '<div class="Block">
	    <div class="Block-tl"></div>
	    <div class="Block-tr"><div></div></div>
	    <div class="Block-bl"><div></div></div>
	    <div class="Block-br"><div></div></div>
	    <div class="Block-tc"><div></div></div>
	    <div class="Block-bc"><div></div></div>
	    <div class="Block-cl"><div></div></div>
	    <div class="Block-cr"><div></div></div>
	    <div class="Block-cc"></div>
	    <div class="Block-body">';
  $output .= '<div class="spelling-suggestions">';
  $output .= '<dl class="form-item"><dt><strong>' . t('Did you mean') . '</strong></dt>';
  foreach ((array) $variables as $link) {
    $output .= '<dd>' . $link . '</dd>';
  }
  $output .= '</dl></div>';
  // Close card divs.
  $output .= '</div></div>';
  return $output;
}

/**
 * Implementation of theme_menu_item_link().
 *
 * Integrates Menu Class
 */
function phptemplate_menu_item_link($link) {
  if (function_exists('menuclass_to_link')) {
    menuclass_to_link($link);
  }
  return theme_menu_item_link($link);
}

function phptemplate_cbc_primary_nav($links) {
  $i = 1;
  foreach($links as $link) {
    if(count($links) == $i) {
      $link['link']['href'] = 'http://www.nycharities.org/donate/c_donate.asp?CharityCode=2336';
      $link['link']['localized_options']['attributes']['target'] = '_blank';
    }
    $link['link']['title'] = '';
    $output .= theme('menu_item_link', $link['link']);
    $i++;
  }
  return $output;
}

function phptemplate_primary_nav($mtree) {
  $output = '';
  // Rebuild the nav
  $output = "<ul>";
  foreach($mtree as $id => $tree) {
    if(!empty($tree['below'])) {
      $blinks = array();
      $bi = 1;
      foreach($tree['below'] as $bid => $btree) {
        $blinks["mlid-" . $btree['link']['mlid']] = $btree['link'];
      }
      $boutput = '<span class="top-block"></span>';
      $boutput .= theme('links', $blinks);
    }
    $output .= "<li>" . theme('menu_item_link', $tree['link']) . $boutput . "</li>\n";
    $boutput = '';
  }
  $output .= "</ul>";
  return $output;
}

/**
 * Override or insert variables into the node templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */

function cbcny_preprocess_node(&$vars, $hook) {
  static $node_info;
  if(empty($node_info)) {
    $node_info = node_get_types();
  }
  $vars['type_name'] = $node_info[$vars['type']]->name;
  // Prepare $read_more_path variable depending on content type.
  $vars['read_more_link'] = l(t('Read more'), 'node/' . $vars['node']->nid, array('title' => t('Read the rest of this posting.')), NULL, NULL, TRUE);
  if ($vars['node']->type == 'oped') {
    $vars['read_more_link'] = l(t('Read more'), 'node/' . $vars['node']->field_title_link[0]['url'], array('title' => t('Read the rest of this posting.'), 'attributes' => array('target' => '_blank')), NULL, NULL, TRUE);
    $vars['node']->readmore = TRUE;
  }
}


/**
 * Override or insert variables into the comment templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function cbcny_preprocess_comment(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function cbcny_preprocess_block(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

// OVERRIDE RSS FEED ICON WITH TEXT
function phptemplate_feed_icon($url, $title) {
    return '<a href="'. check_url($url) . '" class="feed">' . "RSS for this page" . '</a>';
}


/**
 * Implementation of hook_search_theme_form()
 */
function cbcny_preprocess_search_theme_form(&$vars) {
  $vars['search_form'] .= '<div class="advanced-link-wrapper">' . l('Advanced', 'search') . '</div>';
}

/**
 * Implementation of theme_jcalendar_view()
 */
function cbcny_jcalendar_view($node) {
  $node_info = node_get_types();

  $node = node_build_content($node, TRUE);

  $node->links = module_invoke_all('link', 'node', $node, $teaser);
  drupal_alter('link', $node->links, $node);

  $node->teaser = drupal_render($node->content);
  unset($node->body);

  node_invoke_nodeapi($node, 'alter', TRUE);
  $type_name = $node_info[$node->type]->name;

  $output = '
    <div class="node-inner">
      <h2 class="title">' . check_plain($node->title) . '</h2>
      <div class="content">
        <div class="teaser">' . $node->teaser . '</div>
      </div>
      <div class="node-footer">' . $node->service_links_rendered . '
        <div class="node-title-type ' . $node->type . '">' . l($type_name, 'browseby/type/' . $type) . '</div>
      </div>

      <div class="admin-inline">
        <div class="admin-border admin-border-top"></div>
      </div>
    </div>';

  $output .= '<div id="nodelink">'. l(t('more', array(), $node->language), calendar_get_node_link($node)) .'</div>';
  return $output;
}

/**
 * Change theming of facet link to make post date facets nicer.
 */
function cbcny_apachesolr_facet_link($facet_text, $path, $options = array(), $count, $active = FALSE, $num_found = NULL) {
  // Recognize post date facet text and change it.
  if (preg_match('/[0-9]{4}-[0-9]{2}-[0-9]{2}T[0-9]{2}:[0-9]{2}:[0-9]{2}Z/', $facet_text)) {
    $facet_text = format_date(strtotime($facet_text), 'custom', 'D, m/d/Y');
  }

  $options['attributes']['class'][] = 'apachesolr-facet';
  if ($active) {
    $options['attributes']['class'][] = 'active';
  }
  $options['attributes']['class'] = implode(' ', $options['attributes']['class']);
  return apachesolr_l($facet_text ." ($count)",  $path, $options);
}

/**
 * Change theming of unclick facet link.
 */
function cbcny_apachesolr_unclick_link($facet_text, $path, $options = array()) {
  apachesolr_js();
  if (empty($options['html'])) {
    $facet_text = check_plain(html_entity_decode($facet_text));
  }
  else {
    // Don't pass this option as TRUE into apachesolr_l().
    unset($options['html']);
  }

  // Recognize post date facet text and change it.
  if (preg_match('/[0-9]{4}-[0-9]{2}-[0-9]{2}T[0-9]{2}:[0-9]{2}:[0-9]{2}Z/', $facet_text)) {
    $facet_text = format_date(strtotime($facet_text), 'custom', 'D, m/d/Y');
  }

  $options['attributes']['class'] = 'apachesolr-unclick';
  return apachesolr_l("(-)", $path, $options) . ' '. $facet_text;
}

/**
 * strip Date module's unnecessary spans
 */
function cbcny_date_display_single($date, $timezone = NULL) {
  return $date . $timezone;
}


function phptemplate_preprocess_node(&$vars) {
  if(module_exists('service_links')) {
    $vars['service_links'] = theme('links', service_links_render($vars['node'], TRUE));
  }
}
