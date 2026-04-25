#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
	char str[2][1001] = { 0, };
	int i, j;

    int* a;
    int* b;
	
    scanf("%s", str[0]);
	scanf("%s", str[1]);
    
    int len1, len2;
    len1 = strlen(str[0]);
    len2 = strlen(str[1]);
    a = malloc(sizeof(int) * (len1 + 1));
    b = malloc(sizeof(int) * (len1 + 1));
    memset(b, 0, sizeof(int) * (len1 + 1));
    a[0] = 0;
    for (i = 1; i <= len2; i++) {
		for (j = 1; j <= len1; j++) {
			if (str[0][j-1] == str[1][i-1]) {
				a[j] = b[j-1]+1;
			}
            else {
			    if (a[j-1] > b[j])
				    a[j] = a[j-1];
                else 
                    a[j] = b[j];		    
            }
		}
        int *tmp = b;
        b = a;
        a = tmp;
	}

	printf("%d", b[len1]);
    free(a);
    free(b);
}