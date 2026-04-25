#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits> 
using namespace std;

#define ll long long

int n, e;
int arr[801][801];

int dijkstra(int start, int end) {
	priority_queue<pair<int, int>, 
		vector<pair<int, int>>, 
		greater<pair<int, int>>> pq;
	
	//int visited[801] = { 0, };
	vector<int> d( n+1, INT_MAX );
	//memset(d, INT_MAX, (n+1) * sizeof(int));
	

	pq.push({ 0, start });
	//visited[1] = 1;
	d[start] = 0;
	while (!pq.empty()) {
		auto top = pq.top();
		int dist = top.first;
		int node = top.second;
		pq.pop();


		//cout << dist << " " << node << "\n";
		if (node == end) {
			return d[end];
		}

		for (int i = 1; i <= n; i++) {
			if (arr[node][i] == 0) continue;

			int nd = dist + arr[node][i];
			if (d[i] > nd) {
				d[i] = nd;
				//visited[i] = 1;
				pq.push({ nd, i });
			}
		}
	}

	return -1;
}

void solve() {
	int a, b, c;
	int v1, v2;

	cin >> n >> e;

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		arr[a][b] = c;
		arr[b][a] = c;
	}

	cin >> v1 >> v2;

	int _v1_v2 = dijkstra(v1, v2);
	int _1_v1 = dijkstra(1, v1);
	int _1_v2 = dijkstra(1, v2);
	int _v2_n = dijkstra(v2, n);
	int _v1_n = dijkstra(v1, n);

	if (_v1_v2 == -1 || _1_v1 == -1 || _1_v2 == -1 || _v2_n == -1 || _v1_n == -1) {
		cout << -1;

		return;
	}
	int dist1 = _1_v1 + _v1_v2 + _v2_n;
	int dist2 = _1_v2 + _v1_v2 + _v1_n;


	// 경로가 없는 경우
	if (dist1 > dist2)
		cout << dist2;
	else
		cout << dist1;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	solve();


	return 0;
}