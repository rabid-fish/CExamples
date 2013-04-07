#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>
#include "tm_internal.h"
#include "tm_lib.h"

GHashTable* hash_xta = NULL;


struct x_tag_activity*
tma_xta_read(int id)
{
	return (struct x_tag_activity*) tma_read(XTA, id);
}

GSList*
tma_xta_read_all()
{
	return tma_list(XTA);
}

GSList*
tma_xta_read_by_tag(int tag_id)
{
	GSList* list_all = tma_list(XTA);

	// loop through all
	// if item has matching tag_id, populate in new list
	// return new list
	// malloc issues!!!
	
	return NULL;
}

struct x_tag_activity*
tma_xta_create(int tag_id, int activity_id)
{
	struct x_tag_activity* x = malloc( sizeof( *x ) );
	x->tag_id = tag_id;
	x->activity_id = activity_id;
/*	
	GSList* list_activity = tma_activity_read_by_tag(tag_id);
	// read by tag
	//  list of xta's by tag
	
	int max = g_slist_length(list_activity);
	x->activity_sort_order = max;
*/	
	g_log("tma", G_LOG_LEVEL_DEBUG, "Created xta: %p - %d:%d", x, x->tag_id, x->activity_id);
	tma_create(XTA, x);

	return x;
}

struct x_tag_activity*
tma_xta_update(int id, int tag_id, int activity_id, int activity_sort_order)
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

void
tma_xta_initialize()
{
	hash_xta = g_hash_table_new(g_int_hash, g_int_equal);
}

void
tma_xta_cleanup()
{
	g_hash_table_destroy(hash_xta);
}

/*
void tma_xta_add_element(Foo * foo, gchar * key, gpointer data)
{  
  GSList * list = g_hash_table_lookup(foo->bar, key);

  list = g_slist_append(list, data);
  g_hash_table_insert(foo->bar, key, list);
}
*/

