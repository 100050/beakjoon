#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char str[1000001] = "";
char queue[1000001] = "";
char target[37] = "";

int cmp(char target[], char str[], int idx, int t_len) {
	for (int i = 0; i < t_len; i++) {
		if (target[i] != str[i + idx - t_len])
			return 0;
	}
	return 1;
}

int main() {
	int i, idx;
	int len, t_len;

	scanf("%s", str);
	scanf("%s", target);

	len = strlen(str);
	t_len = strlen(target);
	idx = 0;
	for (i = 0; i < len; i++) {
		queue[idx++] = str[i];
		
		if (i < t_len - 1)
			continue;

		if (target[t_len - 1] == queue[idx - 1]) {
			if (cmp(target, queue, idx, t_len)) {
				// TRUE
				idx -= t_len;
			}
		}
	}
	if (idx != 0) {
		for (i = 0; i < idx; i++)
			printf("%c", queue[i]);
	}
	else {
		printf("FRULA");
	}
 }
