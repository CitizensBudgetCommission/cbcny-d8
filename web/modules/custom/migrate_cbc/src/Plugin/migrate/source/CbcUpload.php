<?php

namespace Drupal\migrate_cbc\plugin\migrate\source;

use Drupal\file\Plugin\migrate\source\d6\Upload;

/**
 * Drupal 6 upload source from database. With an added changed date from the node.
 *
 * @MigrateSource(
 *   id = "cbc_d6_upload",
 *   source_provider = "upload"
 * )
 */
class CbcUpload extends Upload {

  public function query() {
    $query = parent::query();
    // Add the node's changed field to use as a highwater mark.
    $query->addField('n', 'changed');
    // Only migrate published content.
    $query->condition('n.status', 1);
    // Offer a list of source content types.
    if (isset($this->configuration['node_type_list'])) {
      $query->condition('n.type', $this->configuration['node_type_list'], 'IN');
    }
    return $query;
  }

  public function fields() {
    return parent::fields() + [
      'changed' => $this->t('Last updated timestamp from the associated node'),
    ];
  }
}