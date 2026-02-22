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

template<typename T>
class SegmentTree {
    vector<T> st; // 4*n or 1 << ((int)ceil(log2(n)) + 1)으로 초기화
    int n = 0;

    void _init(const ll node, const int start, const int end, const vector<T>& arr) {
        if (start == end) {
            st[node] = arr[start];
        } 
        else {
            _init(node * 2, start, (start + end) / 2, arr);
            _init(node * 2 + 1, (start + end) / 2 + 1, end, arr);
            st[node].resize(st[node * 2].size() + st[node * 2 + 1].size());
            merge(st[node * 2].begin(), st[node * 2].end(), 
                st[node * 2 + 1].begin(), st[node * 2 + 1].end(),
                st[node].begin());
        }
    }

    void _init(const ll node, const int start, const int end, const ll& val = 0) {
        if (start == end) {
            st[node] = val;
        }
        else {
            _init(node * 2, start, (start + end) / 2, val);
            _init(node * 2 + 1, (start + end) / 2 + 1, end, val);
            st[node] = st[node * 2] + st[node * 2 + 1];
        }
    }

    void _update(const ll node, const int start, const int end, 
        const int index, const T& diff) {
        
        if (index < start || index > end) return;

        st[node] += diff;
        if (start != end) {
            int mid = (start + end) / 2;
            _update(node * 2, start, mid, index, diff);
            _update(node * 2 + 1, mid + 1, end, index, diff);
            st[node] = st[node * 2] + st[node * 2 + 1];
        }

    }

    T _get(const ll node, const int start, const int end, const int left, const int right) {
        if (left > end || right < start) return 0;
        if (left <= start && end <= right) return st[node];

        int mid = (start + end) / 2;
        return _get(node * 2, start, mid, left, right)
            + _get(node * 2 + 1, mid + 1, end, left, right);
    }

    ll _get(const ll node, const int start, const int end, const int left, const int right, const ll& v) {
        if (left > end || right < start) return 0;
        if (left <= start && end <= right) {
            return upper_bound(st[node].begin(), st[node].end(), v) - st[node].begin();
        }
        int mid = (start + end) / 2;
        return _get(node * 2, start, mid, left, right, v)
            + _get(node * 2 + 1, mid + 1, end, left, right, v);
    }

public:
    SegmentTree() = default;

    void init(const int n, const T& val = 0) {
        this->n = n;
        st.resize(1 << ((int)ceil(log2(n)) + 1));
        if (val != 0) _init(1LL, 0, n - 1, val);
    }

    void init(const int n, const vector<T>& arr) {
        this->n = n;
        st.resize(1 << ((int)ceil(log2(n)) + 1));
        _init(1LL, 0, n - 1, arr);
    }

    void update(const int index, const ll& diff) {
        _update(1LL, 0, n - 1, index, diff);
    }

    ll get(const int left, const int right) {
        return _get(1LL, 0, n - 1, left, right);
    }

    ll get(const int left, const int right, const ll& v) {
        return _get(1LL, 0, n - 1, left, right, v);
    }

};

int cnt = 0;
vector<pii> range;
vector<int> adj[200'001];

void dfs(int x, int par) {
    range[x].first = ++cnt;

    for (int nxt : adj[x]) {
        if (nxt == par) continue;
        dfs(nxt, x);
    }

    range[x].second = cnt;
}

void solve(int CASE = -1) {
    int n, m, c;
    vector<int> color;

    cin >> n >> m >> c;
    color.resize(n);
    range.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> color[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    dfs(0, -1);

    ll res = 0;
    SegmentTree<vector<int>> st;
    vector<vector<int>> arr(n+1, vector<int>(1));
    //cout << 1;
    for (int i = 0; i < n; i++) {
        arr[range[i].first][0] = color[i];
    }
    st.init(n + 1, arr);

    while (m--) {
        int v, c;
        cin >> v >> c;

        res = (res + st.get(range[v - 1].first, range[v - 1].second, c)) % MOD;
    }
    cout << res << "\n";
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