#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <unordered_set>
#include <queue>
#include <stack>
#include <ranges>
#include <numeric>
#include <cstring>
#include <bit>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

constexpr ll MOD = 1000000007;
//constexpr ll MOD = 1000000000;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };


template<typename T>
class SegmentTree {
    int n;
    vector<T> st;
    vector<array<int, 2>> lazy; // 4*n or 1 << ((int)ceil(log2(n)) + 1)으로 초기화

    void _init(const ll node, const int start, const int end, const vector<T>& arr) {
        if (start == end) {
            st[node] = arr[start];
        }
        else {
            _init(node * 2, start, (start + end) / 2, arr);
            _init(node * 2 + 1, (start + end) / 2 + 1, end, arr);
            st[node] = st[node * 2] + st[node * 2 + 1];
            st[node] %= MOD;
        }
    }

    void _init(const ll node, const int start, const int end, const T& val = 0) {
        if (start == end) {
            st[node] = val;
        }
        else {
            _init(node * 2, start, (start + end) / 2, val);
            _init(node * 2 + 1, (start + end) / 2 + 1, end, val);
            st[node] = st[node * 2] + st[node * 2 + 1];
        }
    }

    void push(const ll node, const int op, const int v) {
        if (op == 1) {
            st[node][0] = max(st[node][0], v);
            st[node][1] = max(st[node][1], v);
        }
        else {
            st[node][0] = min(st[node][0], v);
            st[node][1] = min(st[node][1], v);
        }
    }

    void push2(const ll node, const int op, const int v) {
        if (op == 1) {
            lazy[node][0] = max(lazy[node][0], v);
            lazy[node][1] = max(lazy[node][1], v);
        }
        else {
            lazy[node][0] = min(lazy[node][0], v);
            lazy[node][1] = min(lazy[node][1], v);
        }
    }

    void update_lazy(const ll node, const int start, const int end) {
        if (lazy[node][0] != 0 || lazy[node][1] != INF<int>) {
            array<int, 2>& diff = lazy[node];
            
            push(node, 1, diff[0]);
            push(node, 2, diff[1]);

            if (start != end) {
                push2(node * 2, 1, diff[0]);
                push2(node * 2, 2, diff[1]);
                push2(node * 2 + 1, 1, diff[0]);
                push2(node * 2 + 1, 2, diff[1]);
            }
            lazy[node] = { 0, INF<int> };
        }
    }

    void _update(const ll node, const int start, const int end,
        const int left, const int right, const array<int, 2>& diff) {
        update_lazy(node, start, end);

        if (right < start || left > end) return;

        if (left <= start && end <= right) {
            push(node, 1, diff[0]);
            push(node, 2, diff[1]);

            if (start != end) {
                push2(node * 2, 1, diff[0]);
                push2(node * 2, 2, diff[1]);
                push2(node * 2 + 1, 1, diff[0]);
                push2(node * 2 + 1, 2, diff[1]);
            }
            return;
        }

        int mid = (start + end) / 2;
        _update(node * 2, start, mid, left, right, diff);
        _update(node * 2 + 1, mid + 1, end, left, right, diff);
        T& l = st[node * 2];
        T& r = st[node * 2 + 1];
        st[node] = { min(l[0], r[0]), max(l[1], r[1]) };
    }
    

    T _get(const ll node, const int start, const int end, const int left, const int right) {
        update_lazy(node, start, end);

        if (left > end || right < start) return { INF<int>, 0 };
        if (left <= start && end <= right) return st[node];

        int mid = (start + end) / 2;
        T l = _get(node * 2, start, mid, left, right);
        T r = _get(node * 2 + 1, mid + 1, end, left, right);

        return { min(l[0], r[0]), max(l[1], r[1]) };
    }

public:
    SegmentTree() = default;

    void init(const int n, const T& val = 0) {
        this->n = n;
        st.resize(1LL << ((int)ceil(log2(n)) + 1));
        // lazy 초기화
        lazy.resize(1LL << ((int)ceil(log2(n)) + 1), { 0, INF<int> });
        //if (val != 0) _init(1LL, 0, n - 1, val);
    }

    void init(const int n, const vector<T>& arr) {
        this->n = n;
        st.resize(1LL << ((int)ceil(log2(n)) + 1));
        // lazy 초기화
        lazy.resize(1LL << ((int)ceil(log2(n)) + 1), { -1, -1 });
        _init(1LL, 0, n - 1, arr);
    }

    void update(const int left, const int right, const array<int, 2>& diff) {
        _update(1LL, 0, n - 1, left, right, diff);
    }

    T get(const int left, const int right) {
        return _get(1LL, 0, n - 1, left, right);
    }
};



void solve(int CASE = -1) {
    int n, k;
    SegmentTree<array<int, 2>> st;

    cin >> n >> k;
    
    st.init(n, { 0, 0 });

    while (k--) {
        int q, x, y, v;

        cin >> q >> x >> y >> v;
        if (q == 1) {
            st.update(x, y, { v, INF<int> });
        }
        else if (q == 2) {
            st.update(x, y, { 0, v });
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << st.get(i, i)[0] << "\n";
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