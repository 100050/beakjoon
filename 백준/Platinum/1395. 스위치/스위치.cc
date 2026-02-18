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

vector<ll> st, lazy; // 4*n or 1 << ((int)ceil(log2(n)) + 1)으로 초기화

void update_lazy(ll node, int start, int end) {
    if (lazy[node] != 0) {
        st[node] = (end - start + 1) - st[node];
        if (start != end) {
            lazy[node * 2] ^= lazy[node];
            lazy[node * 2 + 1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(ll node, int start, int end, int left, int right, ll diff) {
    update_lazy(node, start, end);

    if (right < start || left > end) return;

    if (left <= start && end <= right) {
        if (diff == 1) st[node] = (end - start + 1) - st[node];
        if (start != end) {
            lazy[node * 2] ^= diff;
            lazy[node * 2 + 1] ^= diff;
        }
        return;
    }

    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, diff);
    update(node * 2 + 1, mid + 1, end, left, right, diff);
    st[node] = st[node * 2] + st[node * 2 + 1];
}

ll get(ll node, int start, int end, int left, int right) {
    update_lazy(node, start, end);

    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return st[node];

    int mid = (start + end) / 2;
    return get(node * 2, start, mid, left, right)
        + get(node * 2 + 1, mid + 1, end, left, right);
}

void solve(int CASE = -1) {
    int n, m;
    
    cin >> n;
    lazy.resize(4 * n);
    st.resize(4 * n);
    
    cin >> m;
    while (m--) {
        int a, b, c;
        ll d;
        cin >> a;

        if (a == 0) {
            cin >> b >> c;
            update(1, 0, n - 1, b-1, c-1, 1);
            //cout << get(1, 0, n - 1, b - 1, c - 1) << "\n";
        }
        else if (a == 1) {
            cin >> b >> c;
            cout << get(1, 0, n-1, b-1, c-1) << "\n";
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