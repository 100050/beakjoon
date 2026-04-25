#include <stdio.h>
#include <math.h>

void hanoi(int n, int start, int middle, int end) 
{
    if (n == 1)
    {
        printf("%d %d\n", start, end);
        return;
    }
    hanoi(n - 1, start, end, middle);
    hanoi(1, start, middle, end);
    hanoi(n - 1, middle, start, end);
}

int main()
{
    int N;
    scanf("%d", &N);

    int cnt = pow(2, N) - 1;
    printf("%d\n", cnt);
    hanoi(N, 1, 2, 3);

    return 0;
 }