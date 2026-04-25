#include <stdio.h>
#include <stdlib.h>

int graph[100001] = { 0, };
int q[100001] = { 0, };
int dx[3] = { -1, 1, 0 };
int cnt = 0;
int n, k;

void bfs() {
    // 큐 front, rear
    int front = 0, rear = 0;
    // 큐에 처음 (1, 1) 좌표 삽입
    q[front] = n;
    rear++;

    // 큐가 빌 때 까지
    while (front < rear) {
        int x = q[front]; // x 좌표
        front++; // front 이동
        dx[2] = x;
        int b = 0;
        for (int i = 0; i < 3; i++) {
            int nx;

            nx = x + dx[i];

            // 범위를 벗어나는 경우
            if (nx < 0 || nx > 100000)
                continue;

            // 이전 칸에서 이동한 칸 수 + 1
            if (graph[nx] != 0) {
                continue;
            }

            graph[nx] = graph[x] + 1;
            if (nx == k) {
                cnt = graph[nx];
                b = 1;
                break;
            }
            // 큐에 (nx, ny) 삽입
            q[rear] = nx;
            rear++;
        }
        if (b == 1) {
            break;
        }
    }
}

int main() {

    scanf("%d %d", &n, &k);
    if (n != k) {
        bfs();
    }

    printf("%d\n", cnt);
}

