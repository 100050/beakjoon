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
    int n, m;
    vector<int> arr, deg;
    vector<vector<int>> adj;

    cin >> n >> m;
    adj.resize(n + 1);
    deg.resize(n + 1);
    while(m--) {
        int t;
        cin >> t;
        int pre = -1;
        while (t--) {
            int v;
            cin >> v;
            if (pre != -1) {
                deg[v]++;
                adj[pre].push_back(v);
                adj[v].push_back(pre);
            }
            pre = v;
        }
    }

    vector<int> res;
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.push(i);
            res.push_back(i);
        }
    }

    while (!q.empty()) {
        int f = q.front(); q.pop();

        for (int nxt : adj[f]) {
            if (--deg[nxt] == 0) {
                q.push(nxt);
                res.push_back(nxt);
            }
        }
    }

    if (res.size() != n) cout << 0;
    else {
        for (int v : res)
            cout << v << "\n";
    }
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