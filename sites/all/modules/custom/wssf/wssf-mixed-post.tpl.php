<?php
/**
 * wssf-mixed-post.tpl.php, Jonathan Kissam, jk@webskillet.com, Nov 2013
 *
 * available variables:
 * $link: link to FB post (on Facebook)
 * $title: title or first complete paragraph if official "FB" title is truncated
 * $title_plain: title with HTML tags stripped
 * $content: entire content of the post
 * $content_plain: entire content of the post with HTML tags stripped
 * $timestamp: formatted display of post date
 */
?>
<li class="wssf-mixed-post wssf-mixed-fb">
	<?php if (strpos($title,'<a href') === false): ?>
		<a href="<?php print $link; ?>"><?php print $title_plain; ?></a>
	<?php else: ?>
		<?php print $title; ?>
	<?php endif; ?>
</li>
