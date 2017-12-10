int rec(int *list, int n, int low, int high) {
	int mid = (low + high) / 2;

	if (low > high)
		return -1;

	if (low == high)
		if (list[low] == n) 
			return low;
		else 
			return -1;
		
	if (list[mid] < n)
		return rec(list, n, mid + 1, high);
	else
		return rec(list, n, low, mid);
}

int binary_search(int *list, int n, int size) {
	return rec(list, n, 0, size - 1);
}
