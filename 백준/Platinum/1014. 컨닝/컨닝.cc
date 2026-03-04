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

vector<int> match, visited;
vector<vector<int>> adj;


bool dfs(int v) {
    visited[v] = 1;

    for (int nxt : adj[v]) {
        //cout << v << " " << nxt << "\n";
        if (visited[match[nxt]]) continue;

        if (match[nxt] == 0 || dfs(match[nxt])) {
            match[v] = nxt;
            match[nxt] = v;

            return true;
        }
    }
    return false;
}

void solve(int CASE = -1) {
    int n, m, mx = 0;
    vector<vector<char>> arr;
    
    cin >> n >> m;
    mx = n * m;
    arr.resize(n);
    adj.resize(m * n + 1);
    match.resize(m * n + 1);
    visited.resize(m * n + 1);
    for (int i = 0; i < n; i++) {
        arr[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            mx -= arr[i][j] == 'x';
        }
    }

    // 간선 생성
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'x') continue;
            if (i >= 1 && j + 1 < m && arr[i - 1][j + 1] != 'x')
                adj[i * m + j + 1].push_back((i - 1) * m + (j + 1) + 1);
            if (i >= 1 && j >= 1 && arr[i - 1][j - 1] != 'x')
                adj[i * m + j + 1].push_back((i - 1) * m + (j - 1) + 1);

            if (j + 1 < m && arr[i][j + 1] != 'x')
                adj[i * m + j + 1].push_back((i) * m + (j + 1) + 1);
            if (j >= 1 && arr[i][j - 1] != 'x')
                adj[i * m + j + 1].push_back((i) * m + (j - 1) + 1);

            if (i + 1 < n && j + 1 < m && arr[i + 1][j + 1] != 'x')
                adj[i * m + j + 1].push_back((i + 1) * m + (j + 1) + 1);
            if (i + 1 < n && j >= 1 && arr[i + 1][j - 1] != 'x')
                adj[i * m + j + 1].push_back((i + 1) * m + (j - 1) + 1);
        }
    }

    int res = 0;
    for (int i = 1; i <= n*m; i++) {
        fill(visited.begin(), visited.end(), 0);
        if (match[i]) continue;
        if (dfs(i)) res++;
        //cout << i << " " << res << "\n";
    }

    cout << mx - res << "\n";

    match.clear();
    adj.clear();
    visited.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}