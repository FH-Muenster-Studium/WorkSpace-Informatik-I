/*
 * tests.c
 *
 *  Created on: 13.12.2016
 *      Author: fabianterhorst
 */

#include "tests.h"
#include "Praktikum4.h"

void test_file_open_success() {
	assert(fopen("/Users/fabianterhorst/bla.txt", "r"));
}

void test_file_open_error() {
	assert(fopen("/Users/fabianterhorst/bla2.txt", "r") == NULL);
}

void test_randomize_length() {
	long values[RANDOM_LENGTH][KEY_VALUE];
	randomize(values);
	long size = sizeof(values) / (sizeof(long) * KEY_VALUE);
	assert(size == RANDOM_LENGTH);
	for (int i = 0;i < size;i++) {
		assert(values[i][0] >= 0 && values[i][0] <= size);
		assert(values[i][1] >= 0 && values[i][1] <= 1000);
	}
}

void run_all_tests() {
	test_file_open_success();
	test_file_open_error();
	test_randomize_length();
}
