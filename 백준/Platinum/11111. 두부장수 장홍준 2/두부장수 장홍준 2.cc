#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <ranges>
#include <numeric>
#include <cstring>
#include <bit>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

constexpr ll MOD = 1000000007;
//constexpr ll MOD = 10007;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

struct Edge {
    int v, dist, cap, rev;
    Edge(int _v, int _dist, int _cap, int _rev) : v(_v), dist(_dist), cap(_cap), rev(_rev) {}
};

ll mx = 0;
const int MAX = 2500+2+1;
array<vector<Edge>, MAX> adj;

pil mcmf(int s, int e) {
    ll costs = 0, flows = 0;

    while (true) {
        array<bool, MAX> inQ{ false };
        array<int, MAX> prev, dist;
        queue<int> q;

        prev.fill(-1); dist.fill(INF<int> / 100);
        dist[s] = 0;
        inQ[s] = true;
        q.push(s);

        while (!q.empty()) {
            int f = q.front(); q.pop();
            inQ[f] = false;

            for (Edge& nxt : adj[f]) {
                if (nxt.cap > 0 && dist[nxt.v] > dist[f] + nxt.dist) {
                    dist[nxt.v] = dist[f] + nxt.dist;
                    prev[nxt.v] = nxt.rev;

                    if (!inQ[nxt.v]) {
                        q.push(nxt.v);
                        inQ[nxt.v] = true;
                    }
                }
            }
        }

        if (dist[e] == INF<int> / 100) break;

        int amount{ INF<int> };
        for (int i = e; i != s; i = adj[i][prev[i]].v) {
            Edge& e = adj[i][prev[i]];
            amount = min(amount, adj[e.v][e.rev].cap);
        }

        flows += amount;
        costs += dist[e] * amount;
        mx = max(mx, -costs);
        for (int i = e; i != s; i = adj[i][prev[i]].v) {
            Edge& e = adj[i][prev[i]];
            e.cap += amount;
            adj[e.v][e.rev].cap -= amount;
        }
        //cout << amount << " " << dist[e] << " " <<  costs << "\n";
    }
    return pil(flows, costs);
}

void insert_edge(int a, int b, int dist, int cost) {
    adj[a].emplace_back(b, dist, cost, adj[b].size());
    adj[b].emplace_back(a, -dist, 0, adj[a].size() - 1);
}

int score[6][6] = {
    {10, 8, 7, 5, 0, 1},
    {8, 6, 4, 3, 0, 1},
    {7, 4 ,3, 2, 0, 1},
    {5, 3, 2, 2, 0, 1},
    {0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0}
};

void solve(int CASE = -1) {
    int n, m;
    vector<vector<char>> arr;

    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        arr[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) % 2 == 1) {
                insert_edge(i * m + j + 1 + 2, 2, 0, 1);
                continue;
            }
            insert_edge(1, i * m + j + 1 + 2, 0, 1);
            for (int k = 0; k < 4; k++) {
                int ni = i + dy[k];
                int nj = j + dx[k];
                if (0 <= ni && ni < n && 0 <= nj && nj < m)
                    insert_edge(i * m + j + 1 + 2, ni * m + nj + 1 + 2,
                        -score[arr[i][j] - 'A'][arr[ni][nj] - 'A'], 1);
            }
        }
    }

    mcmf(1, 2);
    cout << mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    //pre();
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}