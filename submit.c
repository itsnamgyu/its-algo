#include "submit.h"
#include <time.h>
#include <stdio.h>
	
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
