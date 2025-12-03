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

ll power(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (a * res) % mod;
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

ll f(ll x, ll b, ll mod) {
    if (x == 0LL) return 1LL;
    ll e = f(x - 1, b, phi(mod));
    //cout << "f(" << x << ") = " <<  b << " " << e << " " << power(b, e, mod) << " " << mod << "\n";
    ll ret = power(b, e, mod);
    return (ret == 0 ? ret + mod : ret);
}

void solve(int CASE = -1) {
    while (true) {
        ll b, i, n;

        cin >> b;
        if (b == 0LL) break;
        cin >> i >> n;

        ll mod = 1;
        for (int j = 0; j < n; j++)
            mod *= 10;

        ll res = f(i, b, mod) % mod;
        string str = to_string(res);


        for (int j = 0; j < n - str.size(); j++) cout << "0";
        cout << str << "\n";
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