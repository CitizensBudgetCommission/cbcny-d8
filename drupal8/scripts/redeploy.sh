#!/usr/bin/env bash

# Sets an arbitrary variable on Master environment to force a redeploy. Platform checks certificate validity during
# deployments, so this protects us from an expired certificate.

set -e
DATESTAMP=`date +"%s"`
TIME_DIFF=$((${DATESTAMP} - ${CERT_CHECK}))

# If it's been more than a week since the last deployment
if [[ ${PLATFORM_ENVIRONMENT} = "master-7rqtwti" && (( ${TIME_DIFF}  -gt "604800" )) ]];
  then
    # trigger a snapshot.
    php /app/.global/bin/platform.phar vset --yes --no-wait -e master -p ${PLATFORM_PROJECT} env:CERT_CHECK ${DATESTAMP}
fi
