#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>
#include "tm_internal.h"
#include "tm_lib.h"

//GHashTable *hashTable = g_hash_table_new(g_int_hash, g_int_equal);

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

struct x_tag_activity*
tma_xta_create(int activity_id, int tag_id)
{
	struct x_tag_activity* x = malloc( sizeof( *x ) );
	x->activity_id = activity_id;
	x->tag_id = tag_id;
	//x->activity_sort_order ... ???
	
	// hash by tag
	// list of id's
	// get last sort order
	
	g_log("tma", G_LOG_LEVEL_DEBUG, "Created xta: %p - %s\n", x);
	tma_create(XTA, x);

	return x;
}

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

