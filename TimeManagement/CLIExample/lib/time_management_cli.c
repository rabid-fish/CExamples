#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "time_management_lib.h"

void
tm_c_choose_create()
{
	int entries;
	char* description = malloc(sizeof(char) * 50);
	
	printf("Description of the activity: ");
	entries = scanf("%49s", description);
	g_log("tm_c", G_LOG_LEVEL_DEBUG, "Create entries: %d, description: %s\n", entries, description);
	if (entries == 0) return;

	tm_a_activity_create(description);
}

void
tm_c_choose_read_all()
{
	int i = 0;
	struct activity* a;
	GSList* current = tm_a_activity_read_all();
	int length = g_slist_length(current);
	
	if (length == 0)
	{
		printf("\nNo activities to display\n");
		return;
	}

	printf("\nActivity list\n");
	while (current != NULL)
	{
		a = current->data;
		g_log("tm_c", G_LOG_LEVEL_DEBUG, "Current activity: %p - %s\n", a, a->description);
		printf(" #%d : %s\n", ++i, a->description);
		current = current->next;
	}
}

void
tm_c_choose_update()
{
	int entries;
	int id = 0;
	
	printf("Id of the activity to edit: ");
	entries = scanf("%d", &id);
	if (entries == 0) return;

	struct activity* a;
	char* description = malloc(sizeof(char) * 50);
	
	printf("Description of the activity: ");
	entries = scanf("%49s", description);
	g_log("tm_c", G_LOG_LEVEL_DEBUG, "Edit entries: %d, id: %d, description: %s\n", entries, id, description);
	if (entries == 0) return;

	a = tm_a_activity_update(id, description);
	if (a == NULL)
	{
		printf("Item not found\n");
	}
}

void
tm_c_choose_delete()
{
	int entries;
	int id = 0;
	
	printf("Id of the activity to remove: ");
	entries = scanf("%d", &id);
	if (entries == 0) return;

	int success = tm_a_activity_delete(id);
	if (!success)
	{
		printf("Item not found\n");
	}
}

void
tm_c_execute()
{
	while (1)
	{
		// start asking the user for choices
		printf("\nPlease choose one of the following options:\n");
		printf(" 1) Add a new activity\n");
		printf(" 2) Edit an activity\n");
		printf(" 3) Remove an activity\n");
		printf("choice: ");

		int choice;
		int entries;

		entries = scanf("%d", &choice);
		if (entries == 0) break;
		
		g_log("tm_c", G_LOG_LEVEL_DEBUG, "You chose #%d\n", choice);

		if (choice == 1)
		{
			tm_c_choose_create();
		}
		else if (choice == 2)
		{
			tm_c_choose_update();
		}
		else if (choice == 3)
		{
			tm_c_choose_delete();
		}
		else
		{
			break;
		}

		tm_c_choose_read_all();
	}

	tm_a_cleanup();
}

