// Custom scripts file
// to load, uncomment the call to this file in cbcny_theme.info

(function ($) {

  'use strict';

  // Sticky header function initiates sticky header and sets top offset.
  function stickyHeader() {
    var myOffset = 0;

    if ($("body").hasClass("toolbar-fixed")) {
      myOffset = 39;
      if ($("body").hasClass("toolbar-horizontal")) {
        myOffset = 80;
      }
    }
    $(".region-navigation").stick_in_parent({offset_top: myOffset});
  }

  Drupal.behaviors.stickyStuff = {
    attach: function (context, settings) {

      // Initiate sticky header after initial page load.
      $(window).bind("load", function() {
        stickyHeader();
      });
    }
  }

  Drupal.behaviors.slick = {
    attach: function (context, settings) {
      $('.slick-carousel').slick({
        infinite: false,
        slidesToShow: 4,
        slidesToScroll: 4,
        responsive: [
          {
            breakpoint: 650,
            settings: {
              slidesToShow: 3
            }
          },
          {
            breakpoint: 500,
            settings: {
              slidesToShow: 2
            }
          },
          {
            breakpoint: 360,
            settings: {
              slidesToShow: 1
            }
          }
        ]
      });
    }
  }

  // Generic function that runs on window resize.
  function resizeStuff() {
    // mosaicGrid();

    // Recalibrate sticky header.
    $(document.body).trigger("sticky_kit:recalc");
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


  // Dropdown functionality
  Drupal.behaviors.toggleDropdowns = {
    attach: function (context, settings) {
      $('.dropdown-button').on(click, function() {
        $(this).parent('.dropdown').toggleClass('.is-active').children('.dropdown__options').toggleClass('.is-hidden');
      });
    }
  };
})(jQuery);
