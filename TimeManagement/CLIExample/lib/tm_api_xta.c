#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>
#include "tm_internal.h"
#include "tm_lib.h"

GHashTable *hashTable = g_hash_table_new(g_int_hash, g_int_equal);

GSList*
tm_a_xat_read_all()
{
	return tm_a_list(XAT);
}

struct x_activity_tag*
tm_a_xat_read(int id)
{
	return (struct x_activity_tag*) tm_a_read(XAT, id);
}

struct x_activity_tag*
tm_a_xat_create(int activity_id, int tag_id)
{
	struct x_activity_tag* x = malloc( sizeof( *x ) );
	x->activity_id = activity_id;
	x->tag_id = tag_id;
	//x->activity_sort_order ... ???
	
	// hash by tag
	// list of id's
	// get last sort order
	
	g_log("tm_a", G_LOG_LEVEL_DEBUG, "Created xat: %p - %s\n", x);
	tm_a_create(XAT, x);

	return x;
}

struct x_activity_tag*
tm_a_xat_update(int id, int activity_id, int tag_id)
{
	struct x_activity_tag* x = tm_a_read(XAT, id);
	
	if (x != NULL)
	{
		free(x->description);
		x->description = strdup(description);
	}

	return x;
}

int
tm_a_xat_delete(int id)
{
	return tm_a_delete(XAT, id);
}

