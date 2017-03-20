<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cbc_social_media_links_user_default_permissions() {
  $permissions = array();

  // Exported permission: access PDF version
  $permissions['access PDF version'] = array(
    'name' => 'access PDF version',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
  );

  // Exported permission: access service links
  $permissions['access service links'] = array(
    'name' => 'access service links',
    'roles' => array(
      'Administrators' => 'Administrators',
      'Trustee' => 'Trustee',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
  );

  return $permissions;
}
