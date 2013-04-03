#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>
#include "time_management_internal.h"
#include "time_management_lib.h"

GSList*
tm_a_xat_read_all()
{
	return tm_a_list(TAG);
}

struct tag*
tm_a_xat_read(int index)
{
	return (struct tag*) tm_a_read(TAG, index);
}

struct tag*
tm_a_xat_create(char* description)
{
	struct tag* t = malloc( sizeof( *t ) );
	t->description = strdup(description);
		
	g_log("tm_a", G_LOG_LEVEL_DEBUG, "Created tag: %p - %s\n", t, t->description);
	tm_a_create(TAG, t);

	return t;
}

struct tag*
tm_a_xat_update(int index, char* description)
{
	struct tag* t = tm_a_read(TAG, index);
	
	if (t != NULL)
	{
		free(t->description);
		t->description = strdup(description);
	}

	return t;
}

int
tm_a_xat_delete(int index)
{
	return tm_a_delete(TAG, index);
}

