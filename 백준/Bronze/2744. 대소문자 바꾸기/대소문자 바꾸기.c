#include <stdio.h>

int main() {
	int l, i;
	char str[100];
	scanf("%s", str);
	i = 0;
	while (str[i]) {
		if (str[i] - 'a' >= 0) {
			str[i] = str[i] - 'a' + 'A';
		}
		else {
			str[i] = str[i] - 'A' + 'a';
		}
		i++;
	}
	printf("%s", str);
}