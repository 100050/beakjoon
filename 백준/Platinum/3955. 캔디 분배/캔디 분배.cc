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
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

pil eea(ll r1, ll r2, ll u1, ll u2, ll v1, ll v2) {
    if (r2 == 0) return pil(r1, v1);

    ll q = r1 / r2;
    ll r = r1 % r2;
    ll u = u1 - q * u2;
    ll v = v1 - q * v2;

    return eea(r2, r, u2, u, v2, v);
}

void solve(int CASE = -1) {
    ll k, c;

    cin >> k >> c;

    if (c == 1) {
        if (k + 1 <= 1e9) cout << k + 1 << "\n";
        else cout << "IMPOSSIBLE\n";
        return;
    }
    if (k == 1) {
        cout << 1 << "\n";
        return;
    }
    //if (k < c) swap(c, k);
    pil res = eea(-k, c, 1, 0, 0, 1);
    //cout << res.first << ' ';
    if (res.second > 1e9) {
        cout << "IMPOSSIBLE\n";
    }
    else if (res.first == 1) cout << res.second << "\n";
    else if (res.first == -1) cout << -res.second + k << "\n";
    else cout << "IMPOSSIBLE\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}