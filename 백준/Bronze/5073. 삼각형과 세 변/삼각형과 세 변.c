#include <stdio.h>

int main() {
    int a, b, c;
    int max, min, mid;
    
    scanf("%d %d %d", &a, &b, &c);
    while (a != 0) {
        min = (a <= b && a <= c) ? a :        // if      (a < b && a < c) return a;
            (b <= a && b <= c) ? b : c;   // else if (b < a && b < c) return b; else return c;
 
        max = (a >= b && a >= c) ? a :        // if      (a > b && a > c) return a;
            (b >= a && b >= c) ? b : c;   // else if (b > a && b > c) return b; else return c;
 
        mid = (a >= b && a <= c) ? a : 
            (b >= a && b <= c) ? b :
            (c >= a && c <= b) ? c : 
            (a >= c && a <= b) ? a :
            (b >= c && a >= b) ? b : c;
        
        if (min + mid <= max) {
            printf("Invalid\n");
        }
        else if (a == b && b == c) {
            printf("Equilateral\n");
        }
        else if (a != b && b != c && a != c) {
            printf("Scalene\n");   
        }
        else {
            printf("Isosceles\n");
        }
        
        scanf("%d %d %d", &a, &b, &c);
    }
}