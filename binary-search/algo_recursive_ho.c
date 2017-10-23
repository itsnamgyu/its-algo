int rec(int *list, int n, int low, int high) {
	if (low > high) {
		return -1;
	}

	int mid = (low + high) / 2;
	if (n == list[mid]) {
		return mid;
	} else if (n < list[mid]) {
		return rec(list, n, low, mid - 1);
	} else {
		return rec(list, n, mid + 1, high);
	}
}

int binary_search(int *list, int n, int size) {
	return rec(list, n, 0, size - 1);
}
