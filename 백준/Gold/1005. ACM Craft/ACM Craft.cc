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

void solve(int CASE = -1) {
    int n, k, w;
    vector<int> d, degree, dp, adj[1001];

    cin >> n >> k;
    d.resize(n + 1);
    degree.resize(n + 1);
    dp.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 1; i <= k; i++) {
        int x, y;

        cin >> x >> y;
        degree[y]++;
        adj[x].push_back(y);
    }
    cin >> w;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            dp[i] = d[i];
            q.push(i);
        }
    }

    while (q.size()) {
        int f = q.front();  q.pop();

        for (int v : adj[f]) {
            if (--degree[v] == 0) {
                q.push(v);
            }
            dp[v] = max(dp[v], dp[f] + d[v]);
        }
    }

    cout << dp[w] << "\n";
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