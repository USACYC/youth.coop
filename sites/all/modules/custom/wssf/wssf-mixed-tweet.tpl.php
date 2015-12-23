<?php
/**
 * wssf-mixed-tweet.tpl.php, Jonathan Kissam, jk@webskillet.com, Nov 2013
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
<li class="wssf-mixed-post wssf-mixed-tweet"><?php print $tweet; ?></li>
