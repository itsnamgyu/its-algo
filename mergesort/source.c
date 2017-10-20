#include <stdio.h>
#include "../submit.h"
#include <math.h>

#define SIZE 30

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
	if (low < high) {
		// divide and mergesort components
		int mid = (low + high) / 2;

		mergesort(low, mid);
		mergesort(mid + 1, high);
		
		//////
		printf("L1: ");
		for (int i = low; i <= mid; i ++) {
			printf("%d:%d ", i, list[i]);
		}
		printf("\n");

		printf("L2: ");
		for (int i = mid + 1; i <= high; i ++) {
			printf("%d:%d ", i, list[i]);
		}
		printf("\n");
		//////
	
		// merge sorted components
		merge(low, mid, high);

		//////
		printf("L3: ");
		for (int i = low; i <= high; i ++) {
			printf("%d ", list[i]);
		}
		printf("\n");
		//////
	}
}

void merge(int low, int mid, int high) {
	int a = low, b = mid + 1;
	int i, j;

	printf("L0: ");
	for (i = 0; a <= mid || b <= high; i ++) {
		printf("a: %d, mid: %d, b: %d, high %d\n", a, mid, b, high);
		printf("Comparing %d and %d\n", list[a], list[b]);

		if (a == mid + 1) {
			buffer[i] = list[b ++];
		} else if (b == high + 1) {
			buffer[i] = list[a ++];
		} else if (list[a] > list[b]) {
			buffer[i] = list[b ++];
		} else {
			buffer[i] = list[a ++];
		}

		printf("%d  ", buffer[i]);
	}
	printf("\n");

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

	mergesort(0, SIZE - 1);

	for (int i = 0; i < SIZE - 1; i ++) {
		if (list[i] > list[i + 1]) {
			return 0;
		}
	}
	
	return 1;
}
