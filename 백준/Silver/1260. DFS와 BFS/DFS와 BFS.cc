#include<iostream>
#include<algorithm>
#include <queue>

using namespace std;

vector<int> graph[100001];
int visited[100001] = { 0, };
int visited2[100001] = { 0, };
int result[100001];
int result2[100001];
int cnt = 0;

bool compare(int a, int b) {
    return a < b;
}

void dfs(int r) {
	if (visited[r] == 1) { // 방문 한 곳이면 return
		return;
	}

	visited[r] = 1; // 방문하지 않았다면 방문했다고 표시
	printf("%d ", r);

	for (int i = 0; i < graph[r].size(); i++) {
		dfs(graph[r][i]); 
	}
}
void bfs(int start) {
    queue<int> q;
    q.push(start); // 첫 노드를 queue에 삽입
    visited2[start] = true; // 첫 노드를 방문 처리
	cnt++;
	printf("%d ", start);
    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        // 큐에서 하나의 원소를 뽑아 출력
        int x = q.front();
        q.pop();
        // 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if (!visited2[y]) {
				cnt++;
				printf("%d ", y);
                q.push(y);
                visited2[y] = true;
            }
        }
    }
}

int main() {
	int n, m, r, i;
	scanf("%d %d %d", &n, &m, &r);
	for (i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b); // (1,4) (1,2) (2,3) (2,4) (3,4)
		graph[b].push_back(a); // (4,1) (2,1) (3,2) (4,2) (4,3)	
	}
	for (i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end(), compare);
	}
	dfs(r);
	cout << '\n';
	cnt = 0;
	bfs(r);
}