<?php
/**
 * @file
 * API file for the doctor module.
 */

/**
 * Implements hook_doctor_listener_info().
 */
function hook_doctor_listener_info() {
  return array(
    'doctor' => array(
      'callback' => '_hook_doctor_listener_info',
    ),
  );
}

/**
 * Doctor listener callback function.
 *
 * @param $data
 *  The un-serialized data listener item.
 */
function _hook_doctor_listener_info($data) {
  drush_print_r(dt('Your recorded info: @data', array('@data' => $data)));
}

/**
 * Implements hook_doctor_listener_info_alter().
 *
 * Allow you to alter the listener callback functions.
 */
function hook_doctor_listener_info_alter(&$data) {
  foreach ($data as $module_name => &$callbacks_info) {
    if ($module_name == 'doctor') {
      $callbacks_info['callback'] = '__hook_doctor_listener_info';
    }
  }
}

/**
 * Implements hook_doctor_bundle_info().
 */
function hook_doctor_bundle_info() {
  return array(
    'foo' => array(
      'name' => 'Foo',
      'type' => 'foo',
      'description' => 'Bar!! You expected foo but no... surprise ;)',
    ),
  );
}
