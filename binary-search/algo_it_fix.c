/*
 * Fix based on this Quora question
 * https://www.quora.com/What-are-common-mistakes-for-implementing-binary-search
 */

int binary_search(int *list, int n, int size) {
	int low = 0;
	int high = size - 1;

	/*
	 * # Specification
	 * Find any i such that [i] == n if one exists
	 * Else, return NOT_FOUND
	 *
	 * ## Better Spec
	 * Note that this is not a common specification of bsearcch
	 * Instead, the following spec is more versitile and equally easy to implement
	 * >> Find the smallest i s.t. [i] <= n
	 * Check bsearch_esmaller
	 *
	 * # Invariant
	 * [low] <= n <= [high]
	 *
	 * # Input Condition
	 * Since [low] <= n <= [high] for all possible n ( lists,
	 * all n ( list will be found. Else, NOT_FOUND will be returned
	 * 
	 * # Terminating condition
	 * low == high
	 *
	 * # Loop Considerations
	 * Set low or high to mid = low+high / 2
	 * (obv. s.t. invariant is satisfied)
	 * With only the above condition, low & high may not converge
	 * I.e. when low = high + 1, we may loop up in low = mid (=low)
	 * 
	 * We need to solve this edge case.
	 * Here are the possible situations and our desired results
	 *   L < n < H / L < n = H / L = n < H / L = n = H
	 *   L=H       / L<-H      / L->H      / L=H
	 * Thus, we can solve this edge case with
	 *   if L == H+1
	 *     if n == H, then L=H
	 *     else, H=L
	 *
	 * # Return Value
	 * if [low] == n: return low=high
	 * else:          NOT_FOUND
	 */
	while (low < high) {
		int mid = (low + high) / 2;

		if (low == mid) {
			
		}
		if (list[mid] <= n) 
			low = mid;
		else 
			high = mid;
	}

	if (list[low] == n)
		return low;
	else 
		return -1;
}
