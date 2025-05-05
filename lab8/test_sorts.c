#include <stddef.h>
#include <stdarg.h>
#include <setjmp.h>
#include <stdio.h>
#include <string.h>
#include <cmocka.h>
#include "sort.h"

void test_knuth_sequence(void **state) {
    (void)state;
    int seq[20], size;
    generateKnuthSequence(10, seq, &size);
    assert_int_equal(seq[0], 1);
    assert_int_equal(seq[1], 4);}

void test_insertion_sort(void **state) {
    (void)state;
    int arr[] = {5, 2, 4, 6, 1, 3};
    int expected[] = {1, 2, 3, 4, 5, 6};
    int M = 0, C = 0;
    insertionSort(arr, 6, &M, &C);
    assert_memory_equal(arr, expected, sizeof(arr));
    assert_true(M>0);
    assert_true(C>0);}

void test_shell_sort(void **state) {
    (void)state;
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    int expected[] = {0,1,2,3,4,5,6,7,8,9};
    int M = 0, C = 0;
    shellSort(arr, 10, &M, &C);
    assert_memory_equal(arr, expected, sizeof(arr));
    assert_true(M > 0);
    assert_true(C > 0);}

void test_generate_array(void **state) {
    (void)state;
    int arr[100];
    generateArray(arr, 100);
    for (int i = 0; i < 100; i++) {
        assert_true(arr[i] >= 0 && arr[i] < 1000);}
    int is_constant = 1;
    for (int i = 1; i < 100; i++) {
        if (arr[i] != arr[0]) {
            is_constant = 0;
            break;}}
    assert_false(is_constant);}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_knuth_sequence),
        cmocka_unit_test(test_insertion_sort),
        cmocka_unit_test(test_shell_sort),
        cmocka_unit_test(test_generate_array),};
    return cmocka_run_group_tests(tests, NULL, NULL);}
