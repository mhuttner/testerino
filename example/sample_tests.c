#include "../src/testerino.h"

void test_nothing(struct test *t) {
  t_set_msg(t, "Testing nothing...");
  t_log(t, "This test should always succeed");
  t_assert(t, 1 == 1);
}

void test_nothing_and_fail(struct test *t) {
  t_set_msg(t, "Testing failing at nothing...");
  t_log(t, "This test should always fail");
  t_assert_msg(t, 1 == 2, "1 does not equal 2");
}

void test_failing_with_long_log(struct test *t) {
  t_set_msg(t, "Testing failing with a long log...");
  t_log(t, "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do "
           "eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut "
           "enim ad minim veniam, quis nostrud exercitation ullamco laboris "
           "nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor "
           "in reprehenderit in voluptate velit esse cillum dolore eu fugiat "
           "nulla pariatur. Excepteur sint occaecat cupidatat non proident, "
           "sunt in culpa qui officia deserunt mollit anim id est laborum.");
  t_assert_msg(t, 1 == 2, "this is expected");
}

void test_long_test_msg(struct test *t) {
  t_set_msg(t, "Testing a very long test message to see if spacing works "
               "correcly... bla bal bla");
  t_log(t, "This test should always succeed");
  t_assert(t, 1 == 1);
}

/**
 * tests are defined by being a function returning void and accepting a
 * "struct test*" as their single argument */
void this_is_a_unit_test(struct test *t) {
  /**
   * First set the message that should be shown in the test log when running the
   * tests
   */
  t_set_msg(t, "This is an example test message...");

  /**
   * Log important test information, it will be shown in the test log if the
   * test fails.
   * Works like printf but take the test pointer as it's first argument.
   */
  t_log(t, "This is important test information %d", 42);

  /**
   * Assert one or more conditions using this function. If one or more of the
   * asserts fail the test case fails.
   */
  t_assert(t, 1 == 1);
  /**
   * Optionally assert with an error message that will be shown if this assert
   * fails.
   */
  t_assert_msg(t, 1 == 2, "1 does not equal 2");
}