#include <stdio.h>
#include <string.h>

int main() {
	int i, n;
	char str[11][1001];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", str[i]);
		printf("%c", str[i][0]);
		printf("%c\n", str[i][strlen(str[i]) - 1]);
	}
}