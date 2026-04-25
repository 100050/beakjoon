#include <stdio.h> 
#include <string.h>
//1000000000
int main() {
	char arr[1000000];
	short arr2[10] = {0};
	int i, n, j, x;
	scanf("%s", arr);
	for (i = 0; i < strlen(arr); i++) {
		arr2[arr[i] - '0']++;
	}
	for (i = 9; i > -1; i--) {
		for (j = 0; j < arr2[i]; j++) {
			printf("%d", i);
		}
	}
}
