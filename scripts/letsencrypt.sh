#!/usr/bin/env bash

# Checks and updates the letsencrypt HTTPS cert.

set -e

if [ "$PLATFORM_ENVIRONMENT" = "master" ]
  then
    # Renew the certificate
    lego --email="kmedina@cbcny.org" --domains="cbcny.org" --webroot=/app/web/ --path=/app/keys/ -a renew
    # Split the certificate from any intermediate chain
    csplit -f /app/keys/certificates/cbcny.org.crt- /app/keys/certificates/cbcny.org.crt '/-----BEGIN CERTIFICATE-----/' '{1}' -z -s
    # Update the certificates on the domain
    php /app/.global/bin/platform.phar domain:update -p $PLATFORM_PROJECT --no-wait --yes --cert /app/keys/certificates/cbcny.org.crt-00 --chain /app/keys/certificates/cbcny.org.crt-01 --key /app/keys/certificates/cbcny.org.key cbcny.org
fi