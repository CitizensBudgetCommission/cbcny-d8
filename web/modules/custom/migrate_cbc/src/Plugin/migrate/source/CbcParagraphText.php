<?php

namespace Drupal\migrate_cbc\plugin\migrate\source;

use Drupal\node\Plugin\migrate\source\d6\Node;

/**
 * Source plugin for full_text paragraphs. Gets the node body out of particular
 * types, and turns it into paragraphs.
 *
 * @MigrateSource(
 *   id = "cbc_paragraph_text"
 * )
 */
class CbcParagraphText extends Node {

  public function query() {
    $query = parent::query();
    // Only migrate published content
    $query->condition('n.status', 1);
    // Offer a list of source content types.
    if (isset($this->configuration['node_type_list'])) {
      $query->condition('n.type', $this->configuration['node_type_list'], 'IN');
    }
    return $query;
  }
}