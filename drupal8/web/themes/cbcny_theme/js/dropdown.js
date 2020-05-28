(function ($, Drupal) {

  'use strict';

  Drupal.behaviors.menuDropdown = {
    attach: function (context) {

      $('.js-has-subnav', context).once('menuDropdown').each(function () {
        $(this).hover(function () {
          $(this).children('.js-menu-dropdown').addClass('is-open-menu');
        },
          function () {
            $(this).children('.js-menu-dropdown').removeClass('is-open-menu');
          })
      });
    }
  };
})(jQuery, Drupal);
