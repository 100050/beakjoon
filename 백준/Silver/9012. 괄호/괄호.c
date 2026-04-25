#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int t, r, i;
	char str[50];
	scanf("%d", &t);
	while (t--) {
		r = 0;
		scanf("%s", str);
		for (i = 0; i < strlen(str); i++) {
			if (str[i] == '(')
				r++;
			else if (str[i] == ')')
				r--;
			if (r < 0)
				break;
		}
		if (r == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}