<?php

namespace Drupal\book\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Provides the 'CBC Status Bar' block.
 *
 * @Block(
 *   id = "cbc_status_bar",
 *   admin_label = @Translation("CBC Status bar"),
 *   category = @Translation("Custom")
 * )
 */
class StatusBarBlock extends BlockBase implements ContainerFactoryPluginInterface {

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    $settings = $container->get('config.factory')
      ->get('cbc_status_bar.settings');
    return new static(
      $settings->get(),
      $plugin_id,
      $plugin_definition
    );
  }

  /**
   * {@inheritdoc}
   */
  public function defaultConfiguration() {
    return [
      'enabled' => FALSE,
      'message' => '',
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function build() {
    if ($this->configuration['enabled']) {
      return [
        '#theme' => 'cbc_status_bar_block',
        '#message' => $this->configuration['message'],
      ];
    }
    return [];
  }

}
