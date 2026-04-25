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

void solve(int CASE = -1) {
    ll m, seed, x1, x2, a, c;

    cin >> m >> seed >> x1 >> x2;

    a = (inv(x1 - seed, m) * ((x2 - x1) % m)) % m;
    c = (x1 - (a * seed) % m) % m;

    if (a < 0) a += m;
    if (c < 0) c += m;

    cout << a << " " << c;
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