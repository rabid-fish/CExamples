#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>

GSList* list = NULL;

struct activity
{
	char* message;
};

void
tm_a_display_activities()
{
	int i = 0;
	GSList* current = list;
	struct activity* a;
	int length = g_slist_length(list);
	
	if (length == 0)
	{
		printf("\nNo activities to display\n");
		return;
	}

	printf("\nActivity list\n");
	while (current != NULL)
	{
		a = current->data;
		g_log("tm_a", G_LOG_LEVEL_DEBUG, "Current activity: %p - %s\n", a, a->message);
		printf(" #%d : %s\n", ++i, a->message);
		current = current->next;
	}
}

struct activity*
tm_a_create(char* message)
{
	struct activity* a = malloc( sizeof( *a ) );
	a->message = strdup(message);
	g_log("tm_a", G_LOG_LEVEL_DEBUG, "Created activity: %p - %s\n", a, a->message);
	return a;
}

void
tm_a_choose_create()
{
	int entries;
	struct activity* a;
	char* message = malloc(sizeof(char) * 50);
	
	printf("Description of the activity: ");
	entries = scanf("%49s", message);
	g_log("tm_a", G_LOG_LEVEL_DEBUG, "Entries: %d, message: %s\n", entries, message);
	if (entries == 0) return;

	a = tm_a_create(message);
	list = g_slist_append(list, a);
}

void
tm_a_choose_edit()
{
	
}

void
tm_a_destroy_activity(struct activity* a)
{
	free(a->message);
	free(a);
}

tm_a_destroy_activities()
{
	int i;
	GSList* current = list;
	while (current != NULL)
	{
		g_log("tm_a", G_LOG_LEVEL_DEBUG, "Freeing up another struct\n");
		tm_a_destroy_activity(current->data);
		current = current->next;
	}
}

void
tm_a_remove(int index)
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

	if (current == NULL)
	{
		printf("Item not found\n");
	}
	else
	{
		g_log("tm_a", G_LOG_LEVEL_DEBUG, "Removing from list %p - %s\n", a, a->message);
		list = g_slist_remove(list, a);
		tm_a_destroy_activity(a);
	}
}

void
tm_a_choose_remove()
{
	int entries;
	int index = 0;
	
	printf("Id of the activity to remove: ");
	entries = scanf("%d", &index);
	if (entries == 0) return;

	tm_a_remove(index);
}

void
tm_a_list_execute()
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
		
		g_log("tm_a", G_LOG_LEVEL_DEBUG, "You chose #%d\n", choice);

		if (choice == 1)
		{
			tm_a_choose_create();
		}
		else if (choice == 2)
		{
			break;
		}
		else if (choice == 3)
		{
			tm_a_choose_remove();
		}
		else
		{
			break;
		}

		tm_a_display_activities();
	}

	g_log("tm_a", G_LOG_LEVEL_DEBUG, "The list is %d items long prior to cleanup\n", g_slist_length(list));
	tm_a_destroy_activities();
	g_slist_free(list);
}

void
tm_a_execute(char* message)
{
	tm_a_list_execute();
}

