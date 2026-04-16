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
    vector<array<ll, 2>> lazy; // 4*n or 1 << ((int)ceil(log2(n)) + 1)으로 초기화

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

    void update_lazy(const ll node, const int start, const int end) {
        if (lazy[node][0] != 1 || lazy[node][1] != 0) {
            ll t = st[node];
            array<ll, 2>& diff = lazy[node];
            
            st[node] = (t * diff[0]) % MOD + ((end - start + 1) * diff[1]) % MOD;
            st[node] %= MOD;
            
            if (start != end) {
                lazy[node * 2][0] *= diff[0];
                lazy[node * 2][0] %= MOD;
                lazy[node * 2][1] *= diff[0];
                lazy[node * 2][1] %= MOD;
                lazy[node * 2][1] += diff[1];
                lazy[node * 2][1] %= MOD;
                lazy[node * 2 + 1][0] *= diff[0];
                lazy[node * 2 + 1][0] %= MOD;
                lazy[node * 2 + 1][1] *= diff[0];
                lazy[node * 2 + 1][1] %= MOD;
                lazy[node * 2 + 1][1] += diff[1];
                lazy[node * 2 + 1][1] %= MOD;
            }
            lazy[node] = { 1, 0 };
        }
    }

    void _update(const ll node, const int start, const int end,
        const int left, const int right, const array<ll, 2>& diff) {
        update_lazy(node, start, end);

        if (right < start || left > end) return;

        if (left <= start && end <= right) {
            ll t = st[node];
            st[node] = (t * diff[0]) % MOD + ((end - start + 1) * diff[1]) % MOD;
            st[node] %= MOD;

            // Av+u, (A+v)u
            if (start != end) {

                lazy[node * 2][0] *= diff[0];
                lazy[node * 2][0] %= MOD;
                lazy[node * 2][1] *= diff[0];
                lazy[node * 2][1] %= MOD;
                lazy[node * 2][1] += diff[1];
                lazy[node * 2][1] %= MOD;
                lazy[node * 2 + 1][0] *= diff[0];
                lazy[node * 2 + 1][0] %= MOD;
                lazy[node * 2 + 1][1] *= diff[0];
                lazy[node * 2 + 1][1] %= MOD;
                lazy[node * 2 + 1][1] += diff[1];
                lazy[node * 2 + 1][1] %= MOD;
            }
            return;
        }

        int mid = (start + end) / 2;
        _update(node * 2, start, mid, left, right, diff);
        _update(node * 2 + 1, mid + 1, end, left, right, diff);
        st[node] = st[node * 2] + st[node * 2 + 1];
        st[node] %= MOD;
    }

    T _get(const ll node, const int start, const int end, const int left, const int right) {
        update_lazy(node, start, end);

        if (left > end || right < start) return 0;
        if (left <= start && end <= right) return st[node];

        int mid = (start + end) / 2;
        return (_get(node * 2, start, mid, left, right)
            + _get(node * 2 + 1, mid + 1, end, left, right)) % MOD;
    }

public:
    SegmentTree() = default;

    void init(const int n, const T& val = 0) {
        this->n = n;
        st.resize(1 << ((int)ceil(log2(n)) + 1));
        lazy.resize(1 << ((int)ceil(log2(n)) + 1));
        if (val != 0) _init(1LL, 0, n - 1, val);
    }

    void init(const int n, const vector<T>& arr) {
        this->n = n;
        st.resize(1LL << ((int)ceil(log2(n)) + 1));
        lazy.resize(1LL << ((int)ceil(log2(n)) + 1), { 1, 0 });
        _init(1LL, 0, n - 1, arr);
    }

    void update(const int left, const int right, const array<ll, 2>& diff) {
        _update(1LL, 0, n - 1, left, right, diff);
    }

    T get(const int left, const int right) {
        return _get(1LL, 0, n - 1, left, right);
    }
};



void solve(int CASE = -1) {
    int n;
    vector<ll> arr;
    SegmentTree<ll> st;

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    st.init(n, arr);

    int m;
    cin >> m;
    while (m--) {
        int q, x, y, v;

        cin >> q >> x >> y;
        x--;
        y--;
        if (q == 4) {
            cout << st.get(x, y) << "\n";
        }
        else {
            cin >> v;
            if (q == 1) {
                st.update(x, y, { 1, v });
            }
            else if (q == 2) {
                st.update(x, y, { v, 0 });
            }
            else {
                st.update(x, y, { 0, v });
            }
        }
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