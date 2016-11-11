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

  // Smooth scrolling to in-page anchor
  $(document).ready(function(){
    $('a[href^="#"]').on('click',function (e) {
        e.preventDefault();

        var target = this.hash;
        var $target = $(target);

        $('html, body').stop().animate({
          'scrollTop': $target.offset().top
        }, 900, 'swing');
    });
  });

  Drupal.behaviors.gessoTOC = {
    attach: function (context) {

      if ( $(".section--type-section-heading h2").length ) {

        var toc = "";
        var newLine, el, title, link;

        $(".section--type-section-heading h2").each(function() {

          el = $(this);
          title = el.text();
          link = "#" + encodeURIComponent(el.attr("id"));
          newLine = "<a class='nav__item' href='" + link + "'>" + title + "</a>";
          toc += newLine;

        });


        console.log(toc);
        $(".nav--toc__menu").prepend(toc);
        $(".section--toc").show();

      }

      $('.toc-button').click(function(event) {
        $('.toc-button').hide();
        $('.nav--toc').slideToggle("fast");
        event.preventDefault(event);
      });

      $('.close-toc').click(function(event) {
        $('.nav--toc').hide();
        $('.toc-button').show();
        event.preventDefault(event);
      });

    }
  }
})(jQuery);
