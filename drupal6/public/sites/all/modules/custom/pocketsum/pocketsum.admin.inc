<?php
// $Id$

/**
 * @file
 * Admin page for pocketsum custom module
 */

/**
 * Admin form
 */
function pocketsum_admin_settings() {

  // Which node is the frontpage?
  $form['POCKETSUM_NAVIGATOR_LANDING_NODE'] = array(
    '#type' => 'textfield',
    '#maxlength' => '5',
    '#size' => '5',
    '#title' => t('Front page for the navigator system'),
    '#default_value' => variable_get('POCKETSUM_NAVIGATOR_LANDING_NODE', '1858'),
    '#description' => t('The first landing page for the whole navigation system.'),
  );
  $form['POCKETSUM_NAVIGATOR_NYCEXP_VID'] = array(
    '#type' => 'textfield',
    '#maxlength' => '5',
    '#size' => '5',
    '#title' => t('NYC Expense VID'),
    '#default_value' => variable_get('POCKETSUM_NAVIGATOR_NYCEXP_VID', '8'),
    '#description' => t('The vocabulary ID for City Expenses'),
  );
  $form['POCKETSUM_NAVIGATOR_NYCREV_VID'] = array(
    '#type' => 'textfield',
    '#maxlength' => '5',
    '#size' => '5',
    '#title' => t('NYC Revenue VID'),
    '#default_value' => variable_get('POCKETSUM_NAVIGATOR_NYCREV_VID', '10'),
    '#description' => t('The vocabulary ID for City Revenues'),
  );
  $form['POCKETSUM_NAVIGATOR_NYSEXP_VID'] = array(
    '#type' => 'textfield',
    '#maxlength' => '5',
    '#size' => '5',
    '#title' => t('NYS Expense VID'),
    '#default_value' => variable_get('POCKETSUM_NAVIGATOR_NYSEXP_VID', '11'),
    '#description' => t('The vocabulary ID for State Expenses'),
  );
  $form['POCKETSUM_NAVIGATOR_NYSREV_VID'] = array(
    '#type' => 'textfield',
    '#maxlength' => '5',
    '#size' => '5',
    '#title' => t('NYS Revenue VID'),
    '#default_value' => variable_get('POCKETSUM_NAVIGATOR_NYSREV_VID', '12'),
    '#description' => t('The vocabulary ID for City Expenses'),
  );

  
  return system_settings_form($form);

}

