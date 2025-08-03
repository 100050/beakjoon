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
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

// 
const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

ll fact1[98];
ll fact2[1032];

ll power(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (a * res) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }

    return res % mod;
}

ll inv(ll a, ll mod) {
    return power(a, mod - 2, mod) % mod;
}

vector<ll> getLuca(ll val, ll mod) {
    vector<ll> ret;
    while (val > 0) {
        ll remainder = val % mod;
        ret.push_back(remainder);
        val /= mod;

    }
    return ret;
}

ll comb(ll n, ll r, ll mod, ll fact[]) {
    if (n < r) return 0LL;
    return (fact[n] * (inv(fact[r], mod) * inv(fact[n - r], mod) % mod)) % mod;
}

ll c(ll n, ll m, ll mod, ll fact[]) {
    // 뤼카의 정리
    vector<ll> lucaN = getLuca(n, mod);
    vector<ll> lucaM = getLuca(m, mod);
    ll res = 1;

    int minIdx = min(lucaN.size(), lucaM.size());
    //cout << minIdx << "\n";
    for (int i = 0; i < minIdx; ++i) {
        ll n = lucaN[i];
        ll r = lucaM[i];

        //cout << mod << " " << n << " " << r << "\n";

        res = res * comb(n, r, mod, fact);
        res %= mod;
    }

    return res;
}

void solve(int CASE = -1) {
    fact1[0] = 1; fact2[0] = 1;
    for (int i = 1; i <= 97; i++) fact1[i] = (fact1[i - 1] * i) % 97;
    for (int i = 1; i <= 1031; i++) fact2[i] = (fact2[i - 1] * i) % 1031;
    int m;
    ll n, k, res;

    cin >> m;
    while (m--) {
        cin >> n >> k;

        if (k - 1 == 0) {
            if (n == 0) cout << 1 << "\n";
            else cout << 0 << "\n";
            continue;
        }

        if (n == 0) {
            cout << 0 << "\n";
            continue;
        }

        if (n >= k - 1) {
            n = n - 1;
            k = k - 2;

            // 중국인의 나머지 정리
            ll res1, res2, x1, x2;

            res1 = c(n, k, 97, fact1);
            res2 = c(n, k, 1031, fact2);

            x1 = (inv(1031, 97)) % 97;
            x2 = (inv(97, 1031)) % 1031;
            //cout << x1 << " " << res1 << " " << x2 << " " << res2 << "\n";
            res = (x1 * res1 * 1031 + x2 * res2 * 97) % (1031 * 97);
        }
        else {
            res = 0;
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