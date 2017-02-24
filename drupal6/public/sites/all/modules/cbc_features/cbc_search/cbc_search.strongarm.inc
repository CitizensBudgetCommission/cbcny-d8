<?php

/**
 * Implementation of hook_strongarm().
 */
function cbc_search_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_cron_limit';
  $strongarm->value = '0';
  $export['search_cron_limit'] = $strongarm;

  return $export;
}
