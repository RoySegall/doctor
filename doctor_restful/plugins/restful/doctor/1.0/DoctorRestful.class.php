<?php

/**
 * @file
 * Contains RestfulExampleArticlesResource.
 */

class DoctorRestful extends RestfulEntityBase {

  public function publicFieldsInfo() {
    $info = parent::publicFieldsInfo();

    $info['created'] = array(
      'property' => 'created',
      'process_callbacks' => array(
        array($this, 'createProcess'),
      ),
    );

    $info['data'] = array(
      'property' => 'data',
    );

    $info['watched'] = array(
      'property' => 'watched',
    );

    $info['type'] = array(
      'property' => 'type',
    );

    return $info;
  }

  /**
   * Overrides parent::queryForListSort().
   */
  protected function queryForListSort(\EntityFieldQuery $query) {
    $query->propertyOrderBy('created', 'DESC');
  }

  /**
   * Formatting the creation time.
   *
   * @param $value
   *   The unix timestamp
   *
   * @return string
   *   The formatted date.
   */
  public function createProcess($value) {
    return format_date($value);
  }

}
