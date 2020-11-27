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
  Drupal.behaviors.anchorScroll = {
    attach: function (context) {
      $(document.body).on('click', 'a[href^="#"]', function (e) {
        e.preventDefault();

        var target = this.hash;
        var $target = $(target);

        $('html, body').stop().animate({
          'scrollTop': $target.offset().top - 60
        }, 900, 'swing');
      });
    }
   }

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
  
  Drupal.behaviors.modalSubscribe = {
    attach: function (context, settings) {

      jQuery(document).ready(function($) {
        if (document.cookie.indexOf("subscribe_modal_cookie") >= 0) {
          // They've been here before. Do Nothing
        }
        else {
          var flagSubscribe = true;
          jQuery(window).on('scroll', function(){
            var windowHeight = jQuery(document).height();
            var currentPosition = jQuery(document).scrollTop();
            var windowViewingArea = jQuery(window).height();
            var bottomScrollPosition = currentPosition + windowViewingArea;
            var percentScrolled = parseInt((bottomScrollPosition / windowHeight * 100).toFixed(0));
            if(percentScrolled >= 50 && flagSubscribe){
              flagSubscribe = false;
              var modal = document.getElementById("subscribeModal");
              modal.style.display = "block";
              var span = document.getElementById("closeSubscribeModal");
              var btn = document.getElementsByClassName("button--subscribe")[0];
              btn.onclick = function() {
                modal.style.display = "none";
              }
              span.onclick = function() {
                modal.style.display = "none";
              }
              window.onclick = function(event) {
                if (event.target == modal) {
                  modal.style.display = "none";
                }
              }
              createCookie("subscribe_modal_cookie", "1", 30);
            }
          })
        }
      })
    }
  }

  function createCookie(name, value, expires) {
    var cookie = name + "=" + escape(value) + ";";
   
    if (expires) {
      // If it's a date
      if(expires instanceof Date) {
        // If it isn't a valid date
        if (isNaN(expires.getTime()))
         expires = new Date();
      }
      else
        expires = new Date(new Date().getTime() + parseInt(expires) * 1000 * 60 * 60 * 24);
   
      cookie += "expires=" + expires.toGMTString() + ";";
    }

    document.cookie = cookie;
  }

})(jQuery);
