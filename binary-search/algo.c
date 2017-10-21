#include "algo.h"
#include "data.h"

int binary_search(int *list, int n, int size) { 
	int low = 0;
	int high = size - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (list[mid] == n) {
			return mid;
		} else if (list[mid] < n) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	return -1;
}
