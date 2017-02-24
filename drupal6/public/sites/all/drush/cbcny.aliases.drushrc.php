<?php
// Site cbcny, environment local
$aliases['local'] = array(
  'parent' => '@parent',
  'uri' => 'http://10.11.12.14',
  'root' => '/vagrant/public',
  'remote-host' => '10.11.12.14',
  'remote-user' => 'vagrant',
  'ssh-options' => "-i ~/.vagrant.d/insecure_private_key -l vagrant",
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
// Site cbcny, environment dev
$aliases['dev'] = array(
  'parent' => '@parent',
  'site' => 'cbcny',
  'env' => 'dev',
  'root' => '/var/www/vhosts/dev.nodesymphony.com/cbcny/public',
  'remote-host' => 'dev.nodesymphony.com',
  'remote-user' => 'deploy',
);
// Site cbcny, environment staging
$aliases['staging'] = array(
  'parent' => '@parent',
  'site' => 'cbcny',
  'env' => 'staging',
  'root' => '/var/www/vhosts/cbcny.org/public',
  'remote-host' => 'stage.cbcny.org',
  'remote-user' => 'deploy',
);
// Site cbcny, environment live
$aliases['live'] = array(
  'parent' => '@parent',
  'site' => 'cbcny',
  'env' => 'live',
  'root' => '/var/www/vhosts/cbcny.org/public',
  'remote-host' => 'cbcny.org',
  'remote-user' => 'deploy',
);
