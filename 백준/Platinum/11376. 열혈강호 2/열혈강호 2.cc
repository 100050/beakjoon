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

int n, m;
vector<int> adj[2001];
vector<int> visited, match;

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

    cin >> n >> m;
    match.resize(m + 1);
    visited.resize(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int t;
            cin >> t;
            adj[i].push_back(t);
            adj[i + n].push_back(t);
        }
    }
    
    int res = 0;
    vector<bool> g(2*n + 1);
    for (int i = 1; i <= 2 *n; i++) {
        for (int nxt : adj[i]) {
            if (match[nxt] == 0) {
                match[nxt] = i;
                res++;
                g[i] = true;
                break;
            }
        }
    }

    for (int i = 1; i <= 2 * n; i++) {
        if (g[i]) continue;
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