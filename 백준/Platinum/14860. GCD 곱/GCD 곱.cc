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

ll n, m;
vector<ll> primes;
vector<pil> factors;
bool sieve[15000001];

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
    cin >> n >> m;

    if (n > m) swap(n, m);

    // 1 ~ n까지의 소수 다 구하기
    ll i;
    for (i = 2; i*i <= n; i++) {
        if (sieve[i]) continue;
        primes.push_back(i);
        for (ll j = i * i; j <= n; j += i)
            sieve[j] = true;
    }
    for (; i <= n; i++) {
        if (!sieve[i]) primes.push_back(i);
    }
    // 2^3 3^2 2^4 5^1 2^3 3^2 -> 2^10 3^4 5^1
    // 1 2 3 6
    // 2^3, 3^1
    // 1 1, 1 2, 1 3, 1 4, 2 1, 2 2, 2 3, 2 4, 3 1, 3 2, 3 3, 3 4, 4 1, 4 2, 4 3, 4 4, 5 1, 5 2, 5 3, 5 4, 6 1, 6 2, 6 3, 6 4, 8 1, 8 2, 8 3, 8 4
    // 2 2 3 2 4 2 3 2
    // 1024 * 9
    // p가지고 m을 르장드르 공식에 넣어서 값을 구함
    for (const ll& p : primes) {
        ll e = 0;
        for (ll x = p; x <= n; x *= p) {
            e += (m / x) * (n / x);
            //e %= MOD - 1;
        }
        //cout << p << " " << e << "\n";
        factors.push_back(make_pair(p, e));
    }

    // 결과값 구하기
    ll res = 1;
    for (const pil& f : factors) {
        res = (res * power(f.first, f.second)) % MOD;
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