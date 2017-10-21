#include "../submit.h"
#include "../lib.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define COUNT 12
#define BASE 4

typedef struct _List{
	int *array;
	int size;
} List;

int buffer[10000000];

void merge_sort(int *list, int low, int high);

void merge(int *list, int low, int mid, int high);

void *algo(void *data);

void load_title(int index, char title[50]);

void *load_test_case(int index);

int check(void *result, int index);

void *free_all(void *test_case, void *result);

int main(void) {
	List **test_cases;
	char test_titles[COUNT][50];
	
	submit_cases_repeatedly("Merge Sort", load_test_case, load_title, COUNT, algo, check, free_all);

	return 0;
}

void merge_sort(int *list, int low, int high) {
	if (low < high) {
		// divide and merge_sort components
		int mid = (low + high) / 2;

		merge_sort(list, low, mid);
		merge_sort(list, mid + 1, high);
		
		merge(list, low, mid, high);
	}
}

void merge(int *list, int low, int mid, int high) {
	int a = low, b = mid + 1;
	int i, j;

	for (i = 0; a <= mid || b <= high; i ++) {
		if (a == mid + 1) {
			buffer[i] = list[b ++];
		} else if (b == high + 1) {
			buffer[i] = list[a ++];
		} else if (list[a] > list[b]) {
			buffer[i] = list[b ++];
		} else {
			buffer[i] = list[a ++];
		}
	}

	i = 0; j = low;
	while (j <= high) {
		list[j] = buffer[i];
		i ++; j ++;
	}
}

void *algo(void *data) {
	List* list = data;
	merge_sort(list->array, 0, list->size - 1);
	
	return list;
}

int check(void *result, int index) {
	List *list = result;
	return is_sorted(list->array, list->size);
}

void load_title(int index, char title[50]) {
	sprintf(title, "Size = %d", (int) pow(BASE, index));
}

void *load_test_case(int index) {	
	List *test_case;
	int size = pow(BASE, index);

	test_case = (List*) malloc(sizeof(List));
	test_case->array = (int*) malloc(sizeof(int) * size);
	test_case->size = size;
	randomize_array(test_case->array, size);

	return test_case;
}

void *free_all(void *test_case, void *result) {
	List *list = test_case;

	free(list->array);
	free(list);
}
