#include <stdio.h>
#include <stdlib.h>

typedef struct A{
	int age;
    char str[101];
} A;
A c[100001];
int compare(const void* a, const void* b) {
	return ((A*)a)->age>((A*)b)->age;
}

int main(int argc, const char * argv[]) {
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %s", &c[i].age, c[i].str);
	}

	qsort(c, n, sizeof(struct A), compare);

	for (int i = 0; i < n; i++) {
		printf("%d %s\n", c[i].age, c[i].str);
	}
	return 0;
}