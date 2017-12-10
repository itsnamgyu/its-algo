#include "../submit.h"
#include "../lib.h"

#include "data.h"
#include "algo.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define COUNT 12
#define BASE 4

void *algo(void *data);

void load_title(int index, char title[50]);

void *load_test_case(int index);

int check(void *result, int index);

void *free_all(void *test_case, void *result);

int main(void) {
	submit_cases_repeatedly("Quick Sort", load_test_case, load_title, COUNT, algo, check, free_all);

	return 0;
}

void *algo(void *data) {
	Data* list = data;
	quick_sort(list->array, 0, list->size - 1);
	
	return list;
}

int check(void *result, int index) {
	Data *list = result;
	return is_sorted(list->array, list->size);
}

void load_title(int index, char title[50]) {
	sprintf(title, "Size = %d", (int) pow(BASE, index));
}

void *load_test_case(int index) {	
	Data *test_case;
	int size = pow(BASE, index);

	test_case = (Data*) malloc(sizeof(Data));
	test_case->array = (int*) malloc(sizeof(int) * size);
	test_case->size = size;
	randomize_array(test_case->array, size);

	return test_case;
}

void *free_all(void *test_case, void *result) {
	Data *list = test_case;

	free(list->array);
	free(list);
}
