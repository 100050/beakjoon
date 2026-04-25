#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define INF (60000*10000)

int main() {
    int n, m;
    int i, j, b, c;
    int v[6000][3];
    long long e[501];
    
    c = 0;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &v[i][0], &v[i][1], &v[i][2]);
        if (v[i][0] == 1)
            c++;
    }
    for (i = 2; i <= n; i++) {
        e[i] = INF;
    }
    e[1] = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < m; j++) {
            if (e[v[j][0]] != INF)
                if (e[v[j][1]] > e[v[j][0]] + v[j][2])
                    e[v[j][1]] = e[v[j][0]] + v[j][2];
        }
    }
    b = 0;
    for (j = 0; j < m; j++) {
        if (e[v[j][1]] > e[v[j][0]] + v[j][2]) {
            b = -1;
            break;
        }
    }
    if (b == -1 && c > 0) {
        printf("-1");
    }
    else {
        for (i = 2; i <= n; i++) {
            if (e[i] != INF) {
                printf("%lld\n", e[i]);
            }
            else {
                printf("-1\n");
            }
        }
    }
}
