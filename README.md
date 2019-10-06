# cbcny-d8

Repository for the main website of cbcny, and the old archived version. The site itself is in the `drupal8` directory, and accessible from cbcny.org . The archived version is in `drupal6`, and accessible from `old.cbcny.org`. Further directions are in these directories' README files.


# How to create to deploy new release

**Requirements:**
- PHP >=7.3
- node 8.6

**Run the following steps:** 
1. `git clone -b pantheon git@github.com:CitizensBudgetCommission/cbcny-d8.git`
1. `cd cbcny-d8/drupal8`
1. `composer install`
1. If you haven't installed pattern-lap before, do the following steps:
    - `cd web/themes/cbcny_theme/pattern-lab`
    - `composer install`
    - `cd ../../../`
1. If you haven't installed grunt-cli, do the following steps:
    - `cd web/themes/cbcny_theme`
    - `npm install -g grunt-cli`
    - `npm install`
    - `grunt build`
    - `cd ../../`
1. `vendor/bin/robo cbcny:release:pantheon`
1. `cd ../drupal8-release`
1. `git commit -m 'My favorite commit message'`
1. `git push pantheon master`

# CircleCI details

CircleCI deploys the built site to Pantheon.
PANTHEON_SSH_KEY is an environment variable in CircleCI.
The variable's value is a base64 encoded private key. The public key part is added to Pantheon.
If you whish to change the keypair, please create a new keypair add the public part to any user that is assigned to the CBCNY Pantheon site.
On CircleCI add the private part in base64 format as the PANTHEON_SSH_KEY environment variable.
