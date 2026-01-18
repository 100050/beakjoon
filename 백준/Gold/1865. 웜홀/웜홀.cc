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
constexpr T INF = numeric_limits<T>::max();
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

int n, m, w;
vector<pair<pii, int>> adj;
int dist[501];

bool bellmanford(int s) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF<int>/2;
    }
    dist[s] = 0;

    for (int i = 1; i <= n; i++) {
        for (auto& e : adj) {
            auto& v = e.first;
            auto& t = e.second;

            if (dist[v.first] + t < dist[v.second]) {
                dist[v.second] = dist[v.first] + t;
            }
        }
    }

    for (auto& e : adj) {
        auto& v = e.first;
        auto& t = e.second;

        if (dist[v.first] + t < dist[v.second]) {
            return false;
        }
    }

    return true;
}

void solve(int CASE = -1) {
    adj.clear();

    cin >> n >> m >> w;
    for (int i = 0; i < m; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        adj.push_back(make_pair(make_pair(s, e), t));
        adj.push_back(make_pair(make_pair(e, s), t));
    }
    for (int i = 0; i < w; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        t = -t;
        adj.push_back(make_pair(make_pair(s, e), t));
    }

    if (bellmanford(1) == false) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
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