<?php
/**
 * wssf-twitter-tweet.tpl.php, Jonathan Kissam, jk@webskillet.com, Nov 2013
 *
 * available variables:
 * $user: twitter username
 * $name: twitter name
 * $avatar: URL of twitter avatar
 * $tweet_id: numerical id of tweet
 * $retweet: line indicating a retweet
 * $timestamp: post date of tweet (by default, shows today's tweets as "3m ago", "4h ago", etc.
 * $tweet: tweet, with hashtags, mentions and URLs hyperlinked
 * $tweet_plain: tweet in plain text
 */
?>
<li class="wssf-tweet">
	<div class="wssf-tweet-author">
		<a href="https://twitter.com/<?php print $user; ?>" title="<?php print $name; ?>"><img class="wssf-tweet-avatar" src="<?php print $avatar; ?>" alt="<?php print $name; ?>" /></a>
		<span class="wssf-tweet-author-name"><a href="https://twitter.com/<?php print $user; ?>"><?php print $name; ?></a></span>
		<span class="wssf-tweet-author-user"><a href="https://twitter.com/<?php print $user; ?>">@<?php print $user; ?></a></span>
	</div>
	<div class="wssf-tweet-timestamp"><a href="https://twitter.com/<?php print $user; ?>/statuses/<?php print $id; ?>"><?php print $timestamp; ?></a></div>
	<div class="wssf-tweet-tweet"><?php print $tweet; ?></div>
	<?php print $retweet; ?>
	<ul class="wssf-tweet-actions">
		<li class="wssf-tweet-action-reply"><a href="https://twitter.com/intent/tweet?in_reply_to=<?php print $tweet_id; ?>" title="Reply">Reply</a></li>
		<li class="wssf-tweet-action-retweet"><a href="https://twitter.com/intent/retweet?tweet_id=<?php print $tweet_id; ?>" title="Retweet">Retweet</a></li>
		<li class="wssf-tweet-action-favorite"><a href="https://twitter.com/intent/favorite?tweet_id=<?php print $tweet_id; ?>" title="Favorite">Favorite</a></li>
	</ul>
</li>
