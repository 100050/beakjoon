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
//constexpr ll MOD = 10007;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

template<typename T>
class SegmentTree {
    int n;
    vector<T> st, lazy; // 4*n or 1 << ((int)ceil(log2(n)) + 1)으로 초기화

    void _init(const ll node, const int start, const int end, const vector<T>& arr) {
        if (start == end) {
            st[node] = arr[start];
        }
        else {
            _init(node * 2, start, (start + end) / 2, arr);
            _init(node * 2 + 1, (start + end) / 2 + 1, end, arr);
            st[node] = st[node * 2] + st[node * 2 + 1];
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
        if (lazy[node] != 0) {
            st[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void _update(const ll node, const int start, const int end,
        const int left, const int right, const T& diff) {
        update_lazy(node, start, end);

        if (right < start || left > end) return;

        if (left <= start && end <= right) {
            st[node] += (end - start + 1) * diff;
            if (start != end) {
                lazy[node * 2] += diff;
                lazy[node * 2 + 1] += diff;
            }
            return;
        }

        int mid = (start + end) / 2;
        _update(node * 2, start, mid, left, right, diff);
        _update(node * 2 + 1, mid + 1, end, left, right, diff);
        st[node] = st[node * 2] + st[node * 2 + 1];
    }

    T _get(const ll node, const int start, const int end, const int left, const int right) {
        update_lazy(node, start, end);

        if (left > end || right < start) return 0;
        if (left <= start && end <= right) return st[node];

        int mid = (start + end) / 2;
        return _get(node * 2, start, mid, left, right)
            + _get(node * 2 + 1, mid + 1, end, left, right);
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
        lazy.resize(1LL << ((int)ceil(log2(n)) + 1));
        _init(1LL, 0, n - 1, arr);
    }

    void update(const int left, const int right, const T& diff) {
        _update(1LL, 0, n - 1, left, right, diff);
    }

    T get(const int left, const int right) {
        return _get(1LL, 0, n - 1, left, right);
    }
};

void solve(int CASE = -1) {
	int n;
    vector<ll> arr, arr2;
    SegmentTree<ll> st;

	cin >> n;
	arr.resize(n);
    arr2.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
        if (i == 0) arr2[i] = arr[i];
        else arr2[i] = arr[i] - arr[i - 1];
	}

    st.init(n, arr2);

	int q;

	cin >> q;
	while (q--) {
		int s;
		
		cin >> s;

		if (s == 1) {
			int a, b;
			cin >> a >> b;
			st.update(a - 1, b - 1, 1);
            if (b != n) st.update(b, b, -(b - a + 1));
		}
		else {
			int x;
			cin >> x;
			cout << st.get(0, x - 1) << "\n";
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