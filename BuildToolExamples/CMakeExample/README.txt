The sample program in main.c does nothing more than include glib.h.  The point
was to see how hard it would be to get it to compile using cmake as the build
tool.  This turned out to be easy once I found a copy of FindGLIB2.h that
actually works (have a look in the build directory).

To build this project, run these commands:
  cmake .
  make

And done!

