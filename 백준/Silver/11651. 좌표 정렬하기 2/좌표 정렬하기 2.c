#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
} Arr;

int compare(const void* a, const void* b) {
	Arr A = *(Arr*)a;  
	Arr B = *(Arr*)b;
	if (A.y > B.y) {
		return 1;
	}
	else if (A.y == B.y) {
		if (A.x > B.x) {
			return 1;
		}
		else {
			return -1;
		}
	}
	return -1;
}

int main() {
	int n, i, b, c;
	Arr* a;
	scanf("%d", &n);
	a = (Arr*)malloc(sizeof(Arr) * n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &a[i].x, &a[i].y);
	}

	qsort(a, n, sizeof(Arr), compare);
	for (i = 0; i < n; i++) {
		printf("%d %d\n", a[i].x, a[i].y);
	}

	free(a);
	return 0;
}