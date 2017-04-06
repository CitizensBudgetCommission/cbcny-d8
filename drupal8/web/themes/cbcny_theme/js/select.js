(function ($, Drupal) {

  'use strict';

  Drupal.behaviors.select = {
    attach: function (context) {
      // Don’t use selectability.js on selects that allow multiple values.
      $('select:not([multiple])', context).selectability();
    }
  };
})(jQuery, Drupal);
