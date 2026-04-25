#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int str[50];
	int* arr;
} Arr;

int compare(const void* a, const void* b) {
	Arr A = *(Arr*)a;
	Arr B = *(Arr*)b;
	if (A.arr > B.arr) 
		return 1;   
	else if (A.arr == B.arr)
	{
		if (strcmp(A.str, B.str) > 0)
			return 1;
		else
			return -1;
	}
	return -1;
}

int main() {
	int n, i, j, b;
	scanf("%d", &n);
	Arr a[20002];
	for (i = 0; i < n; i++) {
		scanf("%s", &a[i].str);
		a[i].arr = strlen(a[i].str);
	}

	qsort(a, n, sizeof(Arr), compare);

	for (i = 0; i < n; i++) {
		b = 0;
		if(strcmp(a[i].str, a[i+1].str) != 0)
		    printf("%s\n", a[i].str);
	}
    
	return 0;
}