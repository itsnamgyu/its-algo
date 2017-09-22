#include "submit.h"
#include <time.h>
#include <stdio.h>

void submit(int (*f) (void), char *questionString) {
	clock_t start = clock();
	int success = f();
	
	printf(success ? "[Success] %s\n" :"[Failure] %s\n", questionString);
	printf("Time taken: %.2f seconds\n", (float) (clock() - start) / CLOCKS_PER_SEC);
}
