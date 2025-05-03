#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "triangle.h"

static void test_calculation(void **state) {
    (void)state;
    assert_int_equal(triangularNumberRecursive(1), 1);
    assert_int_equal(triangularNumberRecursive(5), 15);
    assert_int_equal(triangularNumberRecursive(10), 55);}

static void test_validation(void **state) {
    (void)state;
    char *valid[] = {"program", "5"};
    assert_true(validateInput(2, valid));
    char *invalid[] = {"program"};
    assert_false(validateInput(1, invalid));}

static void test_parsing(void **state) {
    (void)state;
    assert_int_equal(parseInput("5"), 5);
    assert_int_equal(parseInput("0"), 0);
    assert_int_equal(parseInput("abc"), 0);}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_calculation),
        cmocka_unit_test(test_validation),
        cmocka_unit_test(test_parsing),};
    return cmocka_run_group_tests(tests, NULL, NULL);}