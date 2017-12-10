int binary_search(int *list, int n, int size) {
	int low = 0;
	int high = size - 1;

	while (low < high) {
		int mid = (low + high) / 2;

		if (list[mid] < n)
			low = mid + 1;
		else 
			high = mid;
	}

	if (list[low] == n)
		return low;
	else 
		return -1;
}
