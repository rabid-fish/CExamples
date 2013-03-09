#include <stdlib.h>
#include <string.h>
#include <check.h>
#include "../src/example.h"

START_TEST (test_printMessage1)
{
	printMessage1();
	
	return 0;
}
END_TEST

START_TEST (test_printMessage2)
{
	printMessage2();
	
	return 0;
}
END_TEST

Suite * example_suite()
{
	Suite *s = suite_create("Example");
	TCase *tc_example = tcase_create("Example");
	
	tcase_add_test (tc_example, test_printMessage1);
	tcase_add_test (tc_example, test_printMessage2);
	
	suite_add_tcase (s, tc_example);
	
	return s;
}

// Written with much help from
// http://check.sourceforge.net/doc/check_html/check_3.html
int main ()
{
	printf("Running tests\n");
	
	int number_failed;
	Suite *s = example_suite ();
	SRunner *sr = srunner_create (s);
	srunner_run_all (sr, CK_NORMAL);
	number_failed = srunner_ntests_failed (sr);
	srunner_free (sr);
	
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
