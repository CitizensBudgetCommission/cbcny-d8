// $Id: profile_taxonomy.js,v 1.2 2010/12/30 15:10:58 gnindl Exp $

/**
 * @file profile_taxonomy.js
 * Exports taxonomy terms to profile field options according to the profile_taxonomy form settings. 
 */

Drupal.profile_taxonomy = Drupal.profile_taxonomy || {};

/**
 * Event triggers react on profile field form changes.
 * @param context
 *   DOM context
 */
Drupal.behaviors.ProfileTaxonomy = function(context) {

  //vocabulary selection
  $('#edit-vocabulary:not(.profile-taxonomy-processed)', context) 
    .change(function(event) {Drupal.profile_taxonomy.exportTerms(this, context);})
    .addClass('profile-taxonomy-processed');
  
  //parent term selection
  $('#edit-parent-term:not(.profile-taxonomy-processed)', context) 
	.change(function(event) {Drupal.profile_taxonomy.exportTerms(this, context);})
	.addClass('profile-taxonomy-processed');

  //option for formatting vocabulary as hierarchy
  $('#edit-show-depth:not(.profile-taxonomy-processed)', context) 
	.change(function(event) {Drupal.profile_taxonomy.exportTerms(this, context);})
	.addClass('profile-taxonomy-processed');

  //option for limiting the hierarchy level
  $('#edit-depth:not(.profile-taxonomy-processed)', context) 
	.change(function(event) {Drupal.profile_taxonomy.exportTerms(this, context);})
	.addClass('profile-taxonomy-processed');
  
  $('#edit-options').attr('disabled', 'disabled'); //make options list uneditable now
};

/**
 * Exports taxonomy terms to the options textarea.
 * @param widget
 *   form widget
 * @param $context
 *   DOM context
 */
Drupal.profile_taxonomy.exportTerms = function(widget, context) {
  var vid = $('#edit-vocabulary', context).val();
  if (vid != 0) {
	//if vocabulary has changed, reset parent term list
    var tid = $(widget).attr('id') != 'edit-vocabulary' ? $('#edit-parent-term option:selected').val() : 0;
    var show_depth = $('#edit-show-depth:checked').val() ? 1 : 0; //flags for level indents
    var max_depth = $('#edit-depth').val(); //hierarchy level limit
    
    //construct URL with arguments
    var path = Drupal.settings.profile_taxonomy['path'] + '/' + vid + '/' + tid + '/' + show_depth + '/' + max_depth;
	
    //call server retrieving list of terms
    $.getJSON(path, function(data, textStatus) {
      //data object consists of two subarrays "keys" and "values"
      $('#edit-options').val(data['values'].join("\r\n")); //explode response, e. g. array(1, 2) to 1\r\n2\r\n
  	  $('#edit-options').attr('disabled', 'disabled'); //make options list uneditable now
  	  
  	  //reset parent term list except for first option (no selection)
  	  if (parseInt(tid) == 0 || $(widget).attr('id') == 'edit-vocabulary') { 
  	    $('#edit-parent-term').children(":not(option:first)").remove().end();
  	    //attach term as options
  	    for ($i = 0; $i < data['keys'].length; $i++) { 
  	      $('#edit-parent-term').
            append($("<option></option>").
            attr("value",data['keys'][$i]).
            text(data['values'][$i]));
		}
  	  }
  	});
  }
  else { //no vocabulary selection, fall back into standard mode
	$('#edit-options').removeAttr('disabled');
  	$('#edit-options').val(''); 
  	$('#edit-parent-term').children(":not(option:first)").remove().end();
  }
};