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

struct x_tag_activity
{
	int id;
	int tag_id;
	int activity_id;
	int activity_sort_order;
};

enum model_t { ACTIVITY, TAG, XTA };

struct activity*        tma_activity_create      (char* description);
struct activity*        tma_activity_read        (int id);
GSList*                 tma_activity_read_all    ();
//GSList*                 tma_activity_read_by_tag (int tag_id); // sorted
struct activity*        tma_activity_update      (int id, char* description);
int                     tma_activity_delete      (int id);
struct activity*        tma_activity_reorder     (int activity_id, int tag_id, int sort_order);

struct tag*             tma_tag_create           (char* description);
struct tag*             tma_tag_read             (int id);
GSList*                 tma_tag_read_all         ();
struct tag*             tma_tag_update           (int id, char* description);
int                     tma_tag_delete           (int id);
struct tag*             tma_tag_reorder          (int tag_id, int sort_order);

struct x_tag_activity*  tma_xta_create           (int tag_id, int activity_id);
GSList*                 tma_xta_read_all         ();
GSList*                 tma_xta_read_by_tag      (int tag_id);
struct x_tag_activity*  tma_xta_read             (int id);
struct x_tag_activity*  tma_xta_update           (int id, int tag_id, int activity_id, int activity_sort_order);
int                     tma_xta_delete           (int id);
void                    tma_xta_initialize       ();
void                    tma_xta_cleanup          ();

void                    tma_initialize           ();
void                    tma_cleanup              ();

// main loop for the command line client
void                    tm_c_execute             ();

#endif

