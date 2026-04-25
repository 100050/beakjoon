#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int graph[101][101];

int main() {
    int i, j, k;
    int n, m;
    int a, b, c;

    scanf("%d\n%d", &n, &m);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i != j)
                graph[i][j] = 10000001;
        }
    }
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (graph[a][b] > c)
            graph[a][b] = c;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            for (k = 1; k <= n; k++) {
                if (graph[j][k] > graph[j][i] + graph[i][k])
                    graph[j][k] = graph[j][i] + graph[i][k];
            }
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (graph[i][j] == 10000001) {
                printf("0 ");
                continue;
            }
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
