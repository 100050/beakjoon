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

using ll = unsigned long long;
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

bool prime[100000001];

void solve(int CASE = -1) {
    ll n;
    ll res = 1;

    cin >> n;

    map<ll, ll> m;
    // 에라토스테네스의 체
    for (ll i = 2; i <= n; i++) {
        if (prime[i] != 0) continue;
        
        // 여기서 바로 처리
        // num <= n, k <= n
        ll k = i, e = 1;
        for (;; k *= i, e++) {
            if (k > n / i) {
                break;
            }
        }

        res *= k;
        res %= (ll)1 << 32;

        if (i * i > n) continue;
        for (ll j = i * i; j <= n; j += i) {
            prime[j] = 1;
        }
    }


    //auto modpow = [](ll a, ll e, ll mod) {
    //    ll res = 1;
    //    while (e) {
    //        if (e & 1) res = (a * res) % mod;
    //        a = (a * a) % mod;
    //        e >>= 1;
    //    }

    //    return res % mod;
    //    };

    //for (pair<const ll, ll>& pp : m) {
    //    res *= modpow(pp.first, pp.second, (ll)1 << 32);
    //    //cout << res << " " << pp.first << " " << pp.second << "\n";
    //    res %= (ll)1 << 32;
    //}

    cout << res << "\n";
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