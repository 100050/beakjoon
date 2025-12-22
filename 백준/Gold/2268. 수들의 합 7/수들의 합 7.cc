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

vector<ll> st; // 4*n

ll make_st(ll node, int start, int end) {
    if (start == end)
        return st[node] = 0; // 초기화 값 필요하다면 변경
    int mid = (start + end) / 2;
    ll left = make_st(node * 2, start, mid);
    ll right = make_st(node * 2 + 1, mid + 1, end);
    st[node] = left + right;

    return st[node];
}

void update(ll node, int start, int end, int index, ll diff) {
    if (index < start || index > end) return;
    st[node] += diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

ll get(ll node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return st[node];

    int mid = (start + end) / 2;
    return get(node * 2, start, mid, left, right)
        + get(node * 2 + 1, mid + 1, end, left, right);
}

void solve(int CASE = -1) {
    int n, m;
    vector<ll> arr;

    cin >> n >> m;
    st.resize(4 * n, 0);
    arr.resize(n);
    for (int i = 0; i < m; i++) {
        int mod, j, k;

        cin >> mod >> j >> k;
        if (mod) {
            update(1, 0, n - 1, j-1, k-arr[j-1]);
            arr[j - 1] = k;
        }
        else {
            if (j > k) swap(j, k);
            ll s = get(1, 0, n-1, j-1, k-1);

            cout << s << "\n";
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