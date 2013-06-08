<?php
/**
 * @file
 * Doctor entity class handler.
 */
class doctorEntity extends Entity {

  function __construct($values) {
    $values += array(
      'created' => time(),
    );

    parent::__construct($values, 'doctor');
  }

  /**
   * Overrides create().
   */
  public function create(array $values = array()) {
    $this->data = serialize($values['data']);
    $this->created = $values['created'];

    return $this;
  }
}
