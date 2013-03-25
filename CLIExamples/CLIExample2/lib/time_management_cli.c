#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

void
tm_c_execute(char* message)
{
	printf("Pointer: %p\n", message);
	printf("Message: %s\n", message);
}

