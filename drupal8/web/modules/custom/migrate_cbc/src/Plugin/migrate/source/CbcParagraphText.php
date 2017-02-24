<?php

namespace Drupal\migrate_cbc\plugin\migrate\source;

use Drupal\migrate\Row;
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

  public function fields() {
    return parent::fields() + [
      'files' => $this->t('Files attached directly to the D6 node'),
    ];
  }

  public function prepareRow(Row $row) {
    parent::prepareRow($row);
    $row = $this->addFiles($row);
    return $row;
  }

  /**
   * Add files to the row.
   * OK, this could just as easily have happened in $this->query(). But technically
   * joins are SUPPOSED to happen in prepareRow so as not to slow up the primary
   * query when it's used for counts, etc. Plus, this makes a better example.
   *
   * @param \Drupal\migrate\Row $row
   * @return \Drupal\migrate\Row
   */
  private function addFiles(Row $row) {
    $query = $this->select('upload', 'u')
      ->distinct()
      ->fields('u', array('nid', 'vid'));
    $query->condition('u.nid', $row->getSourceProperty('nid'));
    $fids = $query->execute()
      ->fetchCol(0);
    $row->setSourceProperty('files', $fids);

    return $row;
  }
}