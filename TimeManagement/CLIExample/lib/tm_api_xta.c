#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>
#include "tm_internal.h"
#include "tm_lib.h"

GHashTable* xta_hash = g_hash_table_new(g_int_hash, g_int_equal);

/*
GSList*
tma_xta_read_all()
{
	return tma_list(XTA);
}

struct x_tag_activity*
tma_xta_read(int id)
{
	return (struct x_tag_activity*) tma_read(XTA, id);
}
*/

struct x_tag_activity*
tma_xta_create(int activity_id, int tag_id)
{
	struct x_tag_activity* x = malloc( sizeof( *x ) );
	x->activity_id = activity_id;
	x->tag_id = tag_id;
	
	// knowns
	//   - hash contains keys that are the tag id
	//   - hash values are lists, each list is of activities
	// pseudocode
	//   get the current value (list) for the provided tag id
	//   if null
	//     create a new list (malloc) 
	//     append new xta to list
	//     put list in hash
	//   else
	//     append to list
	//     get length, set sort order
	
	g_log("tma", G_LOG_LEVEL_DEBUG, "Created xta: %p - %s\n", x);

	return x;
}
/*
struct x_tag_activity*
tma_xta_update(int id, int activity_id, int tag_id)
{
	struct x_tag_activity* x = tma_read(XTA, id);
	
	if (x != NULL)
	{
//		free(x->description);
//		x->description = strdup(description);
	}

	return x;
}

int
tma_xta_delete(int id)
{
	return tma_delete(XTA, id);
}
*/

