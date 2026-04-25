#include <stdio.h>

int n, m;
int result[1000];

void DFS(int depth)
{
    int i;

    if (depth == m)
    {
        for (int i = 0; i < m; i++)
            printf("%d ", result[i]);
        printf("\n");
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            result[depth] = i;
            DFS(depth + 1);
        }
    }
}

int main(void)
{
    scanf("%d %d", &n, &m);
    DFS(0);
    return 0;
}