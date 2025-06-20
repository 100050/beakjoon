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
vector<pil> st;

pil make_st(ll node, int start, int end) {
    if (start == end)
        return st[node] = pil(arr[start], arr[start]);
    int mid = (start + end) / 2;
    pil left = make_st(node * 2, start, mid);
    pil right = make_st(node * 2 + 1, mid + 1, end);
    st[node] = pil(min(left.first, right.first), max(left.second, right.second));
    
    return st[node];
}

void update(ll node, int start, int end, int index, ll ne, int n) {
    if (index < start || index > end) return;
    if (start == end) st[node] = pil(ne, ne);

    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, ne, n);
        update(node * 2 + 1, mid + 1, end, index, ne, n);
        st[node] = pil(min(st[node * 2].first, st[node * 2 + 1].first), 
            max(st[node * 2].second, st[node * 2 + 1].second));
    }
}

pil get(ll node, int start, int end, int left, int right) {
    if (left > end || right < start) return pil(1000000001, 0);// todo
    if (left <= start && end <= right) return st[node];

    int mid = (start + end) / 2;

    pil l = get(node * 2, start, mid, left, right);
    pil r = get(node * 2 + 1, mid + 1, end, left, right);
    return pil(min(l.first, r.first), max(l.second, r.second));

}

void solve() {
    int n, m;
    ll a, b, c;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    st.resize(1 << ((int)ceil(log2(n))+1));
    make_st(1LL, 0, n-1);

    for (int i = 0; i < m; i++) {
        cin >> b >> c;
        pil res = get(1LL, 0, n - 1, b - 1, c - 1);
        cout << res.first << " " << res.second << "\n";
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