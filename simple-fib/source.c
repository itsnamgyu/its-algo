#include <stdio.h>
#include "../submit.h"
#include <assert.h>

#define N 20
#define ANSWER 10946

#define uint unsigned int

uint fib[N]; // 1, 1, 2, 3, 5...

int getFib(int n);

int solver();

int main(void) {
	submit(solver, "Simple Fibonnaci Calculate [N = 20]");

	return 0;
}

int getFib(int n) {
	if (fib[n] != 0) {
		return fib[n];
	}

	assert(n > 1);

	return fib[n] = getFib(n - 1) + getFib(n - 2);
}

int solver() {
	for (int i = 0; i < N; ++ i)
		fib[i] = 0;

	fib[0] = 1;
	fib[1] = 1;

	return getFib(N) == ANSWER;
}
