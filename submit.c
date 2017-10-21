#include "submit.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN_REPEAT_COUNT 20
	
void submit(int (*f) (void), char *questionString) {
	clock_t start = clock();
	int success = f();
	
	printf(success ? "[Success] %s\n" : "[Failure] %s\n", questionString);
	printf("Elapsed time: %.2f seconds\n", (float) (clock() - start) / CLOCKS_PER_SEC);
}

void submit_cases(
		char *title, 
		void **test_cases, char test_titles[][50], int test_case_count,
		void *(*algo) (void *test_case), 
		int (*assess) (void *result)) {
	int total_success = 1;

	printf("Testing Algorithm: %s\n", title);
	printf("\n");
	
	for (int i = 0; i < test_case_count; ++ i) {
		clock_t old_clock = clock();
		clock_t elapsed_time;

		void *result = algo(test_cases[i]);

		elapsed_time = clock() - old_clock;

		int success = assess(result);
		total_success &= success;

		printf("\tTest Case #%02d: %s\n", i + 1, test_titles[i]);
		printf("\tResult: %s\n", success ? "Success" : "Failure");
		printf("\tElapsed Time: %.3f\n", (float) elapsed_time / CLOCKS_PER_SEC);
		printf("\n");
	}

	printf("Result: %s\n", total_success ? "Success" : "Failure");
}

void submit_cases_repeatedly(
		char *title, 
		void *load_test_case(int index), 
		void load_test_title(int index, char test_title[50]), 
		int test_case_count,
		void *(*algo) (void *test_case), 
		int (*assess) (void *result, int index),
		void (*free_all) (void *test_case, void *result)) {

	int total_success = 1;
	char test_title[50];

	printf("Testing Algorithm: %s\n", title);
	printf("\n");
	
	for (int i = 0; i < test_case_count; ++ i) {
		clock_t elapsed_time = 0;
		clock_t first_clock = clock();
		int repeat;
		int success;

		for (repeat = 0; (float) (clock() - first_clock) / CLOCKS_PER_SEC < 0.1 || repeat < MIN_REPEAT_COUNT; ++ repeat) {
			void *test_case = load_test_case(i);
			
			clock_t old_clock = clock();
			void *result = algo(test_case);
			elapsed_time += clock() - old_clock;

			success = assess(result, i);
			total_success &= success;
			
			free_all(test_case, result);
		}

		load_test_title(i, test_title);
		printf("\tTest Case #%02d: %s\n", i + 1, test_title);
		printf("\tResult: %s\n", success ? "Success" : "Failure");
		printf("\tElapsed Time: %.9lf * %d\n", (double) elapsed_time / CLOCKS_PER_SEC / repeat, repeat);
		printf("\n");
	}

	printf("Result: %s\n", total_success ? "Success" : "Failure");
}
