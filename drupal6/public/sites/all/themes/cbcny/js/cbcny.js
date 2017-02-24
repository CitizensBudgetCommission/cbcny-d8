Drupal.behaviors.searchBox = function(context) {

  var text = 'Search on CBC';

  var elems = [
      $(context).find('#edit-search-theme-form-1'),
      $(context).find('#edit-keys')
  ];
    if (elems.length > 0) {
        for (var i = 0; i < elems.length; i++) {
            if (elems[i].length > 0) {
                var elem = elems[i];
                if (!elem[0].value) {
                    $(elem).val(text);

                    $(elem).blur(function (e) {
                        if ($(this).val() == '') {
                            $(this).val(text);
                        }
                    });

                    $(elem).focus(function (e) {
                        if ($(this).val() == text) {
                            $(this).val('');
                        }
                    });
                }
            }
        }
    }
}

Drupal.behaviors.newsletterBlock = function(context) {

  var elems = $(context).find('.block #webform-client-form-349 .form-text');

  elems.each(function() {
    var text = $(this).attr('title');

    $(this).val(text);

    $(this).blur(function(e) {
      if ($(this).val() == '') {
        $(this).val(text);
      }
    });

    $(this).focus(function(e) {
      if ($(this).val() == text) {
        $(this).val('');
      }
    });
  });

  $(context).find('.block #webform-client-form-349').submit(function(e) {
    $(this).find('input').each(function() {
      if ($(this).val() == $(this).attr('title')) {
        $(this).val('');
      }
    });
  });
}

Drupal.behaviors.dropMenu = function(context) {
  $('#navigation li.expanded').hover(function() {
    $(this).addClass('hover');
  }, function() {
    $(this).removeClass('hover');
  });
}

