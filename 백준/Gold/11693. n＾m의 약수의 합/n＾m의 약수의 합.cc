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

ll inv(ll a, ll mod = MOD) {
    return power(a, mod - 2, mod) % mod;
}

void solve(int CASE = -1) {
    ll n, m;
    cin >> n >> m;

    if (n == 1) {
        cout << 1;
        return;
    }
    ll res = 1;
    for (ll i = 2; i*i <= n; i++) {
        
        if (n % i == 0) {
            ll x = 0;
            while (n % i == 0) n /= i, x++;
            res = (res * ((power(i, x * m + 1) - 1 + MOD) % MOD)) % MOD;
            res = (res * ((inv(i - 1)) % MOD)) % MOD;
        }
    }

    if (n >= 2) {
        res = (res * ((power(n, m + 1) - 1 + MOD) % MOD)) % MOD;
        //cout << inv(n) - 1 << "\n";
        res = (res * ((inv(n - 1)) % MOD)) % MOD;
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