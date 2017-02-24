/**
 * Add custom click event to facet links.
 *
 * Adds class facet-selected and add/remove item to settings.
 */
Drupal.behaviors.multiple_facet_choice_facet_links = function (context) {
  $('a.apachesolr-facet', context).click(function(){
    // Change class for styles.
    $(this).toggleClass('facet-selected');

    var checkbox = $(this).parent().find('input.facet-checkbox');
    if ($(checkbox).is(':checked')) {
      $(checkbox).attr('checked', false);
    }
    else {
      $(checkbox).attr('checked', true);
    }

    // Parse href to remember the settings.
    var href = $(this).attr('href');
    var href_array = href.split('%20');
    var last_href_element = href_array.pop();
    var last_href_element_array = last_href_element.split('%3A');
    var field = last_href_element_array.shift();
    var value = last_href_element_array.join(':');

    // On the general search page field includes full url. So we should
    // separate key from url.
    var field_array = field.split('=');
    field = field_array.pop();

    // Init array if needed.
    if (typeof(Drupal.settings.multiple_facet_choice_query_filters[field]) == 'undefined') {
      Drupal.settings.multiple_facet_choice_query_filters[field] = [];
    }

    // Save selection to settings.
    Drupal.settings.multiple_facet_choice_query_filters[field][value] = $(this).hasClass('facet-selected');

    // Prevent default click event.
    return false;
  });
}

Drupal.apachesolr.addCheckbox = function() {
  if (!$(this).hasClass('facet-checkbox-processed')) {
    // Put href in context scope to be visible in the anonymous function.
    var href = $(this).attr('href');
    $(this).before($('<input type="checkbox" />')
      .attr('class', 'facet-checkbox')
      .click(function(){
        $(this).parent().find('a').click();
        if ($(this).is(':checked')) {
          $(this).attr('checked', false);
        }
        else {
          $(this).attr('checked', true);
        }
      })
    );
    $(this).addClass('facet-checkbox-processed');
  }
}

Drupal.apachesolr.makeCheckbox = function() {
  // Create a checked checkbox.
  var checkbox = $('<input type="checkbox" />')
    .attr('class', 'facet-checkbox')
    .attr('checked', true);
  // Put href in context scope to be visible in the anonymous function.
  var href = $(this).attr('href');
  checkbox.click(function(){

    // Split current window href to filter pieces.
    var current_href = window.location.href;
    var current_href_array = current_href.split('=');
    var current_filters = current_href_array.pop();
    var current_filters_array = current_filters.split('%20');

    // Split uncheck link href to filter pieces.
    var link_href = $(this).parent().find('a').attr('href');
    var link_href_array = link_href.split('=');
    var link_filters = link_href_array.pop();
    var link_filters_array = link_filters.split('%20');

    // Compare filter arrays and find difference.
    var missing_key = '';
    for (key in current_filters_array) {
      var found = false;
      for (key2 in link_filters_array) {
        if (link_filters_array[key2] == current_filters_array[key]) {
          found = true;
          break;
        }
      }
      if (!found) {
        missing_key = current_filters_array[key];
        break;
      }
    }

    // Missing piece is the filter we should change value in settings value.
    // Split to field, value.
    var last_href_element_array = missing_key.split(':');
    var field = last_href_element_array[0];
    var value = last_href_element_array[1];

    // Init array if needed.
    if (typeof(Drupal.settings.multiple_facet_choice_query_filters[field]) == 'undefined') {
      Drupal.settings.multiple_facet_choice_query_filters[field] = [];
    }

    // Save selection to settings.
    Drupal.settings.multiple_facet_choice_query_filters[field][value] = $(this).hasClass('facet-selected');
  });
  // Add the checkbox, hide the link.
  $(this).before(checkbox).hide();
}

/**
 * Reset and Submit buttons.
 */
Drupal.behaviors.multiple_facet_choice_submit_and_reset = function (context) {
  var submit_button = '<a href="#" class="facets-submit-button">' + Drupal.t('Submit') + '</a>';
  var reset_button = '<a href="#" class="facets-reset-button">' + Drupal.t('Reset') + '</a>';
  // Add links to the bottom of each facet block.
  $(submit_button).appendTo('#block-apachesolr_search-type', context);
  $(reset_button).appendTo('#block-apachesolr_search-type', context);
  $(submit_button).appendTo('#block-apachesolr_search-im_vid_4', context);
  $(reset_button).appendTo('#block-apachesolr_search-im_vid_4', context);
  $(submit_button).appendTo('#block-apachesolr_search-field_cbc_publish_date', context);
  $(reset_button).appendTo('#block-apachesolr_search-field_cbc_publish_date', context);

  // Click event on Reset button.
  $('a.facets-reset-button').click(function(){
    // Prepare reset url. It should include only type:X filter.
    var href = location.href;
    var href_array = href.split('%20');

    var new_href = href_array[0];

    // If we are on the general search page we should remove all filters.
    var position = new_href.indexOf('apachesolr_search');
    if (position != -1) {
      var new_href_array = new_href.split('?');
      new_href = new_href_array[0];
    }

    window.location = new_href;
    return false;
  });

  // Click event on Submit button.
  $('a.facets-submit-button').click(function(){
    console.log(Drupal.settings.multiple_facet_choice_query_filters);
    var filters_string = '';
    for (var field in Drupal.settings.multiple_facet_choice_query_filters) {
      var values_array = Drupal.settings.multiple_facet_choice_query_filters[field];
      for (var value in values_array) {
        if (values_array[value]) {
          filters_string += field + ':' + value + ' ';
        }
      }
    }
    // Prepare url with new filters and redirect.
    var href = location.href;
    var href_array = href.split('?');
    var new_href = href_array[0] + '?filters=' + filters_string;

    window.location = new_href;
    return false;
  });
};
