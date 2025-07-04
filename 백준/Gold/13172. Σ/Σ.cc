#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

const ll mod = 1000000007;

void solve() {
    int m;
    ll n, s;
    ll pn, ps;
    ll res;

    auto power = [&](ll a, ll b) {
        ll ret = 1;
        while (b) {
            if (b & 1) ret = ret * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return ret;
        };

    auto inv = [&](ll n) {
        return power(n, mod - 2);
        };

    auto gcd = [&](ll a, ll b) {
        ll r;
        while (b) {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
        };

    cin >> m;

    res = 1;
    cin >> pn >> ps;
    for (int i = 1; i < m; i++) {
        cin >> n >> s;

        ll g = gcd(n, pn);

        ps = ps * (n / g) % mod;
        s = s * (pn / g) % mod;
        pn = pn * (n / g) % mod;
        
        ps = ps + s % mod;
    }

    res = inv(pn) * ps % mod;

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