# CBCNY.org

This repository contains the code for both www.cbcny.org and old.cbcny.org. It has everything you need to start a local development environment, or run the actual sites.

## Repository structure

### Directories

The repo is divided into drupal8 (www.), and drupal6 (old.). The Drupal 6 site exists for archive purposes only, and should not need any modification. Both have a vanilla platform.sh application configuration, and are reasonably vanilla setups themselves. For relevant documentation, try google. :)

There is also a Docker directory, for configs etc needed for local development. 

### Branches

Since the sites are hosted with platform.sh, the *master* branch is our "live" environment. Ideally, nothing should be committed to this branch directly. All work happens in branches, which are merged in through Pull Requests. All Pull Requests are automatically built as environments in platform.sh. You can get the URLs for each environment using the platform.sh CLI tool, or the platform.sh web user interface.

## Local development

Local development environments are built through Docker.
