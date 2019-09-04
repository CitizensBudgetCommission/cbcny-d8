# cbcny-d8

Repository for the main website of cbcny, and the old archived version. The site itself is in the `drupal8` directory, and accessible from cbcny.org . The archived version is in `drupal6`, and accessible from `old.cbcny.org`. Further directions are in these directories' README files.


# How to create to deploy new release

Run the following steps: 
1. `git clone -b pantheon git@github.com:CitizensBudgetCommission/cbcny-d8.git`
1. `cd cbcny-d8/drupal8`
1. `docker-compose up -d`
1. `docker-compose run php /bin/bash --login`
1. `composer install`
1. `vendor/bin/robo cbcny:release:pantheon`
1. `cd ../drupal8-release`
1. `git commit -m 'My favourite commit message'`
1. `git push pantheon master`
    
