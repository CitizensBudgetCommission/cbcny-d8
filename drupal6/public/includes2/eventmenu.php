<style>
 #eventselector a { text-decoration: none; }
 .current { color: #f00; }
</style>
<div id="eventselector">
    <?php if ($_REQUEST['q'] == "upcomingevents") { ?><a href="?q=upcomingevents" class="gbold">Upcoming Events</a><?php } else { ?><a href="?q=upcomingevents" class="current">Upcoming Events</a> <?php } ?><br />
    <a href="?q=recentevents">Recent Events</a><br>
</div>