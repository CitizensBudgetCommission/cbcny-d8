<?
// $Id$

/**
	* @file
	* Lets users add private annotations to nodes
	* Addds a text field when node is displayed
*/

/** Impleentation of hook_menu() */

function annotate_menu() {
	$items ['admin/settings/annotate'] = array(
		'title' => 'Annotation settins',
		'description' => 'Change how annotations behave.',
		'page callback' => 'drupal_get_form',
		'page arguments' => array('annotate_admin_settings'),
		'access arguments' => array('administer site configuration'),
		'type' => MENU_NORMAL_ITEM,
		'file' => 'annotate.admin.inc',
	);

	return $items;
}