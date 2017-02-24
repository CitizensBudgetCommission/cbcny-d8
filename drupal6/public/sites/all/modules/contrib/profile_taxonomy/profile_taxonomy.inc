<?php
// $Id: profile_taxonomy.inc,v 1.1 2010/12/30 15:10:58 gnindl Exp $

/**
 * @file profile_taxonomy.inc
 * Miscelleanous functions for profile_taxonomy, 
 * e. g. for i18n or accessing profile field values.
 */

/**
 * Localize a term by replacing its name attribute with its localized version
 * for the current language.
 *
 * @param $term
 *   The term to localize.
 *
 * This is based on i18ntaxonomy_localize_terms(), but with less overhead.
 */
function profile_taxonomy_localize_term(&$term) {
  // If this term's vocabulary supports localization.
  if (module_exists('i18ntaxonomy') && i18ntaxonomy_vocabulary($term->vid) == I18N_TAXONOMY_LOCALIZE) {
    $term->name = tt("taxonomy:term:$term->tid:name", $term->name);
  }
}

/**
 * Localize a vocabulary by replacing its name attribute with its localized
 * version for the current language.
 *
 * @param $vocabulary
 *   The vocabulary to localize.
 */
function profile_taxonomy_localize_vocabulary(&$vocabulary) {
  // If this vocabulary supports localization.
  if (module_exists('i18ntaxonomy') && i18ntaxonomy_vocabulary($vocabulary->vid) == I18N_TAXONOMY_LOCALIZE) {
    $vocabulary->name = tt("taxonomy:vocabulary:$vocabulary->vid:name", $vocabulary->name);
  }
}

/**
 * Save field selection options.
 * @param $fid
 *   integer field id
 * @param $options
 *   array of options
 */
function profile_taxonomy_save_selection_options($fid, $options) {
  if (is_array($options)) {
    $options = implode("\r\n", $options);
  }
  db_query("UPDATE profile_fields SET options = '%s' WHERE fid = %d", $options, $fid);
}

/**
 * Get a list of all terms with their term id as key and the term name as value.
 * @param $vid
 *   vocabulary id
 * @return
 *   associative array of vocabulary terms
 */
function profile_taxonomy_get_list_vocabulary_terms($vid, $parent = 0, $hierarchy = 1, $max_depth = NULL) {
 // static $terms = array('keys' => array(), 'values' => array());  
  $tree = taxonomy_get_tree($vid, $parent, -1, $max_depth); //get taxonomy terms
  if ($tree) { //build tree, i. e. term list
    foreach ($tree as $leaf) {
      $terms['keys'][] = $leaf->tid;
      $terms['depths'][] = $leaf->depth;
      if ($hierarchy) {
        $terms['values'][] = str_repeat('- ', $leaf->depth) . $leaf->name;
      }
      else {
        $terms['values'][] = $leaf->name;
      }
    }
  }
  return $terms;
}

/**
 * Prepare vocabularies in an array understandable
 * for a selection widget (drop-down).
 * @return
 *   associative array of vocabularies (id as key, name as value)
 */
function profile_taxonomy_vocabularies_options_list() {
  $vocabs = taxonomy_get_vocabularies(); //get all vocabularies and provide terms

  $options = array();
  $options[] = t('- None selected -');
  foreach ($vocabs as $voc) { //prepare vocabularies to be displayed in an option widget
    profile_taxonomy_localize_vocabulary($voc);
    $options[$voc->vid] = $voc->name;
  }

  return $options;
}

/**
 * Get a profile field by id.
 * @param $fid
 *   profile field id
 * @return
 *   object profile field 
 */
function profile_taxonomy_get_profile_field_by_id($fid) {
  static $fields = array();
  if (empty($fields[$fid])) {
    $fields[$fid] = db_fetch_object(db_query('SELECT * FROM {profile_fields} WHERE fid = %d', $fid));
  }
  return $fields[$fid];
}

/**
 * Get a profile field by name.
 * @param $name
 *   profile name
 * @return
 *   object profile field
 */
function profile_taxonomy_get_profile_field_by_name($name) {
  static $fields = array();
  if (empty($fields[$name])) {
    $fields[$name] = db_fetch_object(db_query("SELECT * FROM {profile_fields} WHERE name = '%s'", $name));
  }
  return $fields[$name];
}