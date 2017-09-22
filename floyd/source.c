#include <stdio.h>
#include "../submit.h"

#define N 5

int graph[N][N] = {
	{0, 1, 0, 1, 5}, 
	{9, 0, 3, 2, 0}, 
	{0, 0, 0, 4, 0},
	{0, 0, 2, 0, 3},
	{3, 0, 0, 0, 0}
};
int answer[N][N] = {
	{0, 1, 3, 1, 4}, 
	{8, 0, 3, 2, 5}, 
	{10, 11, 0, 4, 7},
	{6, 7, 2, 0, 3},
	{3, 4, 6, 4, 0}
};

int solve();

void floyd();

int main(void) {
	submit(solve, "Floyd Algorithm [N = 5]");

	return 0;
}

int solve() {
	floyd();

	for (int i = 0; i < N; ++ i) {
		for (int j = 0; j < N; ++ j) {
			if (graph[i][j] != answer[i][j]) {
				return 0;
			}
		}
	}
	
	return 1;
}

void floyd() {
	for (int k = 0; k < N; ++ k) {
		for (int i = 0; i < N; ++ i) {
			for (int j = 0; j < N; ++ j) {
				if (k == j || i == j) {
					continue;
				}

				int straight = graph[i][j];
				int around = (graph[i][k] + graph[k][j]);
				int can_go_around = graph[i][k] && graph[k][j];
				
				if (can_go_around) {
					if (straight) { // can_go_straight
						graph[i][j] = straight < around ? straight : around;
					} else {
						graph[i][j] = around;
					}
				}
			}
		}
	}
}
