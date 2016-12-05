// Custom scripts file
// to load, uncomment the call to this file in cbcny_theme.info

(function ($) {

  'use strict';

  Drupal.behaviors.stickyStuff = {
    attach: function (context, settings) {
      // Initiate sticky header after initial page load.
      $(window).bind("load", function() {
        if ($("body:not(.user-logged-in)")) {
          $(".region-navigation").stick_in_parent({sticky_class: 'is-stuck'});

        }
      });
    }
  }

  Drupal.behaviors.slick = {
    attach: function (context, settings) {
      $('.slick-carousel-topics').slick({
        infinite: false,
        slidesToShow: 4,
        slidesToScroll: 4,
        responsive: [
          {
            breakpoint: 991,
            settings: {
              slidesToShow: 3,
              slidesToScroll: 3
            }
          },
          {
            breakpoint: 800,
            settings: {
              slidesToShow: 2,
              slidesToScroll: 2
            }
          },
          {
            breakpoint: 600,
            settings: {
              slidesToShow: 1,
              slidesToScroll: 1
            }
          }
        ]
      });
      $('.slick-carousel-homepage').slick({
        infinite: false,
        dots: true
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

  // Dropdown functionality
  Drupal.behaviors.toggleDropdowns = {
    attach: function (context, settings) {
      $('.dropdown').children('.dropdown__options').addClass('hidden');
      $('.button--dropdown').on('click', function() {
        $(this).parent('.dropdown').toggleClass('is-active').children('.dropdown__options').toggleClass('hidden');
      });
    }
  };

  // Smooth scrolling to in-page anchor
  $(document).ready(function(){
    $('a[href^="#"]').on('click',function (e) {
        e.preventDefault();

        var target = this.hash;
        var $target = $(target);

        $('html, body').stop().animate({
          'scrollTop': $target.offset.top
        }, 900, 'swing');
    });
  });

  Drupal.behaviors.gessoTOC = {
    attach: function (context) {

      $(".section--toc").hide();

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

        $(".nav--toc__menu").prepend(toc);
        $(".section--toc").show();

      }

      $('.button--toc').click(function(event) {
        $('.button--toc').hide();
        $('.nav--toc').slideToggle("fast");
        event.preventDefault(event);
      });

      $('.close-toc').click(function(event) {
        $('.nav--toc').hide();
        $('.button--toc').show();
        event.preventDefault(event);
      });
    }
  }

})(jQuery);
