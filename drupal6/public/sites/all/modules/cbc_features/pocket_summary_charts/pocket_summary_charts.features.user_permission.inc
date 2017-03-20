<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function pocket_summary_charts_user_default_permissions() {
  $permissions = array();

  // Exported permission: create expense content
  $permissions['create expense content'] = array(
    'name' => 'create expense content',
    'roles' => array(
      'Administrators' => 'Administrators',
    ),
  );

  // Exported permission: create pocketsum_sponsor content
  $permissions['create pocketsum_sponsor content'] = array(
    'name' => 'create pocketsum_sponsor content',
    'roles' => array(
      'Administrators' => 'Administrators',
    ),
  );

  // Exported permission: delete any expense content
  $permissions['delete any expense content'] = array(
    'name' => 'delete any expense content',
    'roles' => array(
      'Administrators' => 'Administrators',
    ),
  );

  // Exported permission: delete any pocketsum_sponsor content
  $permissions['delete any pocketsum_sponsor content'] = array(
    'name' => 'delete any pocketsum_sponsor content',
    'roles' => array(
      'Administrators' => 'Administrators',
    ),
  );

  // Exported permission: edit any expense content
  $permissions['edit any expense content'] = array(
    'name' => 'edit any expense content',
    'roles' => array(
      'Administrators' => 'Administrators',
    ),
  );

  // Exported permission: edit any pocketsum_sponsor content
  $permissions['edit any pocketsum_sponsor content'] = array(
    'name' => 'edit any pocketsum_sponsor content',
    'roles' => array(
      'Administrators' => 'Administrators',
    ),
  );

  // Exported permission: edit field_expense_value
  $permissions['edit field_expense_value'] = array(
    'name' => 'edit field_expense_value',
    'roles' => array(),
  );

  // Exported permission: edit field_expense_year
  $permissions['edit field_expense_year'] = array(
    'name' => 'edit field_expense_year',
    'roles' => array(),
  );

  // Exported permission: edit field_sponsor_link
  $permissions['edit field_sponsor_link'] = array(
    'name' => 'edit field_sponsor_link',
    'roles' => array(),
  );

  // Exported permission: edit field_sponsor_logo
  $permissions['edit field_sponsor_logo'] = array(
    'name' => 'edit field_sponsor_logo',
    'roles' => array(),
  );

  // Exported permission: use views exporter
  $permissions['use views exporter'] = array(
    'name' => 'use views exporter',
    'roles' => array(
      'Administrators' => 'Administrators',
    ),
  );

  // Exported permission: view field_expense_value
  $permissions['view field_expense_value'] = array(
    'name' => 'view field_expense_value',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
  );

  // Exported permission: view field_expense_year
  $permissions['view field_expense_year'] = array(
    'name' => 'view field_expense_year',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
  );

  // Exported permission: view field_sponsor_link
  $permissions['view field_sponsor_link'] = array(
    'name' => 'view field_sponsor_link',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
  );

  // Exported permission: view field_sponsor_logo
  $permissions['view field_sponsor_logo'] = array(
    'name' => 'view field_sponsor_logo',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
  );

  return $permissions;
}
