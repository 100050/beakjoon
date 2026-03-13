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


const int MAX = 504;
int n;
array<vector<int>, MAX> adj;
array<array<int, MAX>, MAX> cap, flow;
array<int, MAX> m, g, level, work;

void insert_edge(int a, int b, int cost) {
    adj[a].push_back(b);
    adj[b].push_back(a);
    cap[a][b] = cost;
}

bool bfs(int start, int end) {
    fill(level.begin(), level.end(), -1);
    queue<int> q;
    q.push(start);
    level[start] = 0;

    while (q.size()) {
        int f = q.front(); q.pop();

        for (int nxt : adj[f]) {
            if (level[nxt] == -1 && cap[f][nxt] - flow[f][nxt] > 0) {
                level[nxt] = level[f] + 1;
                q.push(nxt);
            }
        }
    }

    return level[end] != -1;
}

int dfs(int v, int f) {
    if (v == 2) return f;
    for (int& i = work[v]; i < adj[v].size(); i++) {
        int nxt = adj[v][i];
        if (level[nxt] == level[v] + 1 && cap[v][nxt] - flow[v][nxt] > 0) {
            int df = dfs(nxt, min(f, cap[v][nxt] - flow[v][nxt]));

            if (df > 0) {
                flow[v][nxt] += df;
                flow[nxt][v] -= df;
                return df;
            }
        }
    }

    return 0;
}

void solve(int CASE = -1) {

    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            insert_edge(1, i+1+2, INF<int>);
            g[i+1+2] = 1;
        }
        else if (t == 2) {
            insert_edge(i+1+2, 2, INF<int>);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int c;
            cin >> c;
            if (i == j) continue;
            insert_edge(i + 1 + 2, j + 1 + 2, c);
        }
    }

    int res = 0;
    while (bfs(1, 2)) {
        fill(work.begin(), work.end(), 0);

        while (1) {
            int flow = dfs(1, INF<int>);
            if (flow == 0) break;
            res += flow;
        }
    }

    // 그룹 찾기
    queue<int> q;
    array<bool, MAX> visited{ 0, };
    q.push(1);
    visited[1] = true;
    while (q.size()) {
        int f = q.front(); q.pop();

        for (int nxt : adj[f]) {
            if (visited[nxt] || cap[f][nxt] - flow[f][nxt] <= 0) continue;

            visited[nxt] = true;
            q.push(nxt);
            g[nxt] = 1;
        }

    }

    cout << res << "\n";
    for (int i = 0; i < n; i++) {
        if (g[i+1+2] == 1) cout << i + 1 << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        if (g[i+1+2] != 1) cout << i + 1 << " ";
    }
    cout << "\n";
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