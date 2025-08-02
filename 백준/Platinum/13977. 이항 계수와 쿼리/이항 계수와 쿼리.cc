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

const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

ll fact[4000001];

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (a * res) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return res % MOD;
}

ll inv(ll a) {
    return power(a, MOD - 2) % MOD;
}

void solve(int CASE = -1) {
    int m;


    cin >> m;
    fact[0] = 1;
    for (int i = 1; i <= 4000000; i++) fact[i] = (fact[i - 1] * i) % MOD;
    while (m--) {
        ll n, k, res;

        cin >> n >> k;

        res = (fact[n] * (inv(fact[k]) * inv(fact[n - k]) % MOD)) % MOD;

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