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


struct Edge {
    int v, cap, rev;
    Edge(int _v, int _cap, int _rev) : v(_v), cap(_cap), rev(_rev) {}
};

const int MAX = 20001;
int n;
array<vector<Edge>, MAX> adj;
array<int, MAX> m, g, level, work;

void insert_edge(int a, int b, int cost) {
    adj[a].emplace_back(b, cost, adj[b].size());
    adj[b].emplace_back(a, 0, adj[a].size() - 1);
}

bool bfs(int start, int end) {
    fill(level.begin(), level.end(), -1);
    queue<int> q;
    q.push(start);
    level[start] = 0;

    while (q.size()) {
        int f = q.front(); q.pop();

        for (Edge& nxt : adj[f]) {
            if (level[nxt.v] == -1 && nxt.cap > 0) {
                level[nxt.v] = level[f] + 1;
                q.push(nxt.v);
            }
        }
    }

    return level[end] != -1;
}

int dfs(int v, int end, int f) {
    if (v == end) return f;
    for (int& i = work[v]; i < adj[v].size(); i++) {
        Edge& nxt = adj[v][i];
        if (level[nxt.v] == level[v] + 1 && nxt.cap > 0) {
            int df = dfs(nxt.v, end, min(f, nxt.cap));

            if (df > 0) {
                nxt.cap -= df;
                adj[nxt.v][nxt.rev].cap += df;
                return df;
            }
        }
    }

    return 0;
}

void solve(int CASE = -1) { 
    int m;
    array<array<char, 100>, 100> mp;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
        }
    }

    int start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == '#') continue;

            if (mp[i][j] == 'K') {
                start = 1 + i * m + j + n * m;
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if (0 <= ny && ny < n && 0 <= nx && nx < m && mp[ny][nx] != '#') {
                        if (mp[ny][nx] == 'H') {
                            cout << -1;
                            return;
                        }
                        else {
                            insert_edge(1 + i * m + j + n * m, 1 + ny * m + nx, 100*100);
                        }
                    }
                }
            }
            else if (mp[i][j] == 'H') end = 1 + i * m + j;
            else {
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if (0 <= ny && ny < n && 0 <= nx && nx < m && mp[ny][nx] != '#') {
                        if (mp[ny][nx] == 'H')
                            insert_edge(1 + i * m + j + n * m, 1 + ny * m + nx, 100 * 100);
                        else if (mp[ny][nx] == 'K') continue;
                        else
                            insert_edge(1 + i * m + j + n*m, 1 + ny * m + nx, 1);
                    }
                }
            }
        }
    }

    for (int i = 0; i < n * m; i++) {
        insert_edge(1 + i, 1 + i + n * m, 1);
    }

    int res = 0;
    while (bfs(start, end)) {
        fill(work.begin(), work.end(), 0);

        while (1) {
            int flow = dfs(start, end, INF<int>);
            if (flow == 0) break;
            res += flow;
        }
    }

    cout << res << "\n";
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