<?php
/**
 * wssf-fb-block.tpl.php, Jonathan Kissam, jk@webskillet.com, Nov 2013
 *
 * available variables:
 * $posts: list of posts
 * $morelink: link to Facebook page
 * $morelink_text: text for the link to the Facebook page
 */
?>
<ul class="wssf-fb-posts">
	<?php print $posts; ?>
</ul>
<div class="more-link"><a href="<?php print $morelink; ?>"><?php print $morelink_text; ?></a></div>
