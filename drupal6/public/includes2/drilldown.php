<?php
	include ("correct.php");
	
	$pq = mysql_query ("SELECT * FROM node_type 
						WHERE
						type != 'page' AND
						type != 'blog' AND
						type != 'panel' AND
						type != 'workinprogress' AND
						type != 'event' AND
						type != 'fastfact' AND
						type != 'quote' AND
						type != 'committee'
						ORDER BY name ASC");
	
	?>

      	<div id="drilldown">
        <?
		if ($_REQUEST['menu'] == "pubtype") {
			echo "<span class='gbold'>PUBLICATION TYPE</span><br /><br />";
	
			while ($prow = mysql_fetch_assoc($pq)) {
    		    if ($_REQUEST['q'] == $prow['type']) { ?> <font class="gbold"><?php echo $prow['name']?></font><br /> <?php 
				} else { ?><a href="./?q=<?php echo $prow['type'];?>&menu=<?php echo $_REQUEST['menu']?>"><?php echo $prow['name']?></a><br /> <?php }
			}

		} else if ($_REQUEST['menu'] == "topic") {
			echo "<span class='gbold'>TOPIC</span><br /><br />";
		}

	echo "</div>";

?>
