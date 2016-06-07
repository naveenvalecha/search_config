Search Config - http://drupal.org/project/search_config
=======================================================

DESCRIPTION
===========

This module has two core roles, modifying the search form interface and search
restrictions by role per content type.

The first is to provide an easy interface to modify the search forms provided by
core. These include some of the following options:

* Removing the basic search form display if there is an advanced search form present
* To move the basic keywords search field into the advanced form
* Options to override the advanced forms fieldset. These include:
  * Remove the collapsible wrapper and title
  * Force it to stay open, but keep the open look and feel
  * Expand initially, then collapsed during searches
  * Expand initially or when there are zero results during searches
* Label overrides provided for fields. These overrides are still translatable.
* Title display settings for individual fields; above, hidden or below
* Hiding or showing search fields completely or by role
* To repopulate the advanced form fields after a search
* Filter display options on the "Only of the type(s)" field
* Custom content type groupings to make the types filter more UI friendly
  This allows you to specify options like:
  [] Standard pages (ie: page, book,etc)
  [] Personal blogging pages (ie: blog, forum, etc)
  [] All other pages (computed list not including page, book, blog or forum content types)

Some of these features can be mimiced using the Views module and making a view
that replaces the standard search page. However, it would be difficult to
completely mimic all of this modules functionality in a view.

If you require alternative search fields, then views may be your best option.

Modify search functionality by role.

For content types, the approach of this module is to re-write the search query,
so that content is indexed and available as search results to users in role(s)
that have permissions to view it, but not displayed to other roles.

This also updates the "Only of the type(s)" field options.

If you also require content restrictions, then the module that supplies that
functionality should also update the search permissions, so this feature of
this module does not need to be used.


PREREQUISITES
=============
Search module (Drupal core).


INSTALLATION
============
Standard module installation.

See http://drupal.org/node/70151 for further information.
