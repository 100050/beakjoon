#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int n;
int arr[20][20];
int min, idx;
int team[20];

min = 200000000;

void sol(int d, int id) {
	if (d == n / 2) { 
		int a, b;
		a = 0;
		b = 0;
		
		for (int i = 0; i < 20; i++) {
			for (int j = i+1; j < 20; j++) {
				if (team[i] == 1 && team[j] == 1) {
					a += arr[i][j];
					a += arr[j][i];
				}
				else if (team[i] == 0 && team[j] == 0) {
					b += arr[i][j];
					b += arr[j][i];
				}
			}
		}
		if (abs(b - a) < min)
			min = abs(b - a);
		idx--;
		return;
	}
	for (int i = id; i < n; i++) {
		if (team[i] == 0) {
			team[i] = 1;
			sol(d+1, i+1);
			team[i] = 0;
		}
	}
	idx--;
}

int main() {
	int i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	sol(0, 0);

	printf("%d", min);
}