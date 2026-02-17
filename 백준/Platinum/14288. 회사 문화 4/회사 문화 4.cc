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

vector<ll> st1, st2; // 4*n or 1 << ((int)ceil(log2(n)) + 1)으로 초기화

void update1(ll node, int start, int end, int index, ll diff) {
    if (index < start || index > end) return;
    st1[node] += diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update1(node * 2, start, mid, index, diff);
        update1(node * 2 + 1, mid + 1, end, index, diff);
    }
}

void update2(ll node, int start, int end, int index, ll diff) {
    if (index < start || index > end) return;
    st2[node] += diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update2(node * 2, start, mid, index, diff);
        update2(node * 2 + 1, mid + 1, end, index, diff);
    }
}

ll get1(ll node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return st1[node];

    int mid = (start + end) / 2;
    return get1(node * 2, start, mid, left, right)
        + get1(node * 2 + 1, mid + 1, end, left, right);
}

ll get2(ll node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return st2[node];

    int mid = (start + end) / 2;
    return get2(node * 2, start, mid, left, right)
        + get2(node * 2 + 1, mid + 1, end, left, right);
}

int cnt = 0;
vector<pii> range;
vector<int> adj[100'001];

void dfs(int x, int par) {
    range[x].first = ++cnt;

    for (int nxt : adj[x]) {
        if (nxt == par) continue;
        dfs(nxt, x);
    }

    range[x].second = cnt;
}

void solve(int CASE = -1) {
    int n, m;
    vector<int> par;

    cin >> n >> m;
    par.resize(n+1);
    range.resize(n+1);
    st1.resize(4 * (n + 1));
    st2.resize(4 * (n + 1));
    cin >> par[1];
    for (int i = 2; i <= n; i++) {
        cin >> par[i];
        adj[i].push_back(par[i]);
        adj[par[i]].push_back(i);
    }

    dfs(1, par[1]);

    bool d = true; // true: 아래쪽 칭찬, false: 윗쪽 칭찬
    while (m--) {
        int q, i, w;
        cin >> q;

        if (q == 1) {
            cin >> i >> w;
            //cout << range[i].first << " " << range[i].second << "\n";
            if (d) {
                update1(1, 0, n, range[i].first, w);
                if (range[i].second != n)
                    update1(1, 0, n, range[i].second + 1, -w);
            }
            else {
                update2(1, 0, n, range[i].first, w);
            }
        }
        else if (q == 2) {
            cin >> i;
            cout << get1(1, 0, n, 0, range[i].first)
                + get2(1, 0, n, range[i].first, range[i].second) << "\n";
        }
        else {
            d = !d;
        }
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