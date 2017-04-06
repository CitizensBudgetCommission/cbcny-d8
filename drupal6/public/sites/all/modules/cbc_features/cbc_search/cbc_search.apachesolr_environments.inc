<?php

/**
 * Implementation of hook_apachesolr_environments().
 */
function cbc_search_apachesolr_environments() {
  $export = array();

  $environment = new stdClass;
  $environment->api_version = 1;
  $environment->env_id = 'solr';
  $environment->name = 'localhost server';
  $environment->url = 'http://localhost:8983/solr/cbcny';
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_index_updated' => 1441378588,
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'blog',
      1 => 'letter',
      2 => 'oped',
      3 => 'page',
      4 => 'pocketsummary',
      5 => 'policy_brief',
      6 => 'presentation',
      7 => 'presscitation',
      8 => 'pressrelease',
      9 => 'report',
      10 => 'reportsummary',
      11 => 'scorecard',
      12 => 'special_feature',
      13 => 'statement',
      14 => 'testimony',
      15 => 'video',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
