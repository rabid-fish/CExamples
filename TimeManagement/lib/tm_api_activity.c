#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>
#include "tm_internal.h"
#include "tm_lib.h"


struct activity*
tma_activity_read(int id)
{
	return (struct activity*) tma_read(ACTIVITY, id);
}

GSList*
tma_activity_read_all()
{
	return tma_list(ACTIVITY);
}

GSList*
tma_activity_read_by_tag(int tag_id)
{
	// Get the hash
	// read the activity list from the hash for the given tag_id
	return NULL;
}

struct activity*
tma_activity_create(char* description)
{
	struct activity* a = malloc( sizeof( *a ) );
	a->description = strdup(description);
	a->date_created = time(NULL);

	g_log("tma", G_LOG_LEVEL_DEBUG, "Created activity: %p - %s\n", a, a->description);
	tma_create(ACTIVITY, a);

	return a;
}

struct activity*
tma_activity_update(int id, char* description)
{
	struct activity* a = tma_read(ACTIVITY, id);
	
	if (a != NULL)
	{
		free(a->description);
		a->description = strdup(description);
		g_log("tma", G_LOG_LEVEL_DEBUG, "Updated activity: %p - %s\n", a, a->description);
	}

	return a;
}

int
tma_activity_delete(int id)
{
	return tma_delete(ACTIVITY, id);
}

