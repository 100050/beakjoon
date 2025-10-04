#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
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
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n, p, k;
// (정점, 가중치)
vector<pii> adj[1001];

int f(int x) {
    // 다익스트라
    // (x보다 큰 간선의 수, 정점)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> d(n + 1, INF<int>);

    d[1] = 0;
    pq.push(make_pair(0, 1));
    while (pq.size()) {
        pii top = pq.top(); pq.pop();

        for (pii& next : adj[top.second]) {
            if (top.first + (next.second > x) < d[next.first]) {
                d[next.first] = top.first + (next.second > x);
                pq.push(make_pair(d[next.first], next.first));
            }
        }
    }

    return d[n];
}

void solve(int CASE = -1) {
    int mn = INF<int>;
    cin >> n >> p >> k;
    for (int i = 0; i < p; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
        mn = min(mn, c);
    }

    int l = 0, r = 1000000;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int ret = f(mid);
        if (ret == INF<int>) {
            r = -1;
            break;
        }
        else if (l == r) {
            r = mid;
            break;
        }
        else if (ret <= k) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << r;
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