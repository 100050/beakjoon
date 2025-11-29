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
    ll n, p, phi_p;
    vector<ll> arr;
    vector<ll> a;

    cin >> n >> p;
    phi_p = p - 1;
    arr.resize(phi_p); a.resize(n+1);
    for (int i = 0; i <= n; i++) {
        cin >> a[n-i];

        arr[(n - i) % phi_p] += a[n - i];
    }

    cout << a[0] % p << "\n";
    for (int i = 1; i < p; i++) {
        ll res = 0;
        for (int j = 0; j < phi_p; j++) {
            ll tmp = arr[j] % p;
            tmp = (tmp * power(i, j, p)) % p;
            res = (res + tmp) % p;
        }

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