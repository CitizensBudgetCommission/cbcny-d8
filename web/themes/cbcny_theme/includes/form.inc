<?php
/**
 * @file
 * Form template functions.
 */

/**
 * Implements template_preprocess_input().
 */
function cbcny_theme_preprocess_input(&$vars) {
  $vars['required'] = $vars['element']['#required'];
  $vars['type'] = $vars['element']['#attributes']['type'];
}
