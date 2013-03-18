#include <stdlib.h>
#include <stdio.h>

struct Activity
{
	int id;
	char *description;
//	char *keywords;
};

void
tm_a_pass_array_1(int *xp, int size)
{
	int i = 0;
	int sum = 0;
	
	for (i = 0; i < size; i++)
	{
		printf("  > loop #%i value %i\n", i, xp[i]);
		sum += xp[i];
	}
	
	printf("The value is: %i \n", sum);
}

void 
tm_a_print(char *message)
{
	int x[] = { 5, 2, 9 };
	int size = sizeof(x) / sizeof(x[0]);
	passArray1(x, size);
	
//	passArray2("Boom shakalaka\n");
	printf(message);
}

/*
  tm_a_activity_create
  tm_a_activity_read
  tm_a_activity_update
  tm_a_activity_delete
*/

void
tm_a_activity_create(int id, const char *description)
{
//	struct Activity a;
//	a.id = id;
	
}
