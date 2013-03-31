#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>
#include "time_management_lib.h"

GSList* list_activities = NULL;

GSList*
tm_a_activity_read_all()
{
	return list_activities;
}

struct activity*
tm_a_activity_read(int index)
{
	int i = 1;
	GSList* current = list_activities;
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
tm_a_activity_create(char* message)
{
	struct activity* a = malloc( sizeof( *a ) );
	a->message = strdup(message);
	g_log("tm_a", G_LOG_LEVEL_DEBUG, "Created activity: %p - %s\n", a, a->message);

	list_activities = g_slist_append(list_activities, a);

	return a;
}

struct activity*
tm_a_activity_update(int index, char* message)
{
	struct activity* a = tm_a_activity_read(index);
	
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
tm_a_activity_delete(int index)
{
	int success = 0;
	struct activity* a = tm_a_activity_read(index);

	if (a != NULL)
	{
		g_log("tm_a", G_LOG_LEVEL_DEBUG, "Removing from list %p - %s\n", a, a->message);
		list_activities = g_slist_remove(list_activities, a);
		tm_a_destroy_activity(a);
		success = 1;
	}
	
	return success;
}

void
tm_a_cleanup()
{
	g_log("tm_a", G_LOG_LEVEL_DEBUG, "The list is %d items long prior to cleanup\n", g_slist_length(list_activities));

	int i;
	GSList* current = list_activities;
	while (current != NULL)
	{
		g_log("tm_a", G_LOG_LEVEL_DEBUG, "Freeing up another struct\n");
		tm_a_destroy_activity(current->data);
		current = current->next;
	}

	g_slist_free(list_activities);
}


