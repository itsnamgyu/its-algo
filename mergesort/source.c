#include <stdio.h>
#include "../submit.h"
#include <math.h>

#define SIZE 10000000

int list[SIZE]; 
int buffer[SIZE];

void mergesort(int low, int high);

void merge(int low, int mid, int high);

int solver();

int main(void) {
	submit(solver, "mergesort [N = 10^7]");

	return 0;
}

void mergesort(int low, int high) {
	// base case?
	if (low == high) {
		return;
	}

	// divide and mergesort components
	int mid = (low + high) / 2;

	mergesort(low, mid);
	mergesort(mid + 1, high);

	// merge sorted components
	merge(low, mid, high);
}

void merge(int low, int mid, int high) {
	int a = low, b = mid + 1;
	int i, j;
	
	for (i = 0; a <= mid && b <= high; i ++) {
		if (a == mid + 1 || list[a] > list[b]) {
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

int solver() {
	srand(time(NULL));

	for (int i = 0; i < SIZE; i ++) {
		list[i] = rand();
	}

	mergesort(0, SIZE);

	for (int i = 0; i < SIZE - 1; i ++) {
		if (list[i] > list[i + 1]) {
			return 0;
		}
	}
	
	return 1;
}
