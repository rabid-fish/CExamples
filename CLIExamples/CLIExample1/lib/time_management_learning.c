#include <stdlib.h>
#include <stdio.h>

typedef struct tm_l_contact {
	int id;
	char *name;
} CONTACT;

void
tm_l_struct()
{
	CONTACT c1 = { 1, "John Deer" };
	CONTACT c2 = c1;
//	struct point *c3 = 

	printf("=====\nRunning tm_l_struct\n");
	printf("CONTACT c = { 1, \"John Deer\" };\n");
	printf("Contact name: %s\n", c1.name);
	printf("Contact name: %s\n", c2.name);
}

void
tm_l_int_pointer()
{
	int *values = { 4, 6, 9, 1, 3, 7 };
	
	// assign to primitive variable
	int a = values[2];
	int b = *(values + 2);
	
	// assign to pointer
	int *c = values[2];  // this is a bad idea
	int *d = &values[2]; // assigns the position starting at 2
	
	// assign to array
//	int e[] = values;     // fails on compiler check
//	int f[] = values[2];  // fails on compiler check
//	int g[] = &values[2]; // fails on compiler check
	
/*
	All of the following commented out statements at runtime,
	no idea why. Many of the runtime failures are SIG 11, 
	trying to access memory that was not assigned.
*/
	
	printf("=====\nRunning tm_l_int_pointer\n");
	printf("int *values = { 4, 3, 9, 1, 7, 6 };\n");
//	printf("Primitive int at position 2: %i\n", a);
//	printf("Primitive int at position 2: %i\n", b);
	
//	printf("Pointer to second array position: %i\n", c);
//	printf("Pointer to second array position with pointer arith wtf: %i\n", (c + 2));
//	printf("Pointer to second array position with bracket notation: %i\n", c[2]);
//	printf("Dereferenced pointer to second array position: %i\n", *c);
	
	printf("Pointer to mem loc of second array position: %i\n", d);
	printf("Pointer to mem loc of second array position plus 2: %i\n", (d + 2));
//	printf("Pointer to mem loc of second array position with bracket notation: %i\n", d[2]);
//	printf("Deref pointer to mem loc of second array position: %i\n", *d);
//	printf("Deref pointer to mem loc of second array position with pointer arith: %i\n", *(d + 2));
}

void
tm_l_int_pointer_extended()
{
	int *values = { 4, 3, 9, 1, 7, 6 };
	
	int a = values;
	int b = values + 2;
	int c = (values + 2);
	int d = *(values + 2);
	int e = values[2];

	printf("=====\nRunning tm_l_int_pointer_extended\n");
	printf("int *values = { 4, 3, 9, 1, 7, 6 };\n");
	printf("Primitive int at position 0: %i\n", a);
	printf("Primitive int at position 0 + 2 wtf: %i\n", b);
	printf("Primitive int pointer arith wtf: %i\n", c);
//	printf("Primitive int deref pointer arith: %i\n", d); // fail, dunno why
//	printf("Primitive int at position 2 with bracket notation: %i\n", e); // fail, dunno why
}

void
tm_l_int_array()
{
	int values[] = { 4, 6, 9, 1, 3, 7 };
	
	// assign to primitive variable
	int a = values[2];
	int b = *(values + 2);
	
	// assign to pointer
	int *c = values[2];  // this is a bad idea
	int *d = &values[2]; // assigns the position starting at 2
	
	// assign to array
//	int e[] = values;     // fails on compiler check
//	int f[] = values[2];  // fails on compiler check
//	int g[] = &values[2]; // fails on compiler check
	
	printf("=====\nRunning tm_l_int_array\n");
	printf("int values[] = { 4, 3, 9, 1, 7, 6 };\n");
	printf("Primitive int at position 2: %i\n", a);
	printf("Primitive int at position 2: %i\n", b);
	
	printf("Pointer to second array position: %i\n", c);
	printf("Pointer to second array position with pointer arith wtf: %i\n", (c + 2)); // wtf is this?
//	printf("Pointer to second array position with bracket notation: %i\n", c[2]); // fail
//	printf("Dereferenced pointer to second array position: %i\n", *c); // fail
	
	printf("Pointer to mem loc of second array position: %i\n", d);
	printf("Pointer to mem loc of second array position plus 2: %i\n", (d + 2));
	printf("Pointer to mem loc of second array position with bracket notation: %i\n", d[2]);
	printf("Deref pointer to mem loc of second array position: %i\n", *d);
	printf("Deref pointer to mem loc of second array position with pointer arith: %i\n", *(d + 2));
}

int*
tm_l_int_array_return(int *values)
{
	printf("Called int array pointer:%i\n", values);
	printf("Called int array deref first position:%i\n", *values);
	printf("Called int array bracketed first position:%i\n", values[0]);
	printf("Called int array bracketed second position wtf:%i\n", values[1]);
	printf("Called int array arith second position wtf:%i\n", (values + 1));
	return values;
}

void
tm_l_int_array_call()
{
	int *values1 = { 4, 3, 9, 1, 7, 6 };
	int *values2;

	printf("=====\nRunning tm_l_int_array_call\n");
	printf("int *values1 = { 4, 3, 9, 1, 7, 6 };\n");
	values2 = tm_l_int_array_return(&values1);
	
	printf("Returned int array first position:%i\n", values1);
	printf("Returned int array first position:%i\n", *values2);
//	printf("Returned int array second position:%i\n", *(values2 + 1));
}

void
tm_l_char_pointer()
{
	char *message = "hello";
	char a = message[2];
	char b = *(message + 2);
	char c = (message + 2);
	char *d = message[2];
	char *e = (message + 2);
	char *f = *(message + 2);
//	char g[] = message[2]; // fails on compiler check
//	char h[] = (message + 2); // fails on compiler check

	printf("=====\nRunning tm_l_char_pointer\n");
	printf("char *message = \"hello\";\n");
	printf("Character at position 2:%c\n", a);
	printf("Character at position 2:%c\n", b);
	printf("Character at position 2 wtf:%c\n", c); // this prints out weirdness
	printf("Character at position 2:%c\n", d);
//	printf("String starting at position 2:%s\n", d); // fail at runtime, dunno why
	printf("String starting at position 2:%s\n", e);
//	printf("String starting at position 2:%s\n", f); // fail at runtime, dunno why
}

void
tm_l_char_pointer_parameter(char *message)
{
	char a = message[2];
	char b = *(message + 2);
	char c = (message + 2);
	char *d = message[2];
	char *e = (message + 2);
	char *f = *(message + 2);
//	char g[] = message[2]; // fails on compiler check
//	char h[] = (message + 2); // fails on compiler check

	printf("=====\nRunning tm_l_char_pointer_parameter\n");
	printf("tm_l_char_pointer_parameter(char *message)\n");
	printf("Character at position 2:%c\n", a);
	printf("Character at position 2:%c\n", b);
	printf("Character at position 2 wtf:%c\n", c); // this prints out weirdness
	printf("Character at position 2:%c\n", d);
//	printf("String starting at position 2:%s\n", d); // fail at runtime, dunno why
	printf("String starting at position 2:%s\n", e);
//	printf("String starting at position 2:%s\n", f); // fail at runtime, dunno why
}

void
tm_l_char_array()
{
	char message[] = "hello";
	char a = message[2];
	char b = *(message + 2);
	char c = (message + 2);
	char *d = message[2];
	char *e = (message + 2);
	char *f = *(message + 2);
//	char g[] = message[2]; // fails on compiler check
//	char h[] = (message + 2); // fails on compiler check

	printf("=====\nRunning tm_l_char_array\n");
	printf("char message[] = \"hello\";\n");
	printf("Character at position 2:%c\n", a);
	printf("Character at position 2:%c\n", b);
	printf("Character at position 2 wtf:%c\n", c); // this prints out weirdness
	printf("Character at position 2:%c\n", d);
//	printf("String starting at position 2:%s\n", d); // fail at runtime, dunno why
	printf("String starting at position 2:%s\n", e);
//	printf("String starting at position 2:%s\n", f); // fail at runtime, dunno why
}

void
tm_l_char_array_parameter(char message[])
{
	char a = message[2];
	char b = *(message + 2);
	char c = (message + 2);
	char *d = message[2];
	char *e = (message + 2);
	char *f = *(message + 2);
//	char g[] = message[2]; // fails on compiler check
//	char h[] = (message + 2); // fails on compiler check

	printf("=====\nRunning tm_l_char_array_parameter\n");
	printf("tm_l_char_array_parameter(char message[])\n");
	printf("Character at position 2:%c\n", a);
	printf("Character at position 2:%c\n", b);
	printf("Character at position 2:%c\n", c); // this prints out weirdness
	printf("Character at position 2:%c\n", d);
//	printf("String starting at position 2:%s\n", d); // fail at runtime, dunno why
	printf("String starting at position 2:%s\n", e);
//	printf("String starting at position 2:%s\n", f); // fail at runtime, dunno why
}

char*
tm_l_char_array_return(char *str)
{
	return str;
}

void
tm_l_char_array_call()
{
	char *message1 = "hello";
	char *message2;
	message2 = tm_l_char_array_return(message1);
	
	printf("=====\nRunning tm_l_char_array_call\n");
	printf("char *message1 = \"hello\";\n");
	printf("Returned string:%s\n", message2);
}

void
tm_l_execute(char *message)
{
	/*
	tm_l_int_pointer();
	tm_l_int_pointer_extended();
	tm_l_int_array();
	
	tm_l_int_array_call();
	
	tm_l_char_pointer();
	tm_l_char_pointer_parameter("hello");

	tm_l_char_array();
	tm_l_char_array_parameter("hello");
	
	tm_l_char_array_call();
	*/
	tm_l_struct();
}
