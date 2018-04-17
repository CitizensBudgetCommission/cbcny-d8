<?php

namespace Drupal\cbc_searchable_actions\Plugin\Action;

use Drupal\Core\Field\FieldUpdateActionBase;
use Drupal\node\NodeInterface;

/**
 * Makes a node unsearchable.
 *
 * @Action(
 *   id = "node_make_unsearchable_action",
 *   label = @Translation("Make selected content unsearchable"),
 *   type = "node"
 * )
 */
class MakeNodeUnsearchable extends FieldUpdateActionBase {

  /**
   * {@inheritdoc}
   */
  protected function getFieldsToUpdate() {
    return ['field_searchable' => 'No'];
  }

}
