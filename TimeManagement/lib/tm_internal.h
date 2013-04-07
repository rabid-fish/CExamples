#ifndef TIME_MANAGEMENT_INTERNAL
#define TIME_MANAGEMENT_INTERNAL
#include <glib.h>
#include "tm_lib.h"

GSList*  tma_list      (enum model_t model);
void*    tma_read      (enum model_t model, int index);
void*    tma_create    (enum model_t model, void* node);
int      tma_free      (enum model_t model, void* node);
int      tma_delete    (enum model_t model, int index);
void     tma_cleanup   ();

#endif

