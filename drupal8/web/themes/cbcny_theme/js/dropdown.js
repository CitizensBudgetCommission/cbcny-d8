(function ($, Drupal) {

  'use strict';

  Drupal.behaviors.menuDropdown = {
    attach: function (context) {

      $('.js-has-subnav', context).once('menuDropdown').each(function () {
        $(this).hover(function () {
          $(this).children('.js-menu-dropdown').addClass('is-open-menu').wrap('<div class="js-menu-dropdown-wrapper"></div>');
        },
          function () {
            $(this).children('.js-menu-dropdown-wrapper').children('.js-menu-dropdown').unwrap().removeClass('is-open-menu');
          })
      });
    }
  };
})(jQuery, Drupal);
