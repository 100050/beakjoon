#include <stdio.h>

int main() {
    int i, n, s, j, k;
    char arr[80];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", arr);
        s = 0;
        j = 0;
        k = 1;
        while (arr[j]) {
            if (arr[j] == 'O') {
                s += k++;
            }
            else {
                k = 1;
            }
            j++;
        }
        
        printf("%d\n", s);
    }
    
   
}