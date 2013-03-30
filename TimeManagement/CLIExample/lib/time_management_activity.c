#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>
#include "time_management_lib.h"

GSList* list = NULL;

GSList*
tm_a_read_all()
{
	return list;
}

struct activity*
tm_a_read(int index)
{
	int i = 1;
	GSList* current = list;
	struct activity* a = current == NULL ? NULL : current->data;

	while (i++ < index)
	{
		current = current->next;
 		a = current == NULL ? NULL : current->data;
		if (current == NULL) break;
	}
	
	return a;
}

struct activity*
tm_a_create(char* message)
{
	struct activity* a = malloc( sizeof( *a ) );
	a->message = strdup(message);
	g_log("tm_a", G_LOG_LEVEL_DEBUG, "Created activity: %p - %s\n", a, a->message);

	list = g_slist_append(list, a);

	return a;
}

struct activity*
tm_a_update(int index, char* message)
{
	struct activity* a = tm_a_read(index);
	
	if (a != NULL)
	{
		free(a->message);
		a->message = strdup(message);
	}

	return a;
}

void
tm_a_destroy_activity(struct activity* a)
{
	free(a->message);
	free(a);
}

int
tm_a_delete(int index)
{
	int success = 0;
	struct activity* a = tm_a_read(index);

	if (a != NULL)
	{
		g_log("tm_a", G_LOG_LEVEL_DEBUG, "Removing from list %p - %s\n", a, a->message);
		list = g_slist_remove(list, a);
		tm_a_destroy_activity(a);
		success = 1;
	}
	
	return success;
}

void
tm_a_cleanup()
{
	g_log("tm_a", G_LOG_LEVEL_DEBUG, "The list is %d items long prior to cleanup\n", g_slist_length(list));

	int i;
	GSList* current = list;
	while (current != NULL)
	{
		g_log("tm_a", G_LOG_LEVEL_DEBUG, "Freeing up another struct\n");
		tm_a_destroy_activity(current->data);
		current = current->next;
	}

	g_slist_free(list);
}


