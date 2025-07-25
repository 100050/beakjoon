#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <cstdlib>   
#include <ctime> 
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

vector<ll> arr;
vector<ll> st;

ll make_st(ll node, int start, int end) {
    if (start == end)
        return st[node] = arr[start];
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

void solve() {
    int n, m, k;
    ll a, b, c;

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    st.resize(4*n);
    make_st(1LL, 0, n-1);

    for (int i = 0; i < m + k; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            update(1LL, 0, n - 1, b - 1, c - arr[b - 1]);
            arr[b - 1] = c;
        }
        else {
            cin >> b >> c;
            cout << get(1LL, 0, n - 1, b - 1, c - 1) << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}