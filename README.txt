What is it?
===========================
The module "Doctor" is "listening" to a doctor listen item that create
during your module actions.

How does it work?
===========================
The doctor create an entity called doctor. When running the drush command
drush doctor-listen, the module will wait for doctor entity entry to create and
will present the data on the CLI. If there any items that created when the
doctor did not listen, the first time the your initialized the command they will
be displayed for you.

Why is this use full?
===========================
Sometimes the dpm messages are not available for us(AJAX callbacks) and
sometimes we just need to debug during a drush script when debug is a little bit
hard. In those cases, you can turn on the doctor and he will be listen to you.

This is also another way to debug you live, dev and test code stages with the
drush remote connect.

Install and usage
===========================
Enable the module just like any other module. There is a module called Doctor
example that show how to implements display handler in the drush CLI. If you did
not implemented any display handler, the module will use the function
drush_print_r that is the equivalent for php standard php print_r.
