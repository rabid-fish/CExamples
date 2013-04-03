#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>
#include "tm_internal.h"
#include "tm_lib.h"


GSList*
tm_a_activity_read_all()
{
	return tm_a_list(ACTIVITY);
}

struct activity*
tm_a_activity_read(int id)
{
	return (struct activity*) tm_a_read(ACTIVITY, id);
}

struct activity*
tm_a_activity_create(char* description)
{
	struct activity* a = malloc( sizeof( *a ) );
	a->description = strdup(description);
	a->date_created = time(NULL);

	g_log("tm_a", G_LOG_LEVEL_DEBUG, "Created activity: %p - %s\n", a, a->description);
	tm_a_create(ACTIVITY, a);

	return a;
}

struct activity*
tm_a_activity_update(int id, char* description)
{
	struct activity* a = tm_a_read(ACTIVITY, id);
	
	if (a != NULL)
	{
		free(a->description);
		a->description = strdup(description);
	}

	return a;
}

int
tm_a_activity_delete(int id)
{
	return tm_a_delete(ACTIVITY, id);
}

