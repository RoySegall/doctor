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

}
