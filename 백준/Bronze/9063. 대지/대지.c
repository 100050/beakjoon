#include <stdio.h>

int main() {
    int n, i;
    int x, y;
    int min[2] = {10000, 10000};
    int max[2] = {-10000, -10000};
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        
        if (x < min[0]) min[0] = x;
        if (x > max[0]) max[0] = x;
        if (y < min[1]) min[1] = y;
        if (y > max[1]) max[1] = y;
    }
    
    printf("%d", (max[0] - min[0]) * (max[1] - min[1]));
    
    return 0;
}