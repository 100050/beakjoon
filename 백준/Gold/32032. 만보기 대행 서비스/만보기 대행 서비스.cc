#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

const ll MOD = 1000000007;
const ld PI = acos(-1.0L);


void solve() {
    ll n, d, k, mns, pls;

    cin >> n >> d;

    mns = 0, pls = 0;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (k < 0) {
            mns = max(mns, -k);
        }
        else if (k > 0) {
            pls = max(pls, k);
        }
    }

    ll res = pls * 2 + mns * 2 + 2 * d;
    if (2 * pls + 2 * mns >= d) {
        res = min(res, pls * 4 + mns * 4);
    }
    else {
        res = min(res, pls * 2 + mns * 2 + d);
    }
    res = min(res, pls * 4 + mns * 2 + d);
    res = min(res, pls * 2 + mns * 4 + d);

    cout << res;
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