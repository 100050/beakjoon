#include <stdio.h>

int t1,t2;
t1 = 0;
t2 = 0;
int fib(int n) {
    if (n == 1 || n == 2) {
        t1++;
        return 1;  
    }
    else 
        return (fib(n - 1) + fib(n - 2));
}
int fibonacci(int n) {
    int f[41] = {0, };
    int i;
    f[1] = 1;
    f[2] = 1;
    for (i = 3; i<=n;i++) {
        t2++;
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main() {
    int n,f1,f2;
    scanf("%d", &n);
    f1 =fib(n);
    f2 =fibonacci(n);
    printf("%d %d", t1,t2);
    
}