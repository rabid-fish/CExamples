This project contains the basics of a modular source tree.  The folders and what they hold:
  src   -> all gui interaction happens here
  lib   -> program logic, basically an api, with few dependencies, called by the gui
  tests -> unit tests written with gnu "check" that validate the api

To build this project, run these commands:
  cmake .
  make

To run the tests, run:
  make test

To run the compiled executable, run:
  src/time_management

