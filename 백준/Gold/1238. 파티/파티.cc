#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ranges>
#include <numeric>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

//const ll MOD = 1000000007;
const ll MOD = 10007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int n, m, x;
// 0: 정방향, 1: 역방향, adj[방향][정점] = (거리, 정점)
vector<pii> adj[2][1001];
vector<int> dist[2];

void dijkstra(int d, int s) {
    // (거리, 정점)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[d][s] = 0;
    pq.push(make_pair(0, s));

    while (pq.size()) {
        pii t = pq.top(); pq.pop();

        if (dist[d][t.second] != t.first) continue;

        for (pii& next : adj[d][t.second]) {
            if (dist[d][next.second] > t.first + next.first) {
                dist[d][next.second] = t.first + next.first;
                pq.push(make_pair(t.first + next.first, next.second));
            }
        }
    }
}

void solve(int CASE = -1) {

    cin >> n >> m >> x;
    dist[0].resize(n + 1, numeric_limits<int>::max());
    dist[1].resize(n + 1, numeric_limits<int>::max());
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        adj[0][a].push_back(make_pair(t, b));
        adj[1][b].push_back(make_pair(t, a));
    }

    dijkstra(0, x);
    dijkstra(1, x);

    int max = 0;
    for (int i = 1; i <= n; i++) {
        dist[0][i] += dist[1][i];
        //cout << dist[0][i] << " " << max << "\n";
        if (max < dist[0][i]) {
            max = dist[0][i];
        }
    }

    cout << max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}