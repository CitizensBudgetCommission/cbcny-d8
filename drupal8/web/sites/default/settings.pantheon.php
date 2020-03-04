<?php

/**
 * @file
 * Pantheon configuration file.
 *
 * IMPORTANT NOTE:
 * Do not modify this file. This file is maintained by Pantheon.
 *
 * Site-specific modifications belong in settings.php, not this file. This file
 * may change in future releases and modifications would cause conflicts when
 * attempting to apply upstream updates.
 */

$variables = [
  'https' => TRUE,
  'domains' => [
    'canonical' => 'cbcny.org',
    'synonyms' => [
      'live-cbcny.pantheonsite.io',
    ],
    'additional' => [
      'www.cbcny.org',
    ],
  ],
  'redis' => TRUE,
];

/**
 * Version of Pantheon files.
 *
 * This is a monotonically-increasing sequence number that is
 * incremented whenever a change is made to any Pantheon file.
 * Not changed if Drupal core is updated without any change to
 * any Pantheon file.
 *
 * The Pantheon version is included in the git tag only if a
 * release is made that includes changes to Pantheon files, but
 * not to any Drupal files.
 */
if (!defined('PANTHEON_VERSION')) {
  define('PANTHEON_VERSION', '3');
}

if (!defined('PANTHEON_ENVIRONMENT')) {
  define('PANTHEON_ENVIRONMENT', $_ENV['PANTHEON_ENVIRONMENT'] ?? 'live');
}

$is_cli = php_sapi_name() === 'cli';
$is_installer_url = strpos($_SERVER['SCRIPT_NAME'], '/core/install.php') === 0;

if ($variables['https']
  && !$is_cli
  && $_SERVER['HTTPS'] === 'OFF'
  && (!isset($_SERVER['HTTP_X_SSL']) || $_SERVER['HTTP_X_SSL'] != 'ON')
) {
  header('HTTP/1.0 301 Moved Permanently');
  header('Location: https://'. $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']);

  exit();
}

/**
 * Determine whether this is a preproduction or production environment, and
 * then load the pantheon services.yml file.  This file should be named either
 * 'pantheon-production-services.yml' (for 'live' or 'test' environments)
 * 'pantheon-preproduction-services.yml' (for 'dev' or multidev environments).
 */
$pantheon_services_file = __DIR__ . '/services.pantheon.preproduction.yml';
if ($_ENV['PANTHEON_ENVIRONMENT'] === 'live' || $_ENV['PANTHEON_ENVIRONMENT'] === 'test') {
  $pantheon_services_file = __DIR__ . '/services.pantheon.production.yml';
}

if (file_exists($pantheon_services_file)) {
  $settings['container_yamls'][] = $pantheon_services_file;
}

/**
 * Add the Drupal 8 CMI Directory Information directly in settings.php to make sure
 * Drupal knows all about that.
 *
 * Issue: https://github.com/pantheon-systems/drops-8/issues/2
 *
 * IMPORTANT SECURITY NOTE:  The configuration paths set up
 * below are secure when running your site on Pantheon.  If you
 * migrate your site to another environment on the public internet,
 * you should relocate these locations. See "After Installation"
 * at https://www.drupal.org/node/2431247
 *
 */
if ($is_installer_url) {
  $config_directories = [
    CONFIG_SYNC_DIRECTORY => 'sites/default/files',
  ];
}

/**
 * Allow Drupal 8 to Cleanly Redirect to Install.php For New Sites.
 *
 * Issue: https://github.com/pantheon-systems/drops-8/issues/3
 *
 * c.f. https://github.com/pantheon-systems/drops-8/pull/53
 *
 */
if (!$is_cli
  && !$is_installer_url
  && isset($_SERVER['PANTHEON_DATABASE_STATE'])
  && $_SERVER['PANTHEON_DATABASE_STATE'] === 'empty'
  && empty($GLOBALS['install_state'])
) {
  include_once __DIR__ . '/../../core/includes/install.core.inc';
  include_once __DIR__ . '/../../core/includes/install.inc';

  install_goto('core/install.php');
}

$config['search_api.server.solr']['backend_config']['connector'] = 'pantheon';
$config['search_api.server.solr']['backend_config']['connector_config']['schema'] = 'modules/contrib/search_api_solr/solr-conf/4.x/schema.xml';

if (!empty($variables['redis']) && !empty($_ENV['CACHE_HOST'])) {
  $redisServicesYml = implode(
    DIRECTORY_SEPARATOR,
    [
      'modules',
      'contrib',
      'redis',
      'example.services.yml',
    ]
  );
  if (file_exists($redisServicesYml)) {
    $settings['container_yamls'][] = $redisServicesYml;

    $settings['redis.connection']['interface'] = 'PhpRedis';
    $settings['redis.connection']['host'] = $_ENV['CACHE_HOST'];
    $settings['redis.connection']['port'] = $_ENV['CACHE_PORT'];
    $settings['redis.connection']['password'] = $_ENV['CACHE_PASSWORD'];

    $settings['cache']['default'] = 'cache.backend.redis';
    $settings['cache_prefix']['default'] = 'pantheon-redis';

    $settings['cache']['bins']['bootstrap'] = 'cache.backend.chainedfast';
    $settings['cache']['bins']['discovery'] = 'cache.backend.chainedfast';
    $settings['cache']['bins']['config'] = 'cache.backend.chainedfast';
  }
}

/**
 * Handle Hash Salt Value from Drupal
 *
 * Issue: https://github.com/pantheon-systems/drops-8/issues/10
 *
 */
if (isset($_ENV['DRUPAL_HASH_SALT'])) {
  $settings['hash_salt'] = $_ENV['DRUPAL_HASH_SALT'];
}

/**
 * Define appropriate location for tmp directory
 *
 * Issue: https://github.com/pantheon-systems/drops-8/issues/114
 *
 */
$config['system.file']['path']['temporary'] = $_SERVER['HOME'] .'/tmp';

/**
 * Install the Pantheon Service Provider to hook Pantheon services into
 * Drupal 8. This service provider handles operations such as clearing the
 * Pantheon edge cache whenever the Drupal cache is rebuilt.
 */
$GLOBALS['conf']['container_service_providers']['PantheonServiceProvider'] = '\Pantheon\Internal\PantheonServiceProvider';

/**
 * Place Twig cache files in the Pantheon rolling temporary directory.
 * A new rolling temporary directory is provided on every code deploy,
 * guaranteeing that fresh twig cache files will be generated every time.
 * Note that the rendered output generated from the twig cache files
 * are also cached in the database, so a cache clear is still necessary
 * to see updated results after a code deploy.
 */
if (isset($_ENV['PANTHEON_ROLLING_TMP']) && isset($_ENV['PANTHEON_DEPLOYMENT_IDENTIFIER'])) {
  // Relocate the compiled twig files to <binding-dir>/tmp/ROLLING/twig.
  // The location of ROLLING will change with every deploy.
  $settings['php_storage']['twig']['directory'] = $_ENV['PANTHEON_ROLLING_TMP'];

  // Ensure that the compiled twig templates will be rebuilt whenever the
  // deployment identifier changes.  Note that a cache rebuild is also necessary.
  $settings['deployment_identifier'] = $_ENV['PANTHEON_DEPLOYMENT_IDENTIFIER'];
  $settings['php_storage']['twig']['secret'] = $_ENV['DRUPAL_HASH_SALT'] . $settings['deployment_identifier'];
}

/**
 * "Trusted host settings" are not necessary on Pantheon; traffic will only
 * be routed to your site if the host settings match a domain configured for
 * your site in the dashboard.
 */
$settings['trusted_host_patterns'] = [
  '.*',
];

/**
 * The default list of directories that will be ignored by Drupal's file API.
 *
 * By default ignore node_modules and bower_components folders to avoid issues
 * with common frontend tools and recursive scanning of directories looking for
 * extensions.
 *
 * @see file_scan_directory()
 * @see \Drupal\Core\Extension\ExtensionDiscovery::scanDirectory()
 */
if (empty($settings['file_scan_ignore_directories'])) {
  $settings['file_scan_ignore_directories'] = [
    'node_modules',
    'bower_components',
  ];
}

/**
 * Override the $databases variable to pass the correct Database credentials
 * directly from Pantheon to Drupal.
 *
 * Issue: https://github.com/pantheon-systems/drops-8/issues/8
 */
if (isset($_SERVER['PRESSFLOW_SETTINGS'])) {
  foreach (json_decode($_SERVER['PRESSFLOW_SETTINGS'], TRUE) as $key => $value) {
    switch ($key) {
      case 'conf';
        foreach($value as $conf_key => $conf_value) {
          $conf[$conf_key] = $conf_value;
        }
        break;

      case 'databases';
        // Protect default configuration but allow the specification of
        // additional databases. Also, allows fun things with 'prefix' if they
        // want to try multisite.
        $databases = array_replace_recursive($databases ?? [], $value);
        break;

      default:
        $$key = $value;
        break;
    }
  }
}

if (PANTHEON_ENVIRONMENT !== 'live') {
  $config['system.logging']['error_level'] = 'verbose';
  $config['google_analytics.settings']['account'] = '';

  $config['cloudflare.settings']['apikey'] = '';
  $config['cloudflare.settings']['email'] = '';
}

if (PANTHEON_ENVIRONMENT === 'dev') {
  // Place for settings for the dev environment.
}

if (PANTHEON_ENVIRONMENT === 'test') {
  // Place for settings for the test environment.
}

if (PANTHEON_ENVIRONMENT === 'live') {
  // Redirect to canonical domain.
  if (!$is_cli) {
    $location = FALSE;

    // Get current protocol.
    $protocol = 'http';
    if ($_SERVER['SERVER_PORT'] == 443
      || (
        $variables['https']
        && !empty($_SERVER['HTTPS'])
        && $_SERVER['HTTPS'] !== 'off'
      )
    ) {
      $protocol = 'https';
    }

    // Default redirect.
    $redirect = "$protocol://{$variables['domains']['canonical']}{$_SERVER['REQUEST_URI']}";
    if ($_SERVER['HTTP_HOST'] === $variables['domains']['canonical']
      || in_array($_SERVER['HTTP_HOST'], $variables['domains']['synonyms'])
    ) {
      $redirect = FALSE;
    }

    if ($redirect) {
      header("HTTP/1.0 301 Moved Permanently");
      header("Location: $redirect");

      exit();
    }
  }

  $config['google_analytics.settings']['account'] = 'UA-11916551-1';
}

if (!empty($variables['environments'][PANTHEON_ENVIRONMENT]['conf'])) {
  foreach ($variables['environments'][PANTHEON_ENVIRONMENT]['conf'] as $variable => $value) {
    $conf[$variable] = $value;
  }
}

if (file_exists("{$settings['file_private_path']}/settings/{$_ENV['PANTHEON_ENVIRONMENT']}.settings.php")) {
  include "{$settings['file_private_path']}/settings/{$_ENV['PANTHEON_ENVIRONMENT']}.settings.php";
}
