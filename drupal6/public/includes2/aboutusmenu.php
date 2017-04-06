<div id="drilldown">
<?php include ("correct.php"); ?>
    <?php if ($_REQUEST['q'] == "node/42") { ?> <font class="gbold">Our Mission</font><br /> <?php } else { ?><a href="<?php echo $corr?>?q=node/42">Our Mission</a><br /><?php } ?>
    <?php if ($_REQUEST['q'] == "node/43") { ?> <font class="gbold">H istory</font><br /> <?php } else { ?><a href="<?php echo $corr?>?q=node/43">History</a><br /><?php } ?>
    <?php if ($_REQUEST['q'] == "") { ?> <font class="gbold">Trustees</font><br /> <?php } else { ?><a href="">Trustees</a><br /><?php } ?>
    <?php if ($_REQUEST['q'] == "node/44") { ?> <font class="gbold">Staff Bios</font><br /> <?php } else { ?><a href="<?php echo $corr?>?q=node/44">Staff Bios</a><br /><?php } ?>
    <?php if ($_REQUEST['q'] == "") { ?> <font class="gbold">Committees</font><br /> <?php } else { ?><a href="">Committees</a><br /><?php } ?>
    <?php if ($_REQUEST['q'] == "node/45") { ?> <font class="gbold">Financials</font><br /> <?php } else { ?><a href="<?php echo $corr?>?q=node/45">Financials</a><br /><?php } ?>
    <?php if ($_REQUEST['q'] == "node/46") { ?> <font class="gbold">Innovation Prize</font><br /> <?php } else { ?><a href="<?php echo $corr?>?q=node/46">Innovation Prize</a><br /><?php } ?>
    <?php if ($_REQUEST['q'] == "node/47") { ?> <font class="gbold">Donate to CBC</font><br /> <?php } else { ?><a href="<?php echo $corr?>?q=node/47">Donate to CBC</a><br /><?php } ?>
    <?php if ($_REQUEST['q'] == "node/48") { ?> <font class="gbold">Jobs and Internships</font><br /> <?php } else { ?><a href="<?php echo $corr?>?q=node/48">Jobs and Internships</a><br /><?php } ?>
    <?php if ($_REQUEST['q'] == "node/49") { ?> <font class="gbold">Resources</font><br /> <?php } else { ?><a href="<?php echo $corr?>?q=node/49">Resources</a><br /><?php } ?>
</div>