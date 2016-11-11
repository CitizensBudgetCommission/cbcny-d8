// Custom scripts file
// to load, uncomment the call to this file in cbcny_theme.info

(function ($) {

  'use strict';

  Drupal.behaviors.stickyStuff = {
    attach: function (context, settings) {
      // Initiate sticky header after initial page load.
      $(window).bind("load", function() {
        if ($("body:not(.user-logged-in)")) {
          $(".region-navigation").stick_in_parent();
        }
      });
    }
  }

  // Generic function that runs on window resize.
  function resizeStuff() {
    // mosaicGrid();
  }

  // Runs function once on window resize.
  var TO = false;
  $(window).resize(function () {
    if (TO !== false) {
      clearTimeout(TO);
    }

    // 200 is time in miliseconds.
    TO = setTimeout(resizeStuff, 200);
  }).resize();

})(jQuery);
