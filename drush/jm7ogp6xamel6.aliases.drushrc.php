<?php

// Figure out where the vagrant private key is stored (it moved in a recent Vagrant version)
$local_root = drush_get_context('DRUSH_SELECTED_DRUPAL_ROOT');
$new_keyfile_path =  $local_root . '/../.vagrant/machines/default/virtualbox/private_key';
if (is_file($new_keyfile_path)) {
  $insecure_private_key = $new_keyfile_path;
}
else {
  $insecure_private_key = '~/.vagrant.d/insecure_private_key';
}

$aliases['local'] = array(
  'parent' => '@parent',
  'uri' => 'http://10.11.12.14',
  'root' => '/vagrant/public',
  'remote-host' => '10.11.12.14',
  'remote-user' => 'vagrant',
  'ssh-options' => "-i " . $insecure_private_key . " -l vagrant",
  'db-url' => 'mysql://web:web@10.11.12.14:3306/web',
  'databases' => array (
    'default' => array (
      'default' => array (
        'database' => 'web',
        'username' => 'web',
        'password' => 'web',
        'host' => '10.11.12.14',
        'port' => '',
        'driver' => 'mysql',
        'prefix' => '',
      ),
    ),
  ),
);

// Automatically generated alias for the environment "Master", application "app".
$aliases['master'] = array (
  'uri' => 'http://master-7rqtwti-jm7ogp6xamel6.us.platform.sh/',
  'remote-host' => 'ssh.us.platform.sh',
  'remote-user' => 'jm7ogp6xamel6-master-7rqtwti',
  'root' => '/app/web',
  'platformsh-cli-auto-remove' => true,
  'command-specific' =>
  array (
    'site-install' =>
    array (
      'sites-subdir' => 'default',
    ),
  ),
);
