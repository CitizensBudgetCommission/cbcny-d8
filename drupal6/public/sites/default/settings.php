<?php

// Configure the database.
if (isset($_ENV['PLATFORM_RELATIONSHIPS'])) {
  $relationships = json_decode(base64_decode($_ENV['PLATFORM_RELATIONSHIPS']), TRUE);

  if (empty($db_url) && !empty($relationships['database'])) {
    foreach ($relationships['database'] as $endpoint) {
      $db_url = "mysql://{$endpoint['username']}:{$endpoint['password']}@{$endpoint['host']}/{$endpoint['path']}";
    }
  }
}

// Set up file paths.
if (isset($_ENV['PLATFORM_APP_DIR'])) {
  // Configure private and temporary file paths.
  if (!isset($conf['file_private_path'])) {
    $conf['file_private_path'] = $_ENV['PLATFORM_APP_DIR'] . '/private';
  }
  $conf['file_directory_temp'] = $_ENV['PLATFORM_APP_DIR'] . '/tmp';
}