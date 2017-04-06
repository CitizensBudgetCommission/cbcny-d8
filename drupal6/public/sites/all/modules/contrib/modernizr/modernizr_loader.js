
(function($) {
  $(function() {
    // adding the no-js class to html
    // in order to make modernizr triggered
    $('html')
      .addClass('modernizr')
      .addClass('no-js');
    // loading modernizr
    $('head').append(
      $('<script></script>')
        .attr('type', 'text/javascript')
        .attr('src', Drupal.settings.basePath + Drupal.settings.modernizrPath)
    );
  });
})(jQuery);