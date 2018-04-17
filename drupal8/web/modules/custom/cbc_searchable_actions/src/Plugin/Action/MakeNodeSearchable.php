<?php

namespace Drupal\cbc_searchable_actions\Plugin\Action;

use Drupal\Core\Field\FieldUpdateActionBase;
use Drupal\node\NodeInterface;

/**
 * Makes a node searchable.
 *
 * @Action(
 *   id = "node_make_searchable_action",
 *   label = @Translation("Make selected content searchable"),
 *   type = "node"
 * )
 */
class MakeNodeSearchable extends FieldUpdateActionBase {

  /**
   * {@inheritdoc}
   */
  protected function getFieldsToUpdate() {
    return ['field_searchable' => 'Yes'];
  }

}
