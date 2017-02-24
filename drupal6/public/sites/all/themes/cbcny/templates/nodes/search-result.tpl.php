<?php

/**
 * @file search-result.tpl.php
 * Default theme implementation for displaying a single search result.
 *
 * This template renders a single search result and is collected into
 * search-results.tpl.php. This and the parent template are
 * dependent to one another sharing the markup for definition lists.
 *
 * Available variables:
 * - $url: URL of the result.
 * - $title: Title of the result.
 * - $snippet: A small preview of the result. Does not apply to user searches.
 * - $info: String of all the meta information ready for print. Does not apply
 *   to user searches.
 * - $info_split: Contains same data as $info, split into a keyed array.
 * - $type: The type of search, e.g., "node" or "user".
 *
 * Default keys within $info_split:
 * - $info_split['type']: Node type.
 * - $info_split['user']: Author of the node linked to users profile. Depends
 *   on permission.
 * - $info_split['date']: Last update of the node. Short formatted.
 * - $info_split['comment']: Number of comments output as "% comments", %
 *   being the count. Depends on comment.module.
 * - $info_split['upload']: Number of attachments output as "% attachments", %
 *   being the count. Depends on upload.module.
 *
 * Since $info_split is keyed, a direct print of the item is possible.
 * This array does not apply to user searches so it is recommended to check
 * for their existance before printing. The default keys of 'type', 'user' and
 * 'date' always exist for node searches. Modules may provide other data.
 *
 *   <?php if (isset($info_split['comment'])) : ?>
 *     <span class="info-comment">
 *       <?php print $info_split['comment']; ?>
 *     </span>
 *   <?php endif; ?>
 *
 * To check for all available data within $info_split, use the code below.
 *
 *   <?php print '<pre>'. check_plain(print_r($info_split, 1)) .'</pre>'; ?>
 *
 * @see template_preprocess_search_result()
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

    <div class="node-inner">
      <dt class="title">
        <a href="<?php print $url; ?>"><?php print $title; ?></a>
      </dt>
      <dd>
        <?php if ($cbc_publish_date) : ?>
          <div class="pub-date"><?php print $cbc_publish_date ?></div>
        <?php endif; ?>
        <div class="content">
          <?php if ($snippet) : ?>
            <p class="search-snippet"><?php print $snippet; ?></p>
          <?php endif; ?>
          <div class="taxonomy">
            <?php print $terms; ?>
          </div>
        </div>
        <div class="node-title-type <?php print $info_split['type']; ?>">
          <?php if ($info_split['type'] != 'Page'): ?>
            <?php print l($info_split['type'], 'browseby/type/' . $info_split['type']);?></a>
        <?php endif; ?>
        </div>
      </dd>
    </div>

  </div>

</div>