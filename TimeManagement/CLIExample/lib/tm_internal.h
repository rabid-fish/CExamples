#ifndef TIME_MANAGEMENT_INTERNAL
#define TIME_MANAGEMENT_INTERNAL
#include <glib.h>
#include "time_management_lib.h"

GSList*  tm_a_list      (enum model_t model);
void*    tm_a_read      (enum model_t model, int index);
void*    tm_a_create    (enum model_t model, void* node);
int      tm_a_free      (enum model_t model, void* node);
int      tm_a_delete    (enum model_t model, int index);
void     tm_a_cleanup   ();

#endif

