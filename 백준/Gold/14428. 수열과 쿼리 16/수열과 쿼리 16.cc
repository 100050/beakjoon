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

vector<ll> arr;
vector<pil> st;

pil make_st(ll node, int start, int end) {
    if (start == end)
        return st[node] = make_pair(arr[start], start);
    int mid = (start + end) / 2;
    pil&& left = make_st(node * 2, start, mid);
    pil&& right = make_st(node * 2 + 1, mid + 1, end);
    st[node] = min(left, right);

    return st[node];
}

void update(ll node, int start, int end, int index, ll ne, int n) {
    if (index < start || index > end) return;
    if (start == end) st[node] = make_pair(ne, start);

    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, ne, n);
        update(node * 2 + 1, mid + 1, end, index, ne, n);
        st[node] = min(st[node * 2], st[node * 2 + 1]);
    }
}

pil get(ll node, int start, int end, int left, int right) {
    if (left > end || right < start) return make_pair((ll)1e9, 100000LL);
    if (left <= start && end <= right) return st[node];

    int mid = (start + end) / 2;
    return min(get(node * 2, start, mid, left, right)
        , get(node * 2 + 1, mid + 1, end, left, right));
}

void solve(int CASE = -1) {
    int n, q;

    cin >> n;

    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        arr.push_back(a);
    }
    st.resize(1 << ((int)ceil(log2(n)) + 1));
    make_st(1LL, 0, n - 1);

    cin >> q;
    while(q--) {
        int s;
        cin >> s;
        if (s == 1) {
            int i, v;
            cin >> i >> v;
            update(1LL, 0, n - 1, i-1, v, n);
        }
        else {
            int i, j;
            cin >> i >> j;
            cout << get(1LL, 0, n - 1, i - 1, j - 1).second+1 << "\n";
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