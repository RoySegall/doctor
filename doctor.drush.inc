<?php
/**
 * @file
 * Doctor drush drush integration file.
 */

/**
 * Implements hook_drush_command().
 */
function doctor_drush_command() {
  $items = array();
  $items['doctor-listen'] = array(
    'description' => 'Activate the doctor listen functionality.',
    'options' => array(
      'timeout' => 'The amount of time in.',
    ),
  );
  return $items;
}

function drush_doctor_listen() {
  $timeout = drush_get_option('timeout', 120);

  $second = 0;
  while($timeout > $second) {
    if ($items = doctor_items()) {
      foreach ($items as $item) {
        drush_print(unserialize($item->data));
        $item->delete();
      }
    }
    $second++;
    sleep(1);
  }
}
