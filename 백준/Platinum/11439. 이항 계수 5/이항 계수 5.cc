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

void solve(int CASE = -1) {
    ll n, k, m;

    cin >> n >> k >> m;

    vector<ll> sieve(n + 1);
    vector<ll> factors(n + 1);

    for (ll i = 2; i * i <= n; i++) {
        if (sieve[i] != 0) continue;

        for (ll j = i * i; j <= n; j += i)
            sieve[j] = i;
    }

    // n!/((n-k)!k!)에서 n!을 소인수 분해, (n-k)!을 소인수 분해, k! 소인수 분해
    for (ll p = 2; p <= n; p++) {
        if (sieve[p] != 0) continue;
        ll e = 0;
        for (ll x = p; x <= n; x *= p) {
            e += n / x;
        }

        factors[p] = e;
    }

    for (ll p = 2; p <= n - k; p++) {
        if (sieve[p] != 0) continue;
        ll e = 0;
        for (ll x = p; x <= n - k; x *= p) {
            e += (n - k) / x;
        }

        factors[p] -= e;
    }

    for (ll p = 2; p <= k; p++) {
        if (sieve[p] != 0) continue;
        ll e = 0;
        for (ll x = p; x <= k; x *= p) {
            e += k / x;
        }

        factors[p] -= e;
    }

    // 소인수들을 곱하고 M으로 나눔
    ll res = 1;
    for (ll i = 2; i <= n; i++) {
        if (factors[i] != 0) {
            //cout << i << " " << factors[i] << "\n";
            res *= power(i, factors[i], m);
            res %= m;
        }
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