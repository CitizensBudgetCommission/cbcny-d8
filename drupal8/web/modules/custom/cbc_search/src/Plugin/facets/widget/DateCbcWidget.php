<?php

declare(strict_types = 1);

namespace Drupal\cbc_search\Plugin\facets\widget;

use Drupal\Core\Annotation\Translation;
use Drupal\Core\Form\FormStateInterface;
use Drupal\facets\Annotation\FacetsWidget;
use Drupal\facets\FacetInterface;
use Drupal\facets\Plugin\facets\query_type\SearchApiDate;
use Drupal\facets\Plugin\facets\widget\LinksWidget;

/**
 * CBC customized date widget.
 *
 * @FacetsWidget(
 *   id = "datecbc",
 *   label = @Translation("CBC Date checklist"),
 *   description = @Translation("A checklist of dates with a soft limit."),
 * )
 */
class DateCbcWidget extends LinksWidget {

  /**
   * {@inheritdoc}
   */
  public function defaultConfiguration() {
    return [
      'granularity' => SearchApiDate::FACETAPI_DATE_YEAR,
      'soft_limit' => 0,
    ] + parent::defaultConfiguration();
  }

  /**
   * {@inheritdoc}
   */
  public function buildConfigurationForm(array $form, FormStateInterface $form_state, FacetInterface $facet) {
    $form += parent::buildConfigurationForm($form, $form_state, $facet);
    // Add soft limit.
    $options = [50, 40, 30, 20, 15, 10, 5, 3];
    $form['soft_limit'] = [
      '#type' => 'select',
      '#title' => $this->t('Soft limit'),
      '#default_value' => $this->getConfiguration()['soft_limit'],
      '#options' => [0 => $this->t('No limit')] + array_combine($options, $options),
      '#description' => $this->t('Limit the number of displayed facets via JavaScript.'),
    ];

    $soft_limit = (int) $this->getConfiguration()['soft_limit'];
    if ($soft_limit !== 0) {
      $build['#attached']['library'][] = 'facets/soft-limit';
      $build['#attached']['drupalSettings']['facets']['softLimit'][$facet->id()] = $soft_limit;
    }
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function build(FacetInterface $facet) {
    $build = parent::build($facet);
    // Add soft limit.
    $soft_limit = (int) $this->getConfiguration()['soft_limit'];
    if ($soft_limit !== 0) {
      $build['#attached']['library'][] = 'facets/soft-limit';
      $build['#attached']['drupalSettings']['facets']['softLimit'][$facet->id()] = $soft_limit;
    }
    // Add checkboxes.
    $build['#attributes']['class'][] = 'js-facets-checkbox-links';
    $build['#attached']['library'][] = 'facets/drupal.facets.checkbox-widget';

    return $build;
  }

}
