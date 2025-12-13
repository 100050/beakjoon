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

vector<ll> st;

ll make_st(ll node, int start, int end) {
    if (start == end)
        return st[node] = 0;
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
    int n;
    vector<int> idx;
    ll res = 0;

    cin >> n;
    st.resize(8 * n);
    //make_st(1LL, 0, n - 1);
    idx.resize(n + 1, -1);
    for (int i = 0; i < 2*n; i++) {
        int m;
        cin >> m;

        if (idx[m] == -1) {
            idx[m] = i;

            update(1LL, 0, 2*n - 1, i, 1);
        }
        else {
            res += get(1LL, 0, 2*n - 1, idx[m]+1, i);
            update(1LL, 0, 2*n - 1, idx[m], -1);
        }
    }

    cout << res;
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