#include "../submit.h"
#include "../lib.h"
#include "algo.h"
#include "data.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define COUNT 25
#define BASE 2

void *solve(void *test_case);

void load_title(int index, char title[50]);

int compare_int(const void *a, const void *b);

void *load_test_case(int index);

int check(void *result, int index);

void *free_all(void *test_case, void *result);

int main(void) {
	Data **test_cases;
	char test_titles[COUNT][50];
	
	srand(time(NULL));
	submit_cases_repeatedly("Binary Search", load_test_case, load_title, COUNT, solve, check, free_all);

	return 0;
}

void *solve(void *test_case) {
	Data *data = test_case;

	int *array = data->array;
	int n = data->n;

	data->position = binary_search(data->array, data->n, data->size);

	return data;
}

int check(void *result, int index) {
	Data *data = result;
	
	if (data->position == -1) {
		void *result = bsearch(&data->n, data->array, data->size, sizeof(int), compare_int);
		if (result) {
			printf("%d = data->array[%d]\n", data->n, (int*)result - (int*)data->array);
			printf("False -1\n");
		}
		return !result;
	}
	return data->array[data->position] == data->n;
}

void load_title(int index, char title[50]) {
	sprintf(title, "Size = %d", (int) pow(BASE, index));
}

int compare_int(const void *a, const void *b) {
	int n = *((int*)a);
	int m = *((int*)b);

	if (n < m) {
		return -1;
	} else if (n == m) {
		return 0;
	} else {
		return 1;
	}
}

void *load_test_case(int index) {	
	Data *data;
	int size = pow(BASE, index);

	data = (Data*) malloc(sizeof(Data));
	data->array = (int*) malloc(sizeof(int) * size);
	data->size = size;
	data->n = data->array[rand() % size];

	fill_array_sorted(data->array, size);

	return data;
}

void *free_all(void *test_case, void *result) {
	Data *data = test_case;

	free(data->array);
	free(data);
}
