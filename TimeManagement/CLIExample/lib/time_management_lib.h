#ifndef TIME_MANAGEMENT_H
#define TIME_MANAGEMENT_H
#include <glib.h>

struct activity
{
	char* message;
};

struct activity*  tm_a_create    (char* message);
struct activity*  tm_a_read      (int index);
struct activity*  tm_a_update    (int index, char* message);
             int  tm_a_delete    (int index);

GSList*           tm_a_read_all  ();
void              tm_a_cleanup   ();

// main loop for the command line client
void              tm_c_execute   ();

#endif

