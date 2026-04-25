#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <climits>
using namespace std;

#define ll long long

int n, m, t;
int s, g, h;

int dijkstra(int start, int end, vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>> que;

    dist[start] = 0;
    que.push({ 0, start });

    while (!que.empty()) {
        auto top = que.top();
        que.pop();

        if (top.second == end) {
            break;
        }

        for (auto node : graph[top.second]) {
            int newDist = node.second + top.first;

            if (newDist < dist[node.first]) {
                dist[node.first] = newDist;
                que.push({ newDist, node.first });
            }
        }
    }

    return dist[end];
}

void solve() {
    vector<int> correct;
    int a, b, d;
    int x, i;
    int hg = 0;

    cin >> n >> m >> t;
    cin >> s >> g >> h;
    vector<vector<pair<int, int>>> graph(n+1);
    for (i = 0; i < m; i++) {
        cin >> a >> b >> d;
        graph[a].push_back({ b, d });
        graph[b].push_back({ a, d });
        if ((a == g && b == h) || (a == h && b == g)) {
            hg = d;
        }
    }
    for (i = 0; i < t; i++) {
        cin >> x;
        int sg = dijkstra(s, g, graph);
        int sh = dijkstra(s, h, graph);
        int gx = dijkstra(g, x, graph);
        int hx = dijkstra(h, x, graph);
        int min = dijkstra(s, x, graph);

        if (sg == INT_MAX || sh == INT_MAX || gx == INT_MAX || hx == INT_MAX || min == INT_MAX)
            continue;

        int min_small = sg + hg + hx > sh + hg + gx ?
            sh + hg + gx : sg + hg + hx;

        if (min_small <= min)
            correct.push_back(x);
    }

    sort(correct.begin(), correct.end());

    for (int i : correct) {
        cout << i << " ";
    }

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

    int t;

    cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }


	return 0;
}