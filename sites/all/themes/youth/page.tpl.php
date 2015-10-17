<?php if (!$ajax): ?>
<div id="wrapper">

  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
    <?php if ($main_menu): ?>
      <a href="#navigation" class="element-invisible element-focusable"><?php print t('Skip to navigation'); ?></a>
    <?php endif; ?>
  </div>

<div id="header-wrapper">
  <header id="header" role="banner" class="clearfix container">
    <?php print render($page['logo']); ?>
    <p id="tagline">Empowering youth in the cooperative movement</p>
    <?php print render($page['header']); ?>
  </header> <!-- /#header -->
</div>

    <div id="navigation-wrapper">
      <nav id="navigation" role="navigation" class="clearfix container <?php print $navigation_class; ?>">
        <h2 class="navigation-header"><i class="fa fa-bars"></i><span>Menu</span></h2>
        <?php print $main_menu_tree; ?>
      </nav> <!-- /#navigation -->
    </div> <!-- /#navigation-wrapper -->


<?php if ($page['highlighted']): ?>
  <div id="highlighted-wrapper">
    <section id="highlighted" role="contentinfo" class="container">
      <?php print render($page['highlighted']) ?>
    </section> <!-- /#footer -->
  </div>
<?php endif; ?>

  <div id="main-wrapper"><div id="main" class="clearfix container"><div class="row">

<?php endif; /* !$ajax */ ?>
  <section id="page" role="main" class="clearfix <?php echo $main_classes; ?>">
    <?php print $messages; ?>
    <a id="main-content"></a>
    <?php print render($title_prefix); ?>
    <?php if ($title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
    <?php print render($title_suffix); ?>
    <?php if (!empty($tabs['#primary'])): ?><div class="tabs-wrapper"><?php print render($tabs); ?></div><?php endif; ?>
    <?php print render($page['help']); ?>
    <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
    <?php print render($page['content']); ?>
  </section> <!-- /#main -->
<?php if (!$ajax): ?>
  
  <?php if ($page['sidebar_first']): ?>
    <aside id="sidebar-first" role="complimentary" class="sidebar clearfix <?php echo $sidebar_first_classes; ?>">
      <?php print render($page['sidebar_first']); ?>
    </aside>  <!-- /#sidebar-first -->
  <?php endif; ?>
  
  <?php if ($page['sidebar_second']): ?>
    <aside id="sidebar-second" role="complimentary" class="sidebar clearfix <?php echo $sidebar_second_classes; ?>">
      <?php print render($page['sidebar_second']); ?>
    </aside>  <!-- /#sidebar-second -->
  <?php endif; ?>

  </div></div></div> <!-- /.row, #main, #wrapper-main -->

<?php if ($page['prefooter1']): ?>
  <div id="prefooter1-wrapper">
    <section id="prefooter1" role="contentinfo" class="container">
      <?php print render($page['prefooter1']) ?>
    </section> <!-- /#footer -->
  </div>
<?php endif; ?>

<?php if ($page['prefooter2']): ?>
  <div id="prefooter2-wrapper">
    <section id="prefooter2" role="contentinfo" class="container">
      <?php print render($page['prefooter2']) ?>
    </section> <!-- /#footer -->
  </div>
<?php endif; ?>

  <?php if ($page['utility'] || $secondary_menu): ?>
    <aside id="utility" role="complimentary">
      <?php if ($secondary_menu): ?>
        <nav id="utility-nav" role="navigation" class="container">
		  <?php echo $secondary_menu; ?>
        </nav> <!-- /#utility-nav -->
      <?php endif; ?>
	  <?php if ($page['utility']) : ?>
		<div class="container">
	      <?php print render($page['utility']); ?>
		</div>
	  <?php endif; ?>
    </aside> <!-- /#utility -->
  <?php endif; ?>

<div id="footer-wrapper">
  <footer id="footer" role="contentinfo" class="container">
    <div class="row">
    <?php print render($page['footer']) ?>
	<div id="site-credit" class="col-md-8 col-sm-8"><h4>USA Cooperative Youth Council</h4>Hand-crafted hosting by Electric Embers<br><a href="http://www.webskillet.com">Design and development by Webskillet</a></div><img src="/sites/all/themes/youth/images/coop_orange.jpg" class="col-md-4 col-sm-4"/>
  </div>
  </footer> <!-- /#footer -->
</div>

</div> <!-- /#wrapper -->
<?php endif; /* !$ajax */ ?>
