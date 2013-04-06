<?php
/**
 * @file
 * Doctor entity class handler.
 */
class doctorEntity extends EntityAPIController {

  /**
   * Overrides __construct().
   */
  public function __construct($entityType) {
    parent::__construct($entityType);

    $this->id = 0;
    $this->data = '';
    $this->created = time();
  }

  /**
   * Overrides create().
   */
  public function create(array $values = array()) {
    $this->data = serialize($values['data']);
    $this->created = $values['created'];

    return $this;
  }

  /**
   * Saving the listen item.
   */
  public function save($entity = NULL) {
    $entity = $this;

    if (!is_string($entity->data)) {
      $entity->data = serialize($entity->data);
    }

    $primary_keys = $entity->id ? 'id' : array();
    drupal_write_record('doctor', $entity, $primary_keys);
  }

  /**
   * Overrides entity_load().
   */
  public function load($ids = array(), $condition = array()) {
    $entities = parent::load($ids, $condition);

    foreach ($entities as &$entity) {
      $entity->data = @unserialize($entity->data);
      $dummy = clone $this;
      // Run over the variagles and add it to the $dummy object.
      foreach (get_object_vars($entity) as $key => $value) {
        $dummy->{$key} = $value;
      }
      $entity = $dummy;
    }

    return $entities;
  }

  public function delete($ids = array()) {
    if (empty($ids) && $this->id) {
      $ids = array($this->id);
    }
    parent::delete($ids);
  }
}
