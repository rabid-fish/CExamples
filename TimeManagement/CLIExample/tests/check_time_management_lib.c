#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <check.h>
#include "../src/time_management_lib.h"

START_TEST (test_execute)
{
	tm_c_execute("Hello from tests");	
}
END_TEST

Suite *
time_management_suite()
{
	Suite *s = suite_create("Time Management");
	TCase *tc_time_management = tcase_create("Time Management");
	
	tcase_add_test(tc_time_management, test_execute);
	
	suite_add_tcase(s, tc_time_management);
	
	return s;
}

int main()
{
	printf("Running tests\n");
	
	int number_failed;
	Suite *s = time_management_suite ();
	SRunner *sr = srunner_create (s);
	srunner_run_all (sr, CK_NORMAL);
	number_failed = srunner_ntests_failed (sr);
	srunner_free (sr);
	
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
