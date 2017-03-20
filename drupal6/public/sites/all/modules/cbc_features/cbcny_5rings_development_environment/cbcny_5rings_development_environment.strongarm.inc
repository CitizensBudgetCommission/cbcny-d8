<?php

/**
 * Implementation of hook_strongarm().
 */
function cbcny_5rings_development_environment_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filter_pathologic_absolute_1';
  $strongarm->value = 1;
  $export['filter_pathologic_absolute_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filter_pathologic_absolute_2';
  $strongarm->value = 1;
  $export['filter_pathologic_absolute_2'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filter_pathologic_absolute_4';
  $strongarm->value = 1;
  $export['filter_pathologic_absolute_4'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filter_pathologic_absolute_5';
  $strongarm->value = 1;
  $export['filter_pathologic_absolute_5'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filter_pathologic_local_paths_1';
  $strongarm->value = 'www.cbcny.org/
cbcny.org/
staging.cbcny.org/
dev.5ringsweb.com/cbcny-support/
localhost/cbcny-support/
/cbcny-support/
/';
  $export['filter_pathologic_local_paths_1'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filter_pathologic_local_paths_2';
  $strongarm->value = 'www.cbcny.org/
cbcny.org/
staging.cbcny.org/
dev.5ringsweb.com/cbcny-support/
localhost/cbcny-support/
/cbcny-support/
/';
  $export['filter_pathologic_local_paths_2'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filter_pathologic_local_paths_4';
  $strongarm->value = 'www.cbcny.org/
cbcny.org/
staging.cbcny.org/
dev.5ringsweb.com/cbcny-support/
localhost/cbcny-support/
/cbcny-support/
/';
  $export['filter_pathologic_local_paths_4'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filter_pathologic_local_paths_5';
  $strongarm->value = 'www.cbcny.org/
cbcny.org/
staging.cbcny.org/
dev.5ringsweb.com/cbcny-support/
localhost/cbcny-support/
/cbcny-support/
/';
  $export['filter_pathologic_local_paths_5'] = $strongarm;

  return $export;
}
