#ifndef TIME_MANAGEMENT_LIB
#define TIME_MANAGEMENT_LIB
#include <glib.h>
#include <time.h>

struct activity
{
	int id;
	char* description;
	time_t date_created;
};

struct tag
{
	int id;
	char* description;
};

struct x_activity_tag
{
	int id;
	int activity_id;
	int activity_sort_order;
	int tag_id;
};

enum model_t { ACTIVITY, TAG };

struct activity*  tm_a_activity_create    (char* description);
GSList*           tm_a_activity_read_all  ();
struct activity*  tm_a_activity_read      (int id);
struct activity*  tm_a_activity_update    (int id, char* description);
             int  tm_a_activity_delete    (int id);

struct tag*       tm_a_tag_create         (char* description);
GSList*           tm_a_tag_read_all       ();
struct tag*       tm_a_tag_read           (int id);
struct tag*       tm_a_tag_update         (int id, char* description);
             int  tm_a_tag_delete         (int id);

struct activity*  tm_a_xat_create         (int activity_id, int tag_id);
GSList*           tm_a_xat_read_all       ();
struct activity*  tm_a_xat_read           (int id);
struct activity*  tm_a_xat_update         (int id, int activity_id, int tag_id);
             int  tm_a_xat_delete         (int id);

void              tm_a_cleanup            ();

// main loop for the command line client
void              tm_c_execute            ();

#endif

