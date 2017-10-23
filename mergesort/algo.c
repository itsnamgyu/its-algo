#include "algo.h"

int buffer[10000000];

void merge_sort(int *list, int size) {
	rec(list, 0, size - 1);
}

void rec(int *list, int low, int high) {
	if (low < high) {
		// divide and merge_sort components
		int mid = (low + high) / 2;

		rec(list, low, mid);
		rec(list, mid + 1, high);
		
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

