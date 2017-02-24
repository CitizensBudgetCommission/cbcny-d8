<form method="get" action="./?q=searchresults">
  <table width="98%" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td>Filter by:</td>
    <td><select name="topic" >
			<option selected value="all">TOPIC</option>
		</select>
    </td>
    <td>
    <select name="year">
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
    <td>
    <select name="month" >
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
    
    <input type="submit" value="GO">
    </td>
    
  </tr>
</table>


</form>