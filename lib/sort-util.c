#include "sort-util.h"
#include <stdlib.h>

void fill_array_random(int *array, int size) {
	for (int i = 0; i < size; i ++) {
		array[i] = rand();
	}
}

int is_sorted(int * const array, int size) {
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
