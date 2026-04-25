#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int mxV = 20001;
const int mxE = 200001;

bool bfs(int start, vector<int> arr[], int visited[]) {
	queue<int> que;
	
	que.push(start);
	visited[start] = 1;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int vertex : arr[cur]) {
			if (visited[cur] == visited[vertex])
				return false;
			if (visited[vertex] == 0) {
				if (visited[cur] == 2)
					visited[vertex] = 1;
				else
					visited[vertex] = 2;
				que.push(vertex);
			}
		}
	}

	return true;
}

void solve() {
	int first, second;
	int v, e;

	vector<int> arr[mxV];
	int visited[mxV] = { 0, };

	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		cin >> first >> second;
		arr[first].push_back(second);
		arr[second].push_back(first);
	}

	bool isBG = true; // = bfs(1);
	for (int i = 1; i <= v; i++) {
		if (visited[i] == 0) {
			isBG = bfs(i, arr, visited);
		}
		if (!isBG) break;
	}
	if (isBG) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while (n--) {
		solve();
	}

	return 0;
}