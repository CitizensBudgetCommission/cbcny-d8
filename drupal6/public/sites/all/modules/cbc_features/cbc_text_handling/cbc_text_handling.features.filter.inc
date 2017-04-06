<?php

/**
 * Implementation of hook_filter_default_formats().
 */
function cbc_text_handling_filter_default_formats() {
  $formats = array();

  // Exported format: Filtered HTML
  $formats['Filtered HTML'] = array(
    'name' => 'Filtered HTML',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'filters' => array(
      '0' => array(
        'module' => 'filter',
        'delta' => '2',
        'weight' => '0',
      ),
      '1' => array(
        'module' => 'filter',
        'delta' => '0',
        'weight' => '1',
      ),
      '2' => array(
        'module' => 'filter',
        'delta' => '1',
        'weight' => '2',
      ),
      '3' => array(
        'module' => 'filter',
        'delta' => '3',
        'weight' => '10',
      ),
    ),
  );

  // Exported format: Full HTML
  $formats['Full HTML'] = array(
    'name' => 'Full HTML',
    'roles' => array(
      'Administrators' => 'Administrators',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'Trustee' => 'Trustee',
      'Under 40 Member' => 'Under 40 Member',
    ),
    'filters' => array(
      '0' => array(
        'module' => 'filter',
        'delta' => '3',
        'weight' => '10',
      ),
      '1' => array(
        'module' => 'htmLawed',
        'delta' => '0',
        'weight' => '10',
      ),
    ),
  );

  // Exported format: Video text
  $formats['Video text'] = array(
    'name' => 'Video text',
    'roles' => array(
      'Administrators' => 'Administrators',
      'authenticated user' => 'authenticated user',
      'Trustee' => 'Trustee',
    ),
    'filters' => array(
      '0' => array(
        'module' => 'filter',
        'delta' => '1',
        'weight' => '10',
      ),
    ),
  );

  // Exported format: PHP
  $formats['PHP'] = array(
    'name' => 'PHP',
    'roles' => array(
      'Administrators' => 'Administrators',
    ),
    'filters' => array(
      '0' => array(
        'module' => 'php',
        'delta' => '0',
        'weight' => '10',
      ),
    ),
  );

  return $formats;
}
