// Custom scripts file
// to load, uncomment the call to this file in cbcny_theme.info

(function ($) {

  'use strict';

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

  // add .header-is-fixed class to .page 
  $(window).scroll(function() {
    var value = $(this).scrollTop();
    if (value > 148)
      $(".page").addClass("header-is-fixed");
    else
      $(".page").removeClass("header-is-fixed");
  });

})(jQuery);
