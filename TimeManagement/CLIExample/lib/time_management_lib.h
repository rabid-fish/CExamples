#ifndef TIME_MANAGEMENT_H
#define TIME_MANAGEMENT_H
#include <glib.h>

struct activity
{
	char* message;
};

typedef enum { ACTIVITY, TAG } model_t;

struct activity*  tm_a_activity_create    (char* message);
GSList*           tm_a_activity_read_all  ();
struct activity*  tm_a_activity_read      (int index);
struct activity*  tm_a_activity_update    (int index, char* message);
             int  tm_a_activity_delete    (int index);

struct activity*  tm_a_tag_create         (char* message);
GSList*           tm_a_tag_read_all       ();
struct activity*  tm_a_tag_read           (int index);
struct activity*  tm_a_tag_update         (int index, char* message);
             int  tm_a_tag_delete         (int index);

void              tm_a_cleanup            ();

// main loop for the command line client
void              tm_c_execute            ();

#endif

