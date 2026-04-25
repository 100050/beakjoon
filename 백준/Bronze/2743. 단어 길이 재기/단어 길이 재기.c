#include <stdio.h>

int main() {
	int l, i;
	char str[100];
	scanf("%s", str);
	l = 0;
	i = 0;
	while (str[i]) l++, i++;
	printf("%d", l);
}