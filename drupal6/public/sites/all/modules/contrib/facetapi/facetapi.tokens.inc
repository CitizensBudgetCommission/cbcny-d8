<?php

/**
 * @file
 * Builds placeholder replacement tokens for searches.
 */

/**
 * Implements hook_token_list().
 */
function facetapi_token_list() {
  $results = $active = $facet = array();

  // Tokens related to search results and response.
  $results['keys'] = t('Search keywords');

  $results['page-number'] = t('Page number');

  $results['page-limit'] = t('Page limit');

  $results['page-total'] = t('Page total');

  $results['offset'] = t('Offset');

  $results['start-count'] = t('Start count');

  $results['end-count'] = t('End count');

  $results['result-count'] = t('Result count');

  // Tokens related to active facet items.
  $active['active-value'] = t('Mapped value');

  $active['active-value-raw'] = t('Raw value');

  $active['active-pos'] = t('Position');

  $active['facet-label'] = t('Facet label');

  $active['facet-name'] = t('Facet name');

  // Tokens related to a facet.
  $facet['facet-label'] = t('Facet label');

  $facet['facet-name'] = t('Facet name');

  return array(
    'facetapi_results' => $results,
    'facetapi_active' => $active,
    'facetapi_facet' => $facet,
  );
}

/**
 * Implements hook_token_values().
 */
function facetapi_token_values($type, $object = NULL, $options = array()) {
  $values = array();

  if ('facetapi_results' == $type && !empty($object)) {
    $adapter = $object;
    
    $values['keys'] = check_plain($adapter->getSearchKeys());
    $values['result-count'] = (int) $adapter->getResultCount();
    $values['page-number'] = (int) $adapter->getPageNumber();
    $values['page-limit'] = (int) $adapter->getPageLimit();
    $values['page-total'] = (int) $adapter->getPageTotal();

    $offset = ($adapter->getPageNumber() - 1) * $adapter->getPageLimit();
    $values['offset'] = $offset;

    $offset = (($adapter->getPageNumber() - 1) * $adapter->getPageLimit()) + 1;
    $values['start-count'] = $offset;

    $page_max = $adapter->getPageNumber() * $adapter->getPageLimit();
    $total_max = (int) $adapter->getResultCount();
    $values['end-count'] = min($page_max, $total_max);
  }  
  elseif ('facetapi_active' == $type && !empty($object)) {
    $item = $object;
    $adapter = $item['adapter'];

    $markup = $adapter->getMappedValue($item['facets'][0], $item['value']);
    $text = empty($markup['#html']) ? check_plain($markup['#value']) : $markup['#value'];
    $values['active-value'] = $text;

    $values['active-value-raw'] = check_plain($item['value']);
    $values['active-pos'] = $item['pos'];

    if ($facet = facetapi_facet_load($item['facets'][0], $adapter->getSearcher())) {
      $values['facet-label'] = check_plain($facet['label']);
    }

    $values['facet-name'] = check_plain($item['facets'][0]);
  }
  elseif ('facetapi_facet' == $type && !empty($object)) {
    $facet = $object;

    $values['facet-label'] = check_plain($facet['label']);

    $values['facet-name'] = check_plain($facet['name']);
  }
  
  return $values;
}