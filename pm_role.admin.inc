<?php
// $Id$

/**
 * @TODO
 *   Test cleanup of settings.
 *   Write a @file.
 */

function pm_role_admin_settings() {
  $form = array();
  $roles = user_roles(TRUE);
  foreach ($roles as $rid1 => $role1) {
    foreach ($roles as $rid2 => $role2) {
      $array = array(
        '@role1' => $role1,
        '@role2' => $role2,
      );
      $form['pm_role_deny_from'. $rid1 .'_to_'. $rid2] = array(
        '#type' => 'checkbox',
        '#title' => t('@role1 cannot sent to @role2', $array),
        '#description' => t('@role1 is not allowed to sent messages to @role2', $array),
        '#default_value' => variable_get('pm_role_deny_from'. $rid1 .'_to_'. $rid2, FALSE),
      );
    }
  }
  return system_settings_form($form);
}

/**
 * @TODO
 *   Needs tests.
 */
function pm_role_admin_settings_submit(&$form, $form_state) {
  foreach ($form_state['values'] as $key => $value) {
    // take sure we have a access form element
    if (strpos($key, 'pm_role_deny_') !== FALSE) {
      if ($value == FALSE) {
        unset($form_state['values'][$key]);
      }
    }
  }
}

