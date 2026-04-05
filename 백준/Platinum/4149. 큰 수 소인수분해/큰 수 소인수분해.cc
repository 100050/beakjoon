#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <unordered_set>
#include <queue>
#include <stack>
#include <ranges>
#include <numeric>
#include <cstring>
#include <bit>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

constexpr ll MOD = 1000000007;
//constexpr ll MOD = 10007;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

ll mul(ll a, ll b, ll mod = MOD) {
    ll res = 0;
    while (b) {
        if (b & 1) res = (a + res) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }

    return res % mod;
}

ll power(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = mul(a, res, mod);
        a = mul(a, a, mod);
        b >>= 1;
    }

    return res % mod;
}

bool millerRabin(const ll& n, ll& p) {
    ll s = 0, d = n - 1;

    while (d % 2 == 0) s++, d /= 2;

    ll x = power(p, d, n);
    if (x == 1 || x + 1 == n) return true;

    for (ll i = 0; i < s - 1; i++) {
        x = power(x, 2, n);
        if (x + 1 == n) return true;
    }

    return false;
}

bool isPrime(const ll& n) {
    array<ll, 13> base = { 2,3,5,7,11,13,17,19,23,29,31,37,41 };

    for (ll& p : base) if (p == n) return true;
    if (n == 1 || n % 2 == 0) return  true;

    for (ll& p : base)
        if (!millerRabin(n, p)) return false;

    return true;
}

void pollardRho(ll n, vector<ll>& ret) {
    if (n == 1) return;
    if (n % 2 == 0) {
        ret.push_back(2);
        pollardRho(n / 2, ret);
        return;
    }

    if (isPrime(n)) {
        ret.push_back(n);
        return;
    }

    ll a, b, c, g = n;
    auto f = [&](ll x) {
        return (c + mul(x, x, n)) % n;
        };

    do {
        if (g == n) {
            a = b = rand() % (n - 2) + 2;
            c = rand() % 20 + 1;
        }
        a = f(a);
        b = f(f(b));
        g = gcd(abs(a - b), n);
    } while (g == 1);

    pollardRho(g, ret);
    pollardRho(n / g, ret);
}

vector<ll> factorize(ll n) {
    vector<ll> ret;

    pollardRho(n, ret);
    sort(ret.begin(), ret.end());
    
    return ret;
}

void solve(int CASE = -1) {
    ll n;

    cin >> n;

    for (ll& x : factorize(n)) {
        cout << x << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    //pre();
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}