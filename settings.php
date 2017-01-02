<?php
/**
 * @file
 * CBC settings.php file for Drupal 8. Platform.sh copies this into place during deploy.
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

// Connect to Redis on Platform.sh.
if (!empty($_ENV['PLATFORM_RELATIONSHIPS'])) {
  $relationships = json_decode(base64_decode($_ENV['PLATFORM_RELATIONSHIPS']), TRUE);
  if (!empty($relationships['redis'][0])) {
    $conf['redis_client_host'] = $relationships['redis'][0]['host'];
    $conf['redis_client_port'] = $relationships['redis'][0]['port'];
    $conf['redis_client_interface'] = 'PhpRedis';
    $conf['cache_backends'][]       = 'sites/all/modules/redis/redis.autoload.inc';
    $conf['cache_default_class']    = 'Redis_Cache';
    // The 'cache_form' bin must be assigned to non-volatile storage.
    $conf['cache_class_cache_form'] = 'DrupalDatabaseCache';
  }
}

// Automatic Platform.sh settings.
if (file_exists(__DIR__ . '/settings.platformsh.php')) {
  include __DIR__ . '/settings.platformsh.php';
}

// Local settings. These come last so that they can override anything.
if (file_exists(__DIR__ . '/settings.local.php')) {
  include __DIR__ . '/settings.local.php';
}
