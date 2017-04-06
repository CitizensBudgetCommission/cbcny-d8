<?php

//die(print_r(get_defined_vars(),1));
//print_r($variables['account']->picture);

$profObj = (object) $variables['account'];
?>
<div class="image">
<?php if ($account->picture): ?>
<pre><?php print theme('imagecache', 'profile_pic', $account->picture, $alt, $title, $attributes); ?> </pre>
<?php else: ?>
<p class="nophoto">No photo</p>
<?php endif; ?>
</div>

<div class="info">
	<h1><?php print "$profObj->profile_fname $profObj->profile_lname"; ?></h1>
	<div class="position"><?php print $profObj->profile_position; ?></div>
	<div class="firm"><?php print $profObj->profile_firm; ?></div>

	
	<!-- div class="heading since">Trustee since ???<?php //print date("Y", $profObj->created); ?></div-->
	
  <?php if(!empty($profObj->profile_bio)): ?>
	<div><?php print $profObj->profile_bio; ?></div>
  <?php endif; ?>
	
  <?php if(!empty($profObj->profile_occind)): ?>
	<div class="heading">Occupation/Industry</div>
	<div><?php print $profObj->profile_occind; ?></div>
  <?php endif; ?>
	
  <?php if(!empty($profObj->profile_education)): ?>
	<div class="heading">Education</div>
	<div><?php print $profObj->profile_education; ?></div>
  <?php endif; ?>
	
  <?php if(!empty($profObj->profile_address1)): ?>
	<div class="heading">Contact</div>
	<div><?php print $profObj->profile_address1; ?><br />
	<?php if (!empty($profObj->profile_address2)) print "$profObj->profile_address2<br />"; ?>
	<?php print "$profObj->profile_city"; ?>, <?php print "$profObj->profile_state"; ?> <?php print "$profObj->profile_zip"; ?>
	</div>
  <?php endif; ?>
	
  <?php if(!empty($profObj->profile_workphone)): ?>
	<div class="noheading"><span class="heading">W</span><?php print "$profObj->profile_workphone"; ?><br />
	<span class="heading">C</span><?php print "$profObj->profile_cellphone"; ?></div>
  <?php endif; ?>
	
  <?php if(!empty($profObj->profile_email)): ?>
	<div class="heading">Email</div>
	<div><?php print $profObj->profile_email; ?></div>
  <?php endif; ?>
	
  <?php if(!empty($profObj->profile_website)): ?>
	<div class="heading">Website</div>
	<div><?php print $profObj->profile_website; ?></div>
  <?php endif; ?>
	
	
</div>
