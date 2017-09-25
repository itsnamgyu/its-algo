#include <stdio.h>
#include "../submit.h"
#include <math.h>
#include <limits.h>

#define V 6
#define E 10

typedef struct Edge {
	int source;
	int dest;
	int distance;
} Edge;

Edge edges[E] = {
	{ 0, 1, 1 }, { 0, 2, -2 }, { 0, 3, 3 },
	{ 1, 2, 4 }, { 1, 4, 3 }, { 4, 5, 10 },
	{ 2, 5, 2 }, { 3, 2, 4 }, { 3, 5, 5 },
	{ 2, 4, -6 }
};

int correct_distances[V] = {
	0, 1, -2, 3, -8, 0
};


int distances[V];

void bellman(void);

// return min(a, b + c) considering overflow
int min_sum(int a, int b, int c);

int solve();

int main(void) {
	submit(solve, "Bellman-Ford [V=6, E=10]");

	return 0;
}

void bellman(void) {
	distances[0] = 0;

	for (int v = 1; v < V; ++ v)
		distances[v] = INT_MAX;

	for (int v = 0; v < V - 1; ++ v) {
		for (int e = 0; e < E; ++ e) {
			int v1 = edges[e].source;
			int v2 = edges[e].dest;
			int d = edges[e].distance;

			distances[v2] = min_sum(distances[v2], distances[v1], d);
		}
	}
}

int min_sum(int a, int b, int c) {
	if (b == INT_MAX || c == INT_MAX)
		return a;

	if (a == INT_MAX) // && b + c is valid
		return b + c;

	return a < b + c ? a : b + c;
}

int solve() {
	bellman();

	for (int v = 0; v < V; ++ v) {
		if (correct_distances[v] != distances[v])
			return 0;
	}
	
	return 1;

}
