<!DOCTYPE html>
<!--[if lt IE 7]>      <html class="no-js lt-ie9 lt-ie8 lt-ie7" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>" xmlns:og="http://opengraphprotocol.org/schema/"> <![endif]-->
<!--[if IE 7]>         <html class="no-js lt-ie9 lt-ie8" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>" xmlns:og="http://opengraphprotocol.org/schema/"> <![endif]-->
<!--[if IE 8]>         <html class="no-js lt-ie9" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>" xmlns:og="http://opengraphprotocol.org/schema/"> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>" xmlns:og="http://opengraphprotocol.org/schema/"> <!--<![endif]-->

<head>
  <!-- add google webfonts here -->
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>

<body id="<?php print $page_id; ?>" class="<?php print $classes; ?>" <?php print $attributes;?>>

<div id="fb-root"></div>
<script>(function(d, s, id) {
  var js, fjs = d.getElementsByTagName(s)[0];
  if (d.getElementById(id)) return;
  js = d.createElement(s); js.id = id;
  js.src = "//connect.facebook.net/en_US/sdk.js#xfbml=1&version=v2.4";
  fjs.parentNode.insertBefore(js, fjs);
}(document, 'script', 'facebook-jssdk'));</script>

  <div id="fb-root"></div>
        <!--[if lt IE 9]>
            <p class="chromeframe">You are using an <strong>outdated</strong> browser. Please <a href="http://browsehappy.com/">upgrade your browser</a>.</p>
        <![endif]-->
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>

</html>
