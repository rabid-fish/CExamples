#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>
#include "tm_internal.h"
#include "tm_lib.h"

struct tag*
tma_tag_read(int id)
{
	return (struct tag*) tma_read(TAG, id);
}

GSList*
tma_tag_read_all()
{
	return tma_list(TAG);
}

struct tag*
tma_tag_create(char* description)
{
	struct tag* t = malloc( sizeof( *t ) );
	t->description = strdup(description);
	
	g_log("tma", G_LOG_LEVEL_DEBUG, "Created tag: %p - %s", t, t->description);
	tma_create(TAG, t);

	return t;
}

struct tag*
tma_tag_update(int id, char* description)
{
	struct tag* t = tma_read(TAG, id);
	
	if (t != NULL)
	{
		free(t->description);
		t->description = strdup(description);
	}

	return t;
}

int
tma_tag_delete(int id)
{
	return tma_delete(TAG, id);
}

