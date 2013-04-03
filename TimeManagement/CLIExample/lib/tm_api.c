#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>
#include "tm_internal.h"

GSList* list_activities = NULL;
GSList* list_tags = NULL;


GSList*
tm_a_list(enum model_t model)
{
	switch (model)
	{
		case ACTIVITY:
			return list_activities;
		case TAG:
			return list_tags;
	}

	return NULL;
}

void*
tm_a_read(enum model_t model, int id)
{
	int i = 1;
	GSList* current = tm_a_list(model);
	void* node = current == NULL ? NULL : current->data;

	while (i++ < id)
	{
		current = current->next;
 		node = current == NULL ? NULL : current->data;
		if (current == NULL) break;
	}
	
	return node;
}

void*
tm_a_create(enum model_t model, void* node)
{
	switch (model)
	{
		case ACTIVITY:
			list_activities = g_slist_append(list_activities, node);
			break;
		case TAG:
			list_tags = g_slist_append(list_tags, node);
			break;
	}

	return node;
}

int
tm_a_free(enum model_t model, void* node)
{
	int success = 0;
	g_log("tm_a", G_LOG_LEVEL_DEBUG, "Removing from list and freeing %p\n", node);

	switch (model)
	{
		case ACTIVITY:
			list_activities = g_slist_remove(list_activities, node);
			free(((struct activity*) node)->description);
			success = 1;
			break;
		case TAG:
			list_tags = g_slist_remove(list_tags, node);
			free(((struct tag*) node)->description);
			success = 1;
			break;
	}

	free(node);

	return success;
}

int
tm_a_delete(enum model_t model, int id)
{
	int success = 0;
	void* node = tm_a_read(model, id);

	if (node != NULL)
	{
		tm_a_free(model, node);
	}
	
	return success;
}

void
tm_a_cleanup()
{
	GSList* lists[2];
	lists[0] = list_activities;
	lists[1] = list_tags;

	enum model_t models[2];
	models[0] = ACTIVITY;
	models[1] = TAG;

	int i = 0;
	int max = 2;
	for (i = 0; i < max; i++)
	{
		GSList* list = lists[i];
		enum model_t model = models[i];

		g_log("tm_a", G_LOG_LEVEL_DEBUG, "The list is %d items long prior to cleanup\n", g_slist_length(list));

		int i;
		GSList* current = list;
		while (current != NULL)
		{
			tm_a_free(model, current->data);
			current = current->next;
		}

		g_slist_free(list);
	}
}

