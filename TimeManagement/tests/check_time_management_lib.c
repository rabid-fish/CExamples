#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <check.h>
#include "../lib/tm_lib.h"

START_TEST (test_activity)
{
	tma_activity_create("one");
	tma_activity_create("two");
	tma_activity_create("three");

	tma_activity_update(2, "numero dos");

	struct activity* a = tma_activity_read(2);
	char* description = a->description;
	// assert message equals "numero dos"

	tma_cleanup();
}
END_TEST

START_TEST (test_tag)
{
	tma_tag_create("one");
	tma_tag_create("two");
	tma_tag_create("three");

	tma_tag_update(2, "numero dos");

	struct tag* t = tma_tag_read(2);
	char* description = t->description;
	// assert message equals "numero dos"

	tma_cleanup();
}
END_TEST

Suite *
time_management_suite()
{
	Suite *s = suite_create("Time Management");
	TCase *tc_time_management = tcase_create("Time Management");
	
	tcase_add_test(tc_time_management, test_activity);
	tcase_add_test(tc_time_management, test_tag);
	
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
