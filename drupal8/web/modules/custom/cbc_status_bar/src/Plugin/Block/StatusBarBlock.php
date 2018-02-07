<?php

namespace Drupal\cbc_status_bar\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Provides the 'CBC Status Bar' block.
 *
 * @Block(
 *   id = "cbc_status_bar",
 *   admin_label = @Translation("CBC Status bar"),
 *   category = @Translation("Custom")
 * )
 */
class StatusBarBlock extends BlockBase {

  /**
   * {@inheritdoc}
   */
  public function blockForm($form, FormStateInterface $form_state) : array {
    $form = parent::blockForm($form, $form_state);
    $config = $this->getConfiguration();
    $form['note'] = [
      '#markup' => $this->t('Note: these settings can also be configured from the CBC Status Bar block admin menu item.'),
    ];
    // Enabled checkbox.
    $form['enabled'] = [
      '#type' => 'checkbox',
      '#title' => $this->t('Enable the status bar'),
      '#description' => $this->t('When checked, the status bar will be displayed on all pages.'),
      '#default_value' => $config['enabled'],
    ];
    // Status message.
    $form['message'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Message'),
      '#description' => $this->t('The message to display. May include HTML.'),
      '#default_value' => $config['message'],
    ];

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function blockSubmit($form, FormStateInterface $form_state) {
    parent::blockSubmit($form, $form_state);
    $values = $form_state->getValues();
    $this->configuration['enabled'] = $values['enabled'];
    $this->configuration['message'] = $values['message'];
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
  public function build() : array {
    if ($this->configuration['enabled']) {
      return [
        '#theme' => 'cbc_status_bar_block',
        '#message' => [
          '#markup' => $this->configuration['message'],
        ],
      ];
    }
    return [];
  }

}
