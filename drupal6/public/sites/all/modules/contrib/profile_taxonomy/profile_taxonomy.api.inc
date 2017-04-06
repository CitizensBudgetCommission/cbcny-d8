<?php
// $Id: profile_taxonomy.api.inc,v 1.5 2010/12/30 15:10:58 gnindl Exp $

/**
 * @file profile_taxonomy.api.inc
 * The developer's API for this module layers the access and the handling of database transactions.
 */

/**
 * Get information about an user profile field vocabulary relation.
 * @param $fid
 *   field id
 * @return
 *   integer of vocabulary id
 */
function profile_taxonomy_get_reference($fid) {
  if (!$fid && !intval($fid))
    return;
    
  $sql = "SELECT * FROM {profile_taxonomy} WHERE fid = %d";
  $reference = db_fetch_object(db_query($sql, intval($fid)));
  if ($reference) { //only unserialize existing db row
    $reference->terms = unserialize($reference->terms);
    $reference->settings = unserialize($reference->settings);
  }
  return $reference;
}

/**
 * Get all profile fields which use a certain vocabulary.
 * @param $vid
 *   vocabulary id
 * @return
 *   array of profile field objects (db table profile_fields)
 */
function profile_taxonomy_get_references_by_vid($vid) {
  if (!$vid && !intval($vid))
    return;  
 
  $sql = "SELECT * FROM {profile_taxonomy} WHERE vid = %d";
  $result = db_query($sql, intval($vid));
  $references = array();
  while (($reference = db_fetch_object($result)) != NULL) {
  	$reference->terms = unserialize($reference->terms);
    $reference->settings = unserialize($reference->settings);
  	$references[] = $reference;
  }
  return $references;
}

/**
 * Get all field vocabulary assignements.
 * @return
 *   profile taxonomy assignements
 */
function profile_taxonomy_get_all_references() {
  static $references = array();
  if (empty($references)) {
    $result = db_query('SELECT * FROM {profile_taxonomy}');
    while (($reference = db_fetch_object($result)) != NULL) {
      $reference->terms = unserialize($reference->terms);
  	  $reference->settings = unserialize($reference->settings);
      $references[] = $reference;
    }
  }
  return $references;
}

/**
 * Create or update a field vocabulary reference.
 * @param $reference
 *   object to be saved
 * @return
 *   status of db operation
 */
function profile_taxonomy_save_reference($reference) {
  //check if field reference already exists
  if (!profile_taxonomy_get_reference($reference->fid)) { //create a new instance
   $success = db_query("INSERT INTO {profile_taxonomy} VALUES (%d, %d, '%s', '%s')", 
   		intval($reference->fid), 
   		intval($reference->vid), 
   		serialize($reference->terms), 
   		serialize($reference->settings)
   );
 }
 else { //update existing instance
   $success = db_query("UPDATE {profile_taxonomy} SET vid = %d, terms = '%s', settings = '%s' WHERE fid = %d", 
   		intval($reference->vid), 
   		serialize($reference->terms), 
   		serialize($reference->settings),
   		intval($reference->fid)
   );
 }
 if ($success) {
   profile_taxonomy_save_selection_options($reference->fid, $reference->terms['values']); //save field options
   drupal_set_message('Profile Taxonomy term references have been successfully saved.');
 }
 else {
   drupal_set_message('Profile Taxonomy term references could not be saved.', 'error');
 }
 return $success;
}


/**
 * Delete a specific field vocabulary association
 * @param $field
 *   name of the profile field
 * @return
 *   status of db operation
 */
function profile_taxonomy_delete_reference($fid) {
  if (!$fid)
    return;
  return db_query("DELETE FROM {profile_taxonomy} WHERE fid = %d", $fid);
}

/**
 * Delete all profile fields association of a vocabulary.
 * @param $vid
 *   vocabulary id
 * @return
 *   status of db operation
 */
function profile_taxonomy_delete_references_by_vid($vid) {
  if (!$vid)
    return;
  return db_query("DELETE FROM {profile_taxonomy} WHERE vid = %d", $vid);
}