Introduction
============

The Deck module allows you to use a CCK field as node teaser. It's an
alternative to CCK Teaser [1], CCK Teaser Field [2] and to some extend
Excerpt [3].

Its advantage over CCK Teaser and CCK Teaser Field is that the
teaser is stored in the node teaser, which means that it works with
other modules that work with the node teaser. Deck also falls back to
generating a teaser from the node body, if the field is empty, using
the fields maximum length as the maximum teaser length, falling back
to the setting of Administer > Content management > Post settings.

Excerpt has the advantage of being able to set the filter used for the
teaser (though this might be implemented in a later version of Deck),
and not being dependent on CCK. However, being able to use the CCK
field used for teaser as the deck (or subhead) when viewing the full
node was one of the motivations behind this module.

[1] http://drupal.org/project/cck_teaser
[2] http://drupal.org/project/cck_teaser_field
[3] http://drupal.org/project/excerpt

Usage
=====

Install and enable the module, and configure it under Administer >
Content management > Content types > [node type]. The available text
fields are listed under Submission form settings, along with options
for dealing with HTML tags in the body, if falling back to that.

Author / maintainer
===================
Thomas Fini Hansen (aka Xen on Drupal.org)
xen at xen dot dk
Developed at Peytz & Co.
http://peytz.dk/
