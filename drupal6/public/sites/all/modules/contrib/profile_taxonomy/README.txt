Profile Taxonomy README
--------------------------------------------------
Profile Taxonomy enables the usage of taxonomy terms for user profile fields. It extends the "list selection"
profile field type providing the possibility to assign a certain vocabulary. Contained taxonomy term names
are exported and permanently synchronized with the profile field options which can be selected in the user
registration and editing form. Therefore the profile field appears to its consumers, e. g. users or other 
modules, as a usual list selection profile field. 

In fact, the list selection interface stays the same and the data layer is dynamized rather than relying on static
values. This elegant masquerading makes Profile Taxonomy compatible with various themes and other modules, e. g. 
Views or Apache Solr Search Integration . Further it can be nicely integrated with Profile Checkboxes 
(http://drupal.org/project/profile_checkboxes) allowing to associate multiple terms with a profile field.

Profile Taxonomy can be compared to User terms as Content Taxonomy to the core taxonomy module. Although it 
has some limitations as the profile field options can only store values rather than ids which makes the
synchronization, e. g. when a term name is changed, pretty hard. Nevertheless it should work out as long as 
term names within a vocabulary are unique which should apply to the most common cases anyway.

Installation
---------------------------------------------------
You just have to enable this module and dependent modules, i. e. taxonomy and profile. It's 
warmly recommended to use this module in combination with profile_role and profile_checkboxes.

Configuration
---------------------------------------------------
* Go to User Management->Profile (URL: admin/user/profile). 
* Now add/edit a field of the type "list selection"/"selection".
* A new form field "Selection options from vocabulary (advanced)" appears. A selection 
  of a vocabulary will import its term names to the "Selection options". The vocabulary's
  terms are now relevant items for selection in user editing an registration forms.
* Save the administration form.

Usage
---------------------------------------------------
* Go to User Management->Users (URL: admin/user/user) and edit a user or go to the user registration form.
* Go to the profile category/tab of the previously added selection field.
* Now the user should be able to select taxonomy terms from a drop down list.
* Finally save the profile.