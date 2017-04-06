<?php
// $Id: views-view-summary-unformatted.tpl.php,v 1.2.4.1 2010/03/16 23:12:31 merlinofchaos Exp $
/**
 * @file views-view-summary-unformatted.tpl.php
 * Default simple view template to display a group of summary lines
 *
 * This wraps items in a span if set to inline, or a div if not.
 *
 * @ingroup views_templates
 */
?>
<?php foreach ($rows as $id => $row): ?>
  <?php if (!empty($options['count'])) {
    $level = ceil($row->count/2);
    $level = ($level > 10) ? 10 : $level;
    $class = 'tagcloud-' . $level;
  }?>
  <?php print (!empty($options['inline']) ? '<span' : '<div') . ' class="views-summary views-summary-unformatted ' . $class . '">'; ?>
    <?php if (!empty($row->separator)) { print $row->separator; } ?>
    <a href="<?php print $row->url; ?>"<?php print !empty($classes[$id]) ? ' class="'. $classes[$id] .'"' : ''; ?>><?php print $row->link; ?></a>
  <?php print !empty($options['inline']) ? '</span>' : '</div>'; ?>
<?php endforeach; ?>
