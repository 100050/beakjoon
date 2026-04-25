#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m, b, i, j, k;
	int arr[500][500];
	int num[257];
	int gap[2] = { 0 };
	int min = 192000000, min_num = 0, max = 0, b_temp, flag = 0;

	scanf("%d %d %d", &n, &m, &b);
    b_temp = b;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (max < arr[i][j]) max = arr[i][j];
		}
	}

	for (i = 0; i <= 256; i++) {
		for (j = 0; j < n; j++) {
			for (k = 0; k < m; k++) {
				if (arr[j][k] > i) {
					gap[0] += arr[j][k] - i;
					b += arr[j][k] - i;
				}
			}
		}
		for (j = 0; j < n; j++) {
			for (k = 0; k < m; k++) {
				if (arr[j][k] <= i) {
					gap[1] += i - arr[j][k];
					b -= i - arr[j][k];
				}
				if (b < 0) { 
					gap[1] = 64000000; 
					gap[0] = 64000000; 
					flag = 1; 
					break; 
				}

			}
			if (flag == 1) { 
				flag = 0; 
				break; 
			}
		}
		num[i] = (gap[0] * 2) + (gap[1]);
		if (num[i] <= min) { 
			min = num[i]; 
			min_num = i; 
		}
		gap[0] = 0; gap[1] = 0; b = b_temp;
	}
    
	printf("%d %d", min, min_num);

	return 0;
}