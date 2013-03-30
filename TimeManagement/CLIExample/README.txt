Glib's Message Logging has been used to allow debugging output that can be turned
on or off using environment variables.  To enable debug output, set the following
environment variable prior to running the executable:
  export G_MESSAGES_DEBUG=all

To build this project, run these commands:
  cmake .
  make

To run the tests, run:
  make test

To run the compiled executable, run:
  src/time_management

