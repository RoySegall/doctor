<?php

$plugin = array(
  'label' => t('Doctor'),
  'resource' => 'doctor',
  'name' => 'doctor__1_0',
  'entity_type' => 'doctor',
  'description' => t('Export the article content type with "cookie" authentication.'),
  'class' => 'DoctorRestful',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
);
