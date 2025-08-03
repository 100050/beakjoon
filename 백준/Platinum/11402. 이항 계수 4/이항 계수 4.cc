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
#include <cstring>
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

ll dp[2001][2001];

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

ll comb(ll n, ll r, ll mod) {
    if (n < r) return 0LL;

    ll& ret = dp[n][r];

    if (dp[n][r] != -1) return ret;

    if (r == 1) return n;
    if (r == 0) return 1;

    return ret = (comb(n - 1, r, mod) + comb(n - 1, r - 1, mod)) % mod;

}

ll c(ll n, ll m, ll mod) {
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
        
        res = res * comb(n, r, mod);
        res %= mod;
    }

    return res;
}

void solve(int CASE = -1) {
    ll n, k, res, m;
    
    memset(dp, -1, sizeof(dp));

    cin >> n >> k >> m;

    res = c(n, k, m);

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