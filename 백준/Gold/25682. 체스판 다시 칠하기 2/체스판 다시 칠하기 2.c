#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int arr[2000][2000][2];

int main() {
	int min, temp;
	int i, j, g, x;
	int n, m, k;
	// w 1 b 0
	// arr[i][j][0] 0,0 black
	scanf("%d %d %d", &n, &m, &k);
	getchar();
	min = 2000 * 2000;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%c", &arr[i][j][1]);
			if (arr[i][j][1] == 'B')
				arr[i][j][1] = 0;
			else
				arr[i][j][1] = 1;
			// i+1와 j+1가 모두 짝수거나 홀수일 때 거짓
			// g == 0, k == 1 1
			// g == 0, k == 0 0
			// g == 1, k == 0 1
			// g == 1, k == 1 0
 
			x = ((i + 1) ^ (j + 1)) & 1;
			for (g = 0; g < 2; g++) {
				if (i == 0 & j == 0) {	
					if (arr[i][j][1] == g ^ x)
						arr[i][j][g] = 0;
					else
						arr[i][j][g] = 1;
				}
				else if (i == 0) {
					if (arr[i][j][1] == g ^ x)
						arr[i][j][g] = arr[i][j - 1][g];
					else
						arr[i][j][g] = arr[i][j - 1][g] + 1;
				}
				else if (j == 0) {
					if (arr[i][j][1] == g ^ x)
						arr[i][j][g] = arr[i-1][j][g];
					else
						arr[i][j][g] = arr[i-1][j][g] + 1;
				}
				else {
					if (arr[i][j][1] == g ^ x)
						arr[i][j][g] = arr[i][j - 1][g] + arr[i-1][j][g] - arr[i-1][j - 1][g];
					else
						arr[i][j][g] = arr[i][j - 1][g] + arr[i - 1][j][g] - arr[i - 1][j - 1][g] + 1;

				}

				if (i == k - 1 && j == k - 1) {
					temp = arr[i][j][g];
					if (temp < min)
						min = temp;
				}
				else if (i == k - 1 && j > k - 1) {
					temp = arr[i][j][g] - arr[i][j - k][g];
					if (temp < min)
						min = temp;
				}
				else if (j == k - 1 && i > k - 1) {
					temp = arr[i][j][g] - arr[i-k][j][g];
					if (temp < min)
						min = temp;
				}
				else if (i > k - 1 && j > k - 1) {
					temp = arr[i][j][g] - arr[i - k][j][g] - arr[i][j - k][g] + arr[i-k][j-k][g];
					if (temp < min)
						min = temp;
				}
				
			}
		}
		getchar();
	}

	printf("%d", min);

	return 0;
}