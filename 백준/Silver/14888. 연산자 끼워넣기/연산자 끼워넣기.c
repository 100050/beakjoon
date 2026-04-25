#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min, max, n, gi;
min = 1000000000;
max = -1000000000;
int oper[4];
int arr[100];

void sol(int d, int result) {
	if (d == n-1) {
		if (result > max) {
			max = result;
		}
		if (result < min) {
			min = result;
		}
		gi--;
		return;
	}
	int idx = 0;
    while (idx < 4) {
		if (oper[idx] > 0) {
			oper[idx]--;
			switch (idx) {
			case 0:
				sol(d + 1, result + arr[gi++]);
				break;
			case 1:
				sol(d + 1, result - arr[gi++]);
				break;
			case 2:
				sol(d + 1, result * arr[gi++]);
				break;
			case 3:
				sol(d + 1, result / arr[gi++]);
				break;
			}
			oper[idx]++;
            
        }
        idx++;
	}
	gi--;
}

int main() {
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < 4; i++) {
		scanf("%d", &oper[i]);
	}

	gi = 0;
	sol(0, arr[gi++]);

	printf("%d\n%d", max, min);
}