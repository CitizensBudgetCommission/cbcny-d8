<?php

/**
 * Implementation of hook_strongarm().
 */
function cbc_text_handling_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'htmLawed_format_2';
  $strongarm->value = array(
    'config' => '\'safe\'=>1, \'elements\'=>\'a, em, strong, b, blockquote, embed, object, table, td, tr, cite, code, ol, ul, li, dl, dt, dd, img, br, p, hr, h1, h2, h3, div, iframe, script, thead, th, cdata\'',
    'spec' => '',
    'help' => 'Tags allowed: a, em, strong, b, blockquote, embed, object, table, td, tr, cite, code, ol, ul, li, dl, dt, dd, img, br, p, hr, h1, h2, h3, div, iframe, blockquote, script, thead, th, cdata',
  );
  $export['htmLawed_format_2'] = $strongarm;

  return $export;
}
