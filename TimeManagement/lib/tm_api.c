#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>
#include "tm_internal.h"

GSList* list_activity = NULL;
GSList* list_tag = NULL;
GSList* list_xta = NULL;

void
tma_initialize()
{
	tma_xta_initialize();
}

GSList*
tma_list(enum model_t model)
{
	GSList* list = NULL;
	
	switch (model)
	{
		case ACTIVITY:
			list = list_activity;
			break;
		case TAG:
			list = list_tag;
			break;
		case XTA:
			list = list_xta;
			break;
	}

	return list;
}

void*
tma_read(enum model_t model, int id)
{
	int i = 1;
	GSList* current = tma_list(model);
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
tma_create(enum model_t model, void* node)
{
	switch (model)
	{
		case ACTIVITY:
			list_activity = g_slist_append(list_activity, node);
			break;
		case TAG:
			list_tag = g_slist_append(list_tag, node);
			break;
		case XTA:
			list_xta = g_slist_append(list_xta, node);
			break;
	}

	return node;
}

int
tma_free(enum model_t model, void* node)
{
	int success = 0;
	g_log("tma", G_LOG_LEVEL_DEBUG, "Removing from list and freeing %i - %p", model, node);
	
	switch (model)
	{
		case ACTIVITY:
			list_activity = g_slist_remove(list_activity, node);
			free(((struct activity*) node)->description);
			success = 1;
			break;
		case TAG:
			list_tag = g_slist_remove(list_tag, node);
			free(((struct tag*) node)->description);
			success = 1;
			break;
		case XTA:
			list_xta = g_slist_remove(list_xta, node);
			success = 1;
			break;
	}

	free(node);

	return success;
}

int
tma_delete(enum model_t model, int id)
{
	int success = 0;
	void* node = tma_read(model, id);

	if (node != NULL)
	{
		tma_free(model, node);
	}
	
	return success;
}

void
tma_cleanup()
{
	const int LIST_MAX = sizeof(enum model_t) - 1;

	GSList* lists[LIST_MAX];
	lists[0] = list_activity;
	lists[1] = list_tag;
	lists[2] = list_xta;

	int i = 0;
	for (i = 0; i < LIST_MAX; i++)
	{
		GSList* list = lists[i];

		g_log("tma", G_LOG_LEVEL_DEBUG, "The list for enum %d is %d items long prior to cleanup", i, g_slist_length(list));

		GSList* current = list;
		GSList* buffer = NULL;
		while (current != NULL)
		{
			buffer = current->next;
			tma_free(i, current->data);
			current = buffer;
		}

		g_slist_free(list);
	}
}

