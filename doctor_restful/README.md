## Set up

On your drupal site you'll need the Libraries module, the [Pusher](https://github.com/pusher/pusher-http-php)
located as: `libraries/pusher`, You'll need to set your pusher variables as a variable:
```php
 $pusher = array(
    'id' => 12345,
    'key' => 'foo',
    'secret' => 'bar',
  );
  variable_set('pusher', $pusher);
```
