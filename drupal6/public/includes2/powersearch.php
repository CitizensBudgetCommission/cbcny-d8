<form method="get" action="./?q=searchresults">
<input type="text" name="psearch" value="" style="width:150px;margin-bottom:5px;" >
<table>
<tr>
	<td colspan="2"><select name="topic" style="width:150px;margin-bottom:5px;">
			<option selected value="all">TOPIC</option>
			<?php
				$tree = taxonomy_get_tree(4);
				foreach($tree as $k => $term) {
					if($term->parents[0] != 0) {
						print '<option value="' . $term->tid . "'>" . $term->name . '</option>';
					}
					else {
						print '<option value="' . $term->tid . "'>-" . $term->name . '</option>';
					}
				}
			?>
		</select>
    </td>
</tr><tr>
	<td colspan="2"><select name="pubtype" style="width:150px;margin-bottom:5px;">
		<option selected value="all">PUBLICATION TYPE</option>
    	<?
		$pq = db_query ("SELECT * FROM {node_type}
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
	
		while ($row = db_fetch_array($pq)) {
			?><option value="<?php echo $row['type']?>"><?php echo $row['name']?></option><?	
		}	
		?>    
		</select>
	</td>
</tr><tr>
	<td><select name="year"style="width:70px;margin-bottom:5px;">
		<option selected value="all">YEAR</option>
		<?php 
			$startyear = "2005";
			$currentyear = date("Y");
			$year = $currentyear;
			while ($year >= $startyear) {
				?><option value="<?php echo $year?>"><?php echo $year?></option><?
			$year = $year - 1;
			}
		?>
		</select>
    </td>
	<td><select name="month" style="width:77px;margin-bottom:5px;">
	<option selected value="all">MONTH</option>
    <option value="01">Jan</option>
    <option value="02">Feb</option>
    <option value="03">Mar</option>
    <option value="04">Apr</option>
    <option value="05">May</option>
    <option value="06">Jun</option>
    <option value="07">Jul</option>
    <option value="08">Aug</option>
    <option value="09">Sep</option>
    <option value="10">Oct</option>
    <option value="11">Nov</option>
    <option value="12">Dec</option>
	</select>
    </td>
</tr><tr>
	<td align="right" colspan="2"><input type="submit" value="GO"></td>
</tr>
</table>

</form>