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


bool nprime[31624];

ll power(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (a * res) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }

    return res % mod;
}

bool is_prime(ll m) {
    for (ll i = 2; i * i <= m; i++) {
        if (nprime[i]) continue;

        if (m % i == 0) return false;
    }

    return true;
}

void solve(int CASE = -1) {
    ll p, a;
    
    for (ll i = 2; i <= 31623; i++) {
        if (nprime[i]) continue;

        if (i * i > 31623) continue;
        for (ll j = i * i; j <= 31623; j += i) {
            nprime[j] = true;
        }
    }
    while (true) {
        cin >> p >> a;
        if (p == 0) break;

        // a^p = a mod p인데 p가 소수가 아니라면 가짜소수이면 yes
        // !is_prime(p) && a^p % p == a
        if (power(a, p, p) % p == a && !is_prime(p)) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }

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