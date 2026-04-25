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
array<vector<int>, 401> adj;
array<array<int, 401>, 401> flow, cap;

int maxFlow(int start, int end) {
    int total{ 0 };

    while (true) {
        queue<int> q;
        array<int, 401> par{ 0, };
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

void solve(int CASE = -1) {
    int m;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        adj[1].push_back(2 + i);
        adj[2 + i].push_back(1);
        cap[1][2 + i] = a;
    }
    for (int i = 1; i <= m; i++) {
        int b;
        cin >> b;
        adj[2].push_back(2 + n + i);
        adj[2 + n + i].push_back(2);
        cap[2 + n + i][2] = b;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost;
            cin >> cost;
            if (cost == 0) continue;
            adj[i + n + 2].push_back(j + 2);
            adj[j + 2].push_back(i + n + 2);
            cap[j + 2][i + n + 2] = cost;
        }
    }

    cout << maxFlow(1, 2);
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