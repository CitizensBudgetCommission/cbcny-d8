<?php

declare(strict_types = 1);

namespace Drupal\cbc_status_bar\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * CBC Status Bar config form.
 *
 * @package Drupal\cbc_status_bar\Form
 */
class ConfigForm extends ConfigFormBase {

  /**
   * {@inheritdoc}
   */
  public function getFormId() : string {
    return 'cbc_status_bar_config';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() : array {
    return ['cbc_status_bar.settings'];
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $config = $this->config('cbc_status_bar.settings');

    $form['enabled'] = [
      '#type' => 'checkbox',
      '#title' => $this->t('Enable the status bar'),
      '#description' => $this->t('When checked, the status bar will be displayed on all pages.'),
      '#default_value' => $config->get('enabled'),
    ];

    $form['message'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Message'),
      '#description' => $this->t("The message to display. May include HTML."),
      '#default_value' => $config->get('message'),
    ];

    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    parent::submitForm($form, $form_state);
    $config = $this->config('cbc_status_bar.settings');
    $config->set('enabled', $form_state->getValue('enabled'));
    $config->set('message', $form_state->getValue('message'));
    $config->save();
  }

}
