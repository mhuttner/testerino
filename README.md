testerino
=========

Simple unit testing framework for C

### How to use:
The testerino framework simply uses two small C files you can build with your project.
Simply include testerino.h and testerino.c into your build and you are good to go.  

### To build the example:

To compile the example with gcc simply run:
  

Unix/Macintosh:

```sh
gcc -o testerino_example example/main.c example/sample_tests.c src/testerino.c
```

### How to create Tests:

```c


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

```

### How to run tests:

```c


int main(int argc, char const *argv[]) {
  /* Create a test suite */
  struct test_suite *s = NULL;
  create_test_suite(&s);
  /* Add your test function to the suite */
  suite_add_test(s, this_is_a_unit_test);
  /* Run the tests */
  suite_run_all_tests(s);
  /* cleanup */
  free_suite(s);
  return 0;
}

```

For a complete example see the example folder.

