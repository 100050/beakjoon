#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <unordered_set>
#include <queue>
#include <stack>
#include <ranges>
#include <numeric>
#include <cstring>
#include <bit>
using namespace std;

using ull = unsigned long long;
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


void solve(int CASE = -1) {
    int n, m, x, k;
    vector<vector<int>> g;
    vector<int> v, visited;

    cin >> n >> m >> k >> x;
    g.resize(n + 1);
    v.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    // g의 그래프에서 x에서 시작해서 bfs로 최단거리가 k인 정점들을 찾는다.
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    v[x] = 0;

    while (q.size()) {
        int node = q.front(); q.pop();

        for (int nxt : g[node]) {
            if (visited[nxt]) continue;

            q.push(nxt);
            v[nxt] = v[node] + 1;
            visited[nxt] = 1;
        }
    }

    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (v[i] == k) {
            cout << i << "\n";
            flag = false;
        }
    }

    if (flag) cout << -1;
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