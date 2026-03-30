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

const int MAX = 10001;
array<vector<Edge>, MAX> adj;

pil mcmf(int s, int e) {
    ll costs = 0, flows = 0;

    while (true) {
        array<bool, MAX> inQ;
        array<int, MAX> prev, dist;
        queue<int> q;

        prev.fill(-1); dist.fill(INF<int>);
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

        if (prev[e] == -1) break;

        int amount{ INF<int> };
        for (int i = e; i != s; i = adj[i][prev[i]].v) {
            Edge& e = adj[i][prev[i]];
            amount = min(amount, adj[e.v][e.rev].cap);
        }

        flows += amount;
        costs += dist[e] * amount;
        
        for (int i = e; i != s; i = adj[i][prev[i]].v) {
            Edge& e = adj[i][prev[i]];
            e.cap += amount;
            adj[e.v][e.rev].cap -= amount;
        }
        //cout << amount << " " << dist[e] << " " <<  costs << "\n";
    }
    return pii(flows, costs);
}

void insert_edge(int a, int b, int dist, int cost) {
    adj[a].emplace_back(b, dist, cost, adj[b].size());
    adj[b].emplace_back(a, -dist, 0, adj[a].size()-1);
}

void solve(int CASE = -1) {
    int n, m;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        insert_edge(m + i + 1 + 2, 2, 0, c);
    }
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        insert_edge(1, i + 1 + 2, 0, c);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int c;
            cin >> c;
            insert_edge(i + 1 + 2, m + j + 1 + 2, c, INF<int>);
        }
    }

    cout << mcmf(1, 2).second;
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