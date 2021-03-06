#include "sort-util.h"
#include <stdlib.h>
#include <limits.h>

void randomize_array(int *array, int size) {
	for (int i = 0; i < size; i ++) {
		array[i] = rand();
	}
}

// from 0 to 99999
void fill_array_sorted(int *array, int size) {
	long count[100000] = { 0 };

	for (int i = 0; i < size; i ++) {
		count[rand() % 100000] ++;
	}

	int index = 0;
	for (int i = 0; i < 100000; i ++) {
		while (count[i] --) {
			array[index ++] = i;
		}
	}
}

int is_sorted(int const * array, int size) {
	if (size < 2) {
		return 1;
	}

	for (int i = 1; i < size; ++ i) {
		if (array[i - 1] > array[i]) {
			return 0;
		}
	}

	return 1;
}
