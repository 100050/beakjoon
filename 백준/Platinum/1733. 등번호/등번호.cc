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
vector<int> res, visited, check;
vector<pii> adj[1'000'001];

bool dfs(int v, int pre) {
    visited[v] = 1;

    for (const auto& [nxt, e] : adj[v]) {
        if (pre == nxt) continue;

        if (!visited[nxt] && !dfs(nxt, v)) return false;
        else {
            if (res[e] != 0) continue;

            //cout << v << " " << nxt << " " << e << "\n";
            if (!check[nxt]) {
                res[e] = nxt;
                check[nxt] = 1;
            }
            else if (!check[v]) {
                res[e] = v;
                check[v] = 1;
            }
            else {
                return false;
            }
        }
    }

    return true;
}

void solve(int CASE = -1) {

    cin >> n;
    res.resize(n);
    visited.resize(1'000'001);
    check.resize(1'000'001);
    for (int i = 0; i < n; i++) {
        int  a, b;
        cin >> a >> b;
        adj[a].push_back(make_pair(b, i));
        adj[b].push_back(make_pair(a, i));
    }

    for (int i = 1; i <= 1'000'000; i++) {
        if (!check[i] && !dfs(i, -1)) {
            //cout << i << " ";
            cout << -1 << "\n";
            return;
        }
    }

    for (int r : res) {
        cout << r << "\n";
    }
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