# CBCNY Drupal 8

This is the Drupal 8 codebase for the cbcny project. It is a relatively vanilla Drupal 8 site, with a theme built using sass and pattern-lab. 

## Local development

The local development environment uses docker, based on [docker4drupal](http://docs.docker4drupal.org/en/latest/).

### Prerequisites

* [Docker](https://docker.com) and [docker-compose](https://docs.docker.com/compose/install/)
* [Platform.sh client](https://docs.platform.sh/overview/cli.html#how-do-i-get-it)
* Nothing else running on your computer's port 80. On *nix/osx you can see what's using that port with `sudo netstat -tlpn |grep -E 'tcp[^6].*:80'`

### Start the development environment

1) Download Drupal and its modules, by running: `composer install`.
2) Download the site's database from prod, by running: `platform db:dump -A app -d docker`
3) Start the development environment, by running: `docker-compose up -d`.

Congratulations! You can now access your development version of the website at [http://localhost/](http://localhost/).

* After docker setup is complete, it takes 1-2 minutes for the theme to compile and the database to import. You can check the status of it with `docker-compose logs -f patternlab` and `docker-compose logs -f mariadb`. Use ctrl+c to stop watching the log. This only happens the first time you set up.
* You only need to run `composer install` on first setup, and when the composer.json/lock files change.
* You only need to download the db from prod on first setup, and when you want to update your database. 
* Changes in the theme will cause the theme to be automatically recompiled immediately. You will still have to clear Drupal's cache though.
* To update the database, download a fresh copy again per step 2, then run `docker-compose exec php bash -c 'drush -r $APP_ROOT/web sqlc < $APP_ROOT/docker/*.sql'`
* To shut down your development environment, run `docker-compose down`. To start it again, run `docker-compose up -d`
* If you want to use solr locally, first run `docker exec -ti drupal8_solr_1 make core=drupal -f /usr/local/bin/actions.mk` to create the solr core your environment will use.

### Tests

Tests are run through Circleci. It uses their "docker" build mode to set up something very similar to our local development environment, loads a sanitized DB dump from prod, and runs Behat and PHPUnit tests.

To generate a new DB dump: 

* Sync the database from live to a local instance, using Drush's `--sanitize` option.
* Dump the database from local to the gzipped circleci db dump file, using Drush's `--skip-tables` and `--structure-tables` options to minimize.
```bash
cd drupal8
docker-compose up -d
cd web
# Dump the DB.
DB_HOST=127.0.0.1 DB_USER=drupal DB_PASSWORD=drupal DB_NAME=drupal DB_DRIVER=mysql drush sql-sync @cbcny-org-drupal-8.master--app @self --sanitize
# Delete non-structural nodes.
DB_HOST=127.0.0.1 DB_USER=drupal DB_PASSWORD=drupal DB_NAME=drupal DB_DRIVER=mysql drush en -y drush_delete
DB_HOST=127.0.0.1 DB_USER=drupal DB_PASSWORD=drupal DB_NAME=drupal DB_DRIVER=mysql drush sql-dump --skip-tables-key=common --structure-tables-key=common --gzip --result-file=../../.circleci/circleci.sql
``` 