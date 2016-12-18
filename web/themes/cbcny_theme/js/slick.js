// Custom scripts file
// to load, uncomment the call to this file in cbcny_theme.info

(function ($) {

  'use strict';

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

})(jQuery);
