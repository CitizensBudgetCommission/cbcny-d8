<?php

// $Id: page.tpl.php,v 1.10.2.4 2009/02/13 17:30:22 johnalbin Exp $

/**
 * @file page.tpl.php
 *
 * Theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $css: An array of CSS files for the current page.
 * - $directory: The directory the theme is located in, e.g. themes/garland or
 *   themes/garland/minelli.
 * - $is_front: TRUE if the current page is the front page. Used to toggle the mission statement.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Page metadata:
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $head_title: A modified version of the page title, for use in the TITLE tag.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $body_classes: A set of CSS classes for the BODY tag. This contains flags
 *   indicating the current layout (multiple columns, single column), the current
 *   path, whether the user is logged in, and so on.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 * - $mission: The text of the site mission, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $search_box: HTML to display the search box, empty if search has been disabled.
 * - $primary_links (array): An array containing primary navigation links for the
 *   site, if they have been configured.
 * - $secondary_links (array): An array containing secondary navigation links for
 *   the site, if they have been configured.
 *
 * Page content (in order of occurrance in the default page.tpl.php):
 * - $left: The HTML for the left sidebar.
 *
 * - $breadcrumb: The breadcrumb trail for the current page.
 * - $title: The page title, for use in the actual HTML content.
 * - $help: Dynamic help text, mostly for admin pages.
 * - $messages: HTML for status and error messages. Should be displayed prominently.
 * - $tabs: Tabs linking to any sub-pages beneath the current page (e.g., the view
 *   and edit tabs when displaying a node).
 *
 * - $content: The main content of the current Drupal page.
 *
 * - $right: The HTML for the right sidebar.
 *
 * Footer/closing data:
 * - $feed_icons: A string of all feed icons for the current page.
 * - $footer_message: The footer message as defined in the admin settings.
 * - $footer : The footer region.
 * - $closure: Final closing markup from any modules that have <ered the page.
 *   This variable should always be output last, after all other dynamic content.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">

<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $body_classes; ?>">


  <div id="page">
    <div id="header">
    <div class="top-bar">
      <?php if (!empty($secondary_links)): ?>
			<div id="menu-secondary">
				<div class="seconday-menu-items">
				<?php print theme('links', $secondary_links); ?>
				</div>
			</div>
			<?php endif; ?>
    </div>
     
      <div id="skip-nav"><a href="#content"><?php print t('Skip to Main Content'); ?></a></div>

      <div id="logo-title">
				<div class="site-name"><?php print $site_name ?></div>
				<div class="logo-bg-div" style="background:url('<?php echo $logo?>') no-repeat;">
					<div class="logo-link"><a href="<?php print url('<front>'); ?>"></a></div>
					
					<?php print $user_links ?>
					<?php print $search_box; ?>
					
				</div>
			 
      </div> <!-- /logo-title -->
      <div id="navigation" style="margin-top:0px;" class="menu<?php if ($primary_links) { print " withprimary"; } if ($secondary_links) { print " withsecondary"; } ?> ">
        <?php if (!empty($primary_links)): ?>
				<div id="primary-menu-links">
					<?php print $primary_links; ?>
				</div>
        <?php endif; ?>

      </div> <!-- /navigation -->

      <?php if (!empty($header) || !empty($breadcrumb)): ?>
        <div id="header-region">
          <?php //print $breadcrumb; ?>
          <?php print $header; ?>
        </div> <!-- /header-region -->
      <?php endif; ?>

    </div> <!-- /header -->

   	<?php if ($user->uid) { ?> <div id="container" style="background:#eaf5e4;"> 
    <?php } else { ?> <div id="container" class="clear-block">  <?php } ?>
    
    <div class="sidebar-left">
    	<?php echo $left?>
    </div>
    
    <?php if (!empty($right)) { ?>
    <div class="login-with-right">
<?php } else { ?>
    <div class="login-without-right">
    <?php } ?>
		<?php if (!empty($title)): ?>
            <!--<h1 class="title"><?php print $title; ?></h1>-->
          <?php endif; ?>
          <?php print $help; ?>
      <div class="Block">
        <div class="Block-tl"></div>
        <div class="Block-tr"><div></div></div>
        <div class="Block-bl"><div></div></div>
        <div class="Block-br"><div></div></div>
        <div class="Block-tc"><div></div></div>
        <div class="Block-bc"><div></div></div>
        <div class="Block-cl"><div></div></div>
        <div class="Block-cr"><div></div></div>
        <div class="Block-cc"></div>
        <div class="Block-body">
          <?php if ($block->subject): ?>
          <div class="BlockHeader">
              <div class="header-tag-icon">
              </div>
              <div class="l"></div>
              <div class="r"><div></div></div>
          </div>
        <?php endif; ?>		
        <div class="BlockContent">
          <div class="BlockContent-body">
            <p>Only Trustee Members who have been issued user names and passwords
            from CBC will be able to access the secure Trustee Area of this website.</p>
            <p>If you are a Trustee, please enter in your username and password below.</p>
            <?php print $content; ?>
            <?php print l(t('Forgot Password?'), 'user/password'); ?>
          </div>
        </div>
        <?php echo $edit_links; ?>
        </div>
      </div>
          
     </div>
     
     <div class="sidebar-right">
     	<?php print $right; ?>
     </div>
     
     <div style="clear:both;"></div>
    
    </div> <!-- container end -->

    <?php if ($footer || $footer_message): ?>
      <div id="footer-wrapper"><div id="footer">

        <?php if ($footer_message): ?>
          <div id="footer-message"><?php print $footer_message; ?></div>
        <?php endif; ?>

        <?php print $footer; ?>
	<?php print $feed_icons; ?>
      </div></div> <!-- /#footer, /#footer-wrapper -->
    <?php endif; ?>

  </div> <!-- /page -->

  <?php if ($closure_region): ?>
    <div id="closure-blocks"><?php print $closure_region; ?></div>
  <?php endif; ?>

  <?php print $closure; ?>
</div>
</body>
</html>
