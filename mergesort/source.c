#include "../submit.h"
#include "../lib.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define COUNT 12

typedef struct _List{
	int *array;
	int size;
} List;


int buffer[10000000];


void my_mergesort(int *list, int low, int high);

void merge(int *list, int low, int mid, int high);

void *algo(void *data);

int check(void *result);

int main(void) {
	List **test_cases;
	char test_titles[COUNT][50];

	test_cases = (List**) malloc(sizeof(List*) * COUNT);
	int size = 1;
	for (int i = 0; i < COUNT; i ++) {
		sprintf(test_titles[i], "Size = %d", size);
		test_cases[i] = (List*) malloc(sizeof(List));
		test_cases[i]->array = (int*) malloc(sizeof(int) * size);
		test_cases[i]->size = size;
		randomize_array(test_cases[i]->array, size);
		
		size *= 4;
	}
	
	submit_cases("Merge Sort", test_cases, test_titles, COUNT, algo, check);

	for (int i = 0; i < COUNT; ++ i) {
		free(test_cases[i]);
	}
	free(test_cases);

	return 0;
}

void my_mergesort(int *list, int low, int high) {
	if (low < high) {
		// divide and my_mergesort components
		int mid = (low + high) / 2;

		my_mergesort(list, low, mid);
		my_mergesort(list, mid + 1, high);
		
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
	my_mergesort(list->array, 0, list->size - 1);
	
	return list;
}

int check(void *result) {
	List *list = result;
	return is_sorted(list->array, list->size);
}
