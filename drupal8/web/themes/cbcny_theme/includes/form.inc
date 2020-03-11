<?php
/**
 * @file
 * Form template functions.
 */

/**
 * Implements template_preprocess_fieldset().
 */
function cbcny_theme_preprocess_fieldset(&$vars) {
  $vars['type'] = isset($vars['element']['#type']) ? $vars['element']['#type'] : NULL;
}

/**
 * Implements template_preprocess_input().
 */
function cbcny_theme_preprocess_input(&$vars) {
  $vars['required'] = isset($vars['element']['#required']) ? $vars['element']['#required'] : $vars['required'];
  $vars['type'] = isset($vars['element']['#attributes']['type']) ? $vars['element']['#attributes']['type'] : NULL;
}
