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

ll power(ll a, ll b, bool& flag, ll mod = MOD) {
    ll res = 1;
    bool flag2 = false;
    while (b) {
        if (b & 1) {
            if (flag2 || a * res >= mod) {
                flag = true;
            }
            res = (a * res) % mod;
        }
        if (a * a >= mod) {
            flag2 = true;
        }
        a = (a * a) % mod;
        b >>= 1;
    }

    return res % mod;
}

ll phi(ll n) {
    ll result = n;

    for (ll p = 2; p * p <= n; p++)
    {
        if (n % p == 0) {
            result -= result / p;
            while (n % p == 0)
                n /= p;
        }
    }

    if (n > 1)
        result -= result / n;

    return result;
}

ll f(ll d, ll n, vector<ll>& x, ll mod) {
    if (d == n) return 1LL;
    ll e = f(d + 1, n, x, phi(mod));
    //cout << "f(" << x << ") = " <<  b << " " << e << " " << power(b, e, mod) << " " << mod << "\n";
    bool flag = false;
    ll ret = power(x[d], e, flag, mod);
    if (flag) ret += mod;
    return ret;
}

void solve(int CASE = -1) {
    ll t, m;

    cin >> t >> m;
    while (t--) {
        ll n;
        vector<ll> x;

        cin >> n;
        x.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        ll res = f(0, n, x, m) % m;
        
        cout << res << "\n";
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