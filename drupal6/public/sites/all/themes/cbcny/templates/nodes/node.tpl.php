<?php
// $Id: node.tpl.php,v 1.4 2008/09/15 08:11:49 johnalbin Exp $

/**
 * @file node.tpl.php
 *
 * Theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: Node body or teaser depending on $teaser flag.
 * - $picture: The authors picture of the node output from
 *   theme_user_picture().
 * - $date: Formatted creation date (use $created to reformat with
 *   format_date()).
 * - $links: Themed links like "Read more", "Add new comment", etc. output
 *   from theme_links().
 * - $name: Themed username of node author output from theme_user().
 * - $node_url: Direct url of the current node.
 * - $terms: the themed list of taxonomy term links output from theme_links().
 * - $submitted: themed submission information output from
 *   theme_node_submitted().
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $teaser: Flag for the teaser state.
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 */
?>
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

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"><div class="node-inner">
  <?php print $picture; ?>

  <h2 class="title">
    <?php if ($node->field_title_link): ?>
      <?php print l($node->title, $node->field_title_link[0]['url'], array('attributes' => array('target' => '_blank'))); ?>
      <?php if (stripos($node->field_title_link[0]['url'], '.pdf') !== FALSE): ?>
          <?php print theme('image', drupal_get_path('theme', 'cbcny') . '/images/pdf.gif'); ?>
      <?php endif; ?>

    <?php elseif (!$page): ?>
      <a href="<?php print $node_url ;?>"><?php print $node->title; ?></a>
      <?php if ($type == "video"): ?>
          <?php print theme('image', drupal_get_path('theme', 'cbcny') . '/images/video-icon.gif'); ?>
      <?php endif ?>
    <?php else: ?>
      <?php print $node->title; ?>
    <?php endif; ?>
  </h2>

  <?php if ($unpublished): ?>
    <div class="unpublished"><?php print t('Unpublished'); ?></div>
  <?php endif; ?>

  <?php if($node->field_cbc_publish_date): ?>
    <div class="pub-date"><?php $time = strtotime($node->field_cbc_publish_date[0]['value']); print format_date($time, 'custom', 'M d, Y', ''); ?></div>
  <?php endif; ?>

  <div class="content">
    <?php if ($teaser) : ?>
      <div class="teaser">
    <?php endif; ?>

    <?php print $content; ?>

    <?php if ($page == 0 && $node->readmore): ?>
      <div class='read-more'><?php print $read_more_link; ?> </div>
      <?php $node->readmore = false; ?>
    <?php endif; ?>

    <div class="taxonomy">
      <?php print $terms; ?>
    </div>

    <?php if ($teaser) : ?>
      </div>
    <?php endif; ?>
  </div>

  <div class="node-footer">
    <?php if ($service_links_rendered): ?>
      <?php print $service_links_rendered; ?>
    <?php endif; ?>

    <div class="node-title-type <?php print $type; ?>">
      <?php if ($type != 'page'): ?>
        <a href="<?php print $type_url; ?>"><?php print l($type_name, 'browseby/type/' . $type);?></a>
      <?php endif; ?>
    </div>
  </div>

    <div class='admin-inline'>
      <div class='admin-border admin-border-top'></div>
    </div>



</div></div> <!-- /node-inner, /node -->

</div>
      </div>
