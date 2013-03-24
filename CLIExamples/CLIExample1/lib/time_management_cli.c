#include <stdlib.h>
#include <glib.h>

char input[50];

void
tm_c_execute()
{
	printf("Please enter some text:");
	scanf("%50s", input);
	printf("You entered %s\n", input);
}

