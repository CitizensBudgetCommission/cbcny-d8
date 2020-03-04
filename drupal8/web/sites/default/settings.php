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
$databases = [
  'default' => [
    'default' => [
      'driver' => 'mysql',
      'namespace' => '\Drupal\Core\Database\Driver\\mysql',
      'username' => '',
      'password' => '',
      'host' => '127.0.0.1',
      'port' => 3306,
      'prefix' => '',
      'database' => 'cbcny__default',
      'collation' => 'utf8mb4_general_ci',
    ],
  ],
];

/**
 * Public file path:
 *
 * A local file system path where public files will be stored. This directory
 * must exist and be writable by Drupal. This directory must be relative to
 * the Drupal installation directory and be accessible over the web.
 */
$settings['file_public_path'] = 'sites/default/files';
$config['image.settings']['suppress_itok_output'] = TRUE;
$config['image.settings']['allow_insecure_derivatives'] = TRUE;

/**
 * Private file path:
 *
 * A local file system path where private files will be stored. This directory
 * must be absolute, outside of the Drupal installation directory and not
 * accessible over the web.
 *
 * Note: Caches need to be cleared when this value is changed to make the
 * private:// stream wrapper available to the system.
 *
 * See https://www.drupal.org/documentation/modules/file for more information
 * about securing private files.
 */
$settings['file_private_path'] = 'sites/default/files/private';

// Set up a config sync directory.
$settings['config_sync_directory'] = '../config/sync';

$settings['update_free_access'] = FALSE;
$settings['container_yamls'][] = __DIR__ . '/services.yml';

// Install with the 'standard' profile for this example.
//
// As the settings.php file is not writable during install on Platform.sh (for
// good reasons), Drupal will refuse to install a profile that is not defined
// here.
$settings['install_profile'] = 'minimal';

// The hash_salt should be a unique random value for each application.
// If left unset, the settings.platformsh.php file will attempt to provide one.
// You can also provide a specific value here if you prefer and it will be used
// instead. In most cases it's best to leave this blank on Platform.sh. You
// can configure a separate hash_salt in your settings.local.php file for
// local development.
// $settings['hash_salt'] = 'change_me';
$settings['hash_salt'] = 'CHANGEME';

$config['system.performance']['css']['preprocess'] = TRUE;
$config['system.performance']['css']['gzip'] = TRUE;
$config['system.performance']['js']['preprocess'] = TRUE;
$config['system.performance']['js']['gzip'] = TRUE;

// Include PDF files in core's fast_404 targets
$config['system.performance']['fast_404']['paths'] = '/\.(?:txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp|pdf)$/i';

// Disable access checks for entities explicitly rendered by Twig.
$settings['twig_tweak_check_access'] = FALSE;

if (getenv('DB_HOST')) {
  $databases['default']['default']['driver'] = getenv('DB_DRIVER');
  $databases['default']['default']['username'] = getenv('DB_USER');
  $databases['default']['default']['password'] = getenv('DB_PASSWORD');
  $databases['default']['default']['host'] = getenv('DB_HOST');
  $databases['default']['default']['port'] = getenv('DB_PORT') ?: 3306;
  $databases['default']['default']['database'] = getenv('DB_NAME');
}

// Local settings. These come last so that they can override anything.
if (file_exists(__DIR__ . '/settings.local.php')) {
  include __DIR__ . '/settings.local.php';
}

// If nothing else set it, here's the fallback db for testing.
if (!isset($databases['default']['default'])) {
  // Local testing settings for behat, circleci, etc.
  $databases['default']['default'] = [
    'driver' => 'mysql',
    'database' => 'drupal',
    'username' => 'drupal',
    'password' => 'drupal',
    'host' => '127.0.0.1',
    'port' => 3306,
  ];
}
