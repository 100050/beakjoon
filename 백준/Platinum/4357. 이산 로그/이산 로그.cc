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
        if (b & 1) {
            res = (a * res) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }

    return res % mod;
}

ll inv(ll a, ll mod = MOD) {
    return power(a, mod - 2, mod) % mod;
}

void solve(int CASE = -1) {
    ll p, b, n;
    ll m;

    while (cin >> p) {
        map<ll, ll> s;
        cin >> b >> n;

        m = sqrt(p - 1);

        for (int i = 0; i < m; i++) {
            s[power(b, i, p)] = i;
        }

        ll res = -1;
        for (int i = 0; i <= (p - 1) / m; i++) {
            auto it = s.find(n * inv(power(b, i * m, p), p) % p);
            if (it != s.end()) {
                res = i * m + it->second;
                break;
            }
        }

        if (res == -1) cout << "no solution\n";
        else cout << res << "\n";
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