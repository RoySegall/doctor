<?php
/**
 * @file
 * Rules integration with the doctor module.
 */

/**
 * Implements hook_rules_action_info().
 */
function doctor_rules_action_info() {
  return array(
    'doctor_queue_data' => array(
      'base' => 'doctor_queue_data',
      'label' => t('Add data for a doctor queue item'),
      'group' => t('Doctor'),
      'parameter' => array(
        'value' => array('type' => 'unknown', 'label' => t('Value to debug')),
      ),
    ),
    'doctor_create_item' => array(
      'base' => 'doctor_create_item',
      'label' => t('Compile all queued items'),
      'group' => t('Doctor'),
    ),
  );
}

/**
 * Rules callback action - build an array that will be compile later.
 */
function doctor_queue_data($value) {
  $info = variable_get('doctor_rules_data', array());
  $info[] = $value;
  variable_set('doctor_rules_data', $info);
}

/**
 * Create the doctor entity.
 */
function doctor_create_item() {
  $info = variable_get('doctor_rules_data', array());
  doctor_create($info)->save();
  variable_del('doctor_rules_data');
}
