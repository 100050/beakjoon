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

vector<int> a, b;
vector<ll> ft;

void update(int i, ll val) {
    while (i < ft.size()) {
        ft[i] = ft[i] + val;
        i = i + (i & -i);
    }
}

void make_ft(int n) {
    for (int i = 1; i <= n; i++) {
        update(i, b[i]);
    }
}

ll sum(int i) {
    ll res = 0;
    while (i > 0) {
        res += ft[i];
        i -= (i & -i);
    }
    return res;
}

void solve() {
    int n, m;
    int q, i, j, k, x;

    cin >> n;
    a.resize(n + 1, 0);
    b.resize(n + 1, 0);
    ft.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }

    make_ft(n);

    cin >> m;
    while (m--) {
        cin >> q;
        if (q == 1) {
            cin >> i >> j >> k;
            update(i, k);
            if (j != n)
                update(j + 1, -k);
        }
        else {
            cin >> x;
            cout << sum(x) << "\n";
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