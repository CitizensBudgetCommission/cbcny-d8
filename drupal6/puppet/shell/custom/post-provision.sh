#!/bin/bash

VAGRANT_CORE_FOLDER="/vagrant"

if [[ ! -d "/home/vagrant/.drush" ]]; then
  echo 'Creating drush directory'
  su - vagrant -c "mkdir ~/.drush"
fi

if [[ ! -f "/home/vagrant/.drush/drush.ini" ]]; then
  echo 'Creating drush settings'
  su - vagrant -c "echo 'memory_limit = 512M' > ~/.drush/drush.ini"
fi
