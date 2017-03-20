<div id="drilldown">
<?php
	$picnum = rand(1,8);
	switch($picnum) {
		case 1: $img = "cbc_aboutus_1.jpg"; break;
		case 2: $img = "cbc_aboutus_2.jpg"; break;
		case 3: $img = "cbc_aboutus_3.jpg"; break;
		case 4: $img = "cbc_aboutus_4.jpg"; break;
		case 5: $img = "cbc_aboutus_5.jpg"; break;
		case 6: $img = "cbc_aboutus_6.jpg"; break;
		case 7: $img = "cbc_aboutus_7.jpg"; break;
		case 8: $img = "cbc_aboutus_8.jpg"; break;
	}
	$img = theme('image', 'images/about/' . $img);
?>
<?php print $img; ?>
<!--img src="images/about/<?php echo $img?>" style="margin-left:-8px;" /-->

<table>
<tr><td>"an influential, nonpartisan watchdog group"</td></tr>
<tr><td align="right"><em>~The Wall Street Journal</em></td></tr>
</table>

<br />

<table>
<tr><td>"a prominent organization that studies government finances"</td></tr>
<tr><td align="right"><em>~The New York Times</em></td></tr>
</table>

<br />

<table>
<tr><td>"one of the oldest and most respected independent fiscal watchdog groups in the country"</td></tr>
<tr><td align="right"><em>~The Bond Buyer</em></td></tr>
</table>
</div>
