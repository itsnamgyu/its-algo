#include <stdio.h>
#include "../submit.h"

int list[100000]; 

void mergesort(int low, int high);

void merge(int lowA, int highA, int lowB, int highB);

int solver();

int main(void) {
	submit(solver, "mergesort");

	return 0;
}

void mergesort(int low, int high) {

}

void merge(int lowA, int highA, int lowB, int highB) {

}

int solver() {
	return 1;
}
