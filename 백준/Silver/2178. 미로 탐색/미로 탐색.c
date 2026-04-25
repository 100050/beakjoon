#include <stdio.h>
#include <stdlib.h>

int graph[101][101] = { 0, };
int cnt = 0;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, m;
int q[10001][2] = { 0, };

int bfs() {
    // 큐 front, rear
    int front = 0, rear = 0;
    // 큐에 처음 (1, 1) 좌표 삽입
    q[front][0] = 1;
    q[front][1] = 1;
    rear++;

    // 큐가 빌 때 까지
    while (front < rear) {
        int x = q[front][0]; // x 좌표
        int y = q[front][1]; // y 좌표 
        front++; // front 이동

        // 인접 칸(상하좌우) 이동
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위를 벗어나는 경우
            if (nx < 1 || ny < 1 || nx > n || ny > m)
                continue;

            // 길이 아닌 경우
            if (graph[nx][ny] != 1)
                continue;

            // 이전 칸에서 이동한 칸 수 + 1
            graph[nx][ny] = graph[x][y] + 1;

            // 큐에 (nx, ny) 삽입
            q[rear][0] = nx;
            q[rear][1] = ny;
            rear++;
        }
    }
    return graph[n][m];
}

int main() {
	int i, j;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
    int ans = bfs();
	printf("%d\n", ans);
}
