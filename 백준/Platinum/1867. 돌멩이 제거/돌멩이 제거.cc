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

int n, res = 0;
vector<int> visited, match;
vector<vector<int>> adj;

bool dfs(int v) {
    visited[v] = 1;

    for (int nxt : adj[v]) {
        if (visited[match[nxt]]) continue;

        if (match[nxt] == 0 || dfs(match[nxt])) {
            match[nxt] = v;

            return true;
        }
    }

    return false;
}

void solve(int CASE = -1) {
    int k;

    cin >> n >> k;
    adj.resize(n+1);
    match.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        fill(visited.begin(), visited.end(), 0);
        if (dfs(i)) res++;
    }

    cout << res;
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