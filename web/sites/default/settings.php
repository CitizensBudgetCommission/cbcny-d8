<?php
/**
 * @file
 * Platform.sh example settings.php file for Drupal 8.
 */

// Default Drupal 8 settings.
//
// These are already explained with detailed comments in Drupal's
// default.settings.php file.
//
// See https://api.drupal.org/api/drupal/sites!default!default.settings.php/8
$databases = [];
$config_directories = [];
$settings['update_free_access'] = FALSE;
$settings['container_yamls'][] = __DIR__ . '/services.yml';

// Install with the 'standard' profile for this example.
//
// As the settings.php file is not writable during install on Platform.sh (for
// good reasons), Drupal will refuse to install a profile that is not defined
// here.
$settings['install_profile'] = 'standard';

// The hash_salt should be a unique random value for each application.
// If left unset, the settings.platformsh.php file will attempt to provide one.
// You can also provide a specific value here if you prefer and it will be used
// instead. In most cases it's best to leave this blank on Platform.sh. You
// can configure a separate hash_salt in your settings.local.php file for
// local development.
// $settings['hash_salt'] = 'change_me';

// Set up a config sync directory.
//
// This is defined inside the read-only "config" directory. This works well,
// however it requires a patch from issue https://www.drupal.org/node/2607352
// to fix the requirements check and the installer.
$config_directories[CONFIG_SYNC_DIRECTORY] = '../config/sync';

// Disable page cache, JS/CSS aggregation on all environments except Platform Master (live) and stage.
if (getenv('PLATFORM_BRANCH') && in_array(getenv('PLATFORM_BRANCH'), ['master', 'stage'])) {
  $config['system.performance']['cache']['page']['max_age'] = 31536000;
  $config['system.performance']['cache']['css'] = [
    'preprocess' => TRUE,
    'gzip' => TRUE
  ];
  $config['system.performance']['cache']['js'] = $config['system.performance']['cache']['css'];
  // Cloudflare settings should already be in the DB.
}
else {
  $config['system.performance']['cache']['page']['max_age'] = 0;
  $config['system.performance']['cache']['css'] = [
    'preprocess' => FALSE,
    'gzip' => FALSE
  ];
  $config['system.performance']['cache']['js'] = $config['system.performance']['cache']['css'];
  // Ensure empty cloudflare settings.
  $config['cloudflare.settings']['apikey'] = '';
  $config['cloudflare.settings']['email'] = '';
}

// Disable google analytics except on platform Master environment
if (getenv('PLATFORM_BRANCH') && getenv('PLATFORM_BRANCH') == 'master') {
  $config['google_analytics.settings']['account'] = 'UA-11916551-1';
}
else {
  $config['google_analytics.settings']['account'] = '';
}

// Automatic Platform.sh settings.
if (file_exists(__DIR__ . '/settings.platformsh.php')) {
  include __DIR__ . '/settings.platformsh.php';
}

// Include PDF files in core's fast_404 targets
$config['system.performance']['fast_404']['paths'] = '/\.(?:txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp|pdf)$/i';

// Local settings. These come last so that they can override anything.
if (file_exists(__DIR__ . '/settings.local.php')) {
  include __DIR__ . '/settings.local.php';
}
