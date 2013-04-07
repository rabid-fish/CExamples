#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>
#include <check.h>
#include "../lib/tm_lib.h"

START_TEST (test_activity_create)
{
	GSList* list = tma_activity_read_all();
	int length = g_slist_length(list);
	ck_assert(length == 3);
}
END_TEST

START_TEST (test_activity_update)
{
	tma_activity_update(2, "numero dos");
	struct activity* a = tma_activity_read(2);
	char* description = a->description;
	ck_assert(strcmp(description, "numero dos") == 0);
}
END_TEST

START_TEST (test_tag_create)
{
	GSList* list = tma_tag_read_all();
	int length = g_slist_length(list);
	ck_assert(length == 3);
}
END_TEST

START_TEST (test_tag_update)
{
	tma_tag_update(2, "numero dos");

	struct tag* t = tma_tag_read(2);
	char* description = t->description;
	ck_assert(strcmp(description, "numero dos") == 0);
}
END_TEST

START_TEST (test_xta_create)
{
	GSList* list = tma_xta_read_all();
	int length = g_slist_length(list);
	ck_assert(length == 3);
}
END_TEST

void
time_management_activity_setup()
{
	tma_activity_create("one");
	tma_activity_create("two");
	tma_activity_create("three");
}

void
time_management_tag_setup()
{
	tma_tag_create("one");
	tma_tag_create("two");
	tma_tag_create("three");
}

void
time_management_xta_setup()
{
	tma_xta_create(1, 1);
	tma_xta_create(1, 2);
	tma_xta_create(1, 3);
}

void
time_management_teardown()
{
	tma_cleanup();
}

Suite *
time_management_suite()
{
	Suite *s = suite_create("Time Management");

/*
	TCase *tc_time_management_activity = tcase_create("Time Management Activity");
	tcase_add_checked_fixture(tc_time_management_activity, time_management_activity_setup, time_management_teardown);
	tcase_add_test(tc_time_management_activity, test_activity_create);
	tcase_add_test(tc_time_management_activity, test_activity_update);
	suite_add_tcase(s, tc_time_management_activity);

	TCase *tc_time_management_tag = tcase_create("Time Management Tag");
	tcase_add_checked_fixture(tc_time_management_tag, time_management_tag_setup, time_management_teardown);
	tcase_add_test(tc_time_management_tag, test_tag_create);
	tcase_add_test(tc_time_management_tag, test_tag_update);
	suite_add_tcase(s, tc_time_management_tag);
*/

	TCase *tc_time_management_xta = tcase_create("Time Management Tag");
	tcase_add_checked_fixture(tc_time_management_xta, time_management_xta_setup, time_management_teardown);
	tcase_add_test(tc_time_management_xta, test_xta_create);
//	tcase_add_test(tc_time_management_xta, test_xta_update);
	suite_add_tcase(s, tc_time_management_xta);
	
	return s;
}

int main()
{
	printf("Running tests\n");
	
	int number_failed;
	Suite *s = time_management_suite();
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
