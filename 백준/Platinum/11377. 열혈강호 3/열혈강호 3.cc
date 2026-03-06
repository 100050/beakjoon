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
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

constexpr ll MOD = 1000000007;
//const ll MOD = 10007;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

int n;
array<vector<int>, 2005> adj;
array<array<int, 2005>, 2005> flow, cap;

int maxFlow(int start, int end) {
    int total{ 0 };

    while (true) {
        queue<int> q;
        array<int, 2005> par{ 0, };
        // v + e
        q.push(start);
        while (!q.empty()) {
            int f{ q.front() }; q.pop();

            for (const int nxt : adj[f]) {
                if (par[nxt] == 0 && cap[f][nxt] - flow[f][nxt] > 0) {
                    par[nxt] = f;
                    q.push(nxt);
                }
            }
        }

        if (par[end] == 0) break;

        int amount{ INF<int> };
        for (int v{ end }; v != start; v = par[v])
            amount = min(amount, cap[par[v]][v] - flow[par[v]][v]);

        for (int v{ end }; v != start; v = par[v]) {
            flow[par[v]][v] += amount;
            flow[v][par[v]] -= amount;
        }

        total += amount;
    }

    return total;
}

void insert_edge(int a, int b, int cost) {
    adj[a].push_back(b);
    adj[b].push_back(a);
    cap[a][b] = cost;
}

void solve(int CASE = -1) {
    int m, k;

    cin >> n >> m >> k;
    insert_edge(1, 2, n);
    insert_edge(1, 3, k);
    for (int i = 1; i <= n; i++) {
        int nn;
        cin >> nn;
        insert_edge(2, 4 + i, 1);
        insert_edge(3, 4 + i, 1);
        for (int j = 0; j < nn; j++) {
            int a;
            cin >> a;
            insert_edge(4 + i, 4 + a + n, 1);
        }
    }
    for (int i = 1; i <= m; i++) {
        insert_edge(4 + n + i, 4, 1);
    }

    cout << maxFlow(1, 4);
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