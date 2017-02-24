#!/bin/bash
# Deployment steps for a Drupal site. Should be run on each deployment.
# Usage: ./deploy.sh <environment>
# environment is one of: local, dev, staging, live.
ENV=$1
REPO_ROOT=`pwd`
PARENT_DIR=`dirname $REPO_ROOT`

if [[ -f "$REPO_ROOT/public/htaccess.$ENV" ]]; then
  echo 'Copying .htaccess'
  cd $REPO_ROOT/public && cp htaccess.$ENV .htaccess > /dev/null
fi

if [[ -f "$REPO_ROOT/public/robots.txt.$ENV" ]]; then
  echo 'Copying robots.txt'
  cd $REPO_ROOT/public && cp robots.txt.$ENV robots.txt > /dev/null
fi

if [[ -f "$REPO_ROOT/public/sites/default/$ENV.settings.php" ]]; then
  echo 'Copying settings.php'
  cd $REPO_ROOT/public/sites/default && cp $ENV.settings.php settings.php > /dev/null
fi

echo 'Creating and simlinking files directory' 
if [[ ! -d $PARENT_DIR/common/public/sites/default/files ]]; then
  mkdir -p $PARENT_DIR/common/public/sites/default/files 
fi
cd $REPO_ROOT/public/sites/default && ln -fns $PARENT_DIR/common/public/sites/default/files

echo 'Creating and simlinking private files directory'
if [[ ! -d $PARENT_DIR/common/private ]]; then
  mkdir -p $PARENT_DIR/common/private
fi
ln -fns $PARENT_DIR/common/private $PARENT_DIR/private


echo 'Simlinking public directory'
ln -fns $REPO_ROOT/public $PARENT_DIR/public

DRUSH=`which drush`

echo 'Making DB backup'
drush -r $REPO_ROOT/public -p -y sql-dump |gzip > $PARENT_DIR/last-deploy.sql.gz

echo 'Running DB updates'
drush -r $REPO_ROOT/public -p -y updb > $PARENT_DIR/last_deploy.log

echo 'Reverting Features'
drush -r $REPO_ROOT/public -p -y fra >> $PARENT_DIR/last_deploy.log

echo 'Clearing cache'
drush -r $REPO_ROOT/public -p -y cc all >> $PARENT_DIR/last_deploy.log

if [[ $ENV == 'dev' ]]; then
  echo 'Resetting admin password'
  drush -r $REPO_ROOT/public -p -y upwd admin --password="admin" >> $PARENT_DIR/last_deploy.log
fi
