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

tuple<ll, ll, ll> egcd(ll a, ll b) {
    if (b == 0)
        return make_tuple(a, 1, 0);
    auto&& [g, x1, y1] = egcd(b, a % b);
    return make_tuple(g, y1, x1 - (a / b) * y1);
}

void solve(int CASE = -1) {
    ll n, m, x, y;
    
    cin >> m >> n >> x >> y;

    if (n == m) {
        if (x != y) cout << -1 << "\n";
        else cout << x << "\n";

        return;
    }
    x--;
    y--;
    
    ll k = (y - x + 40000*n) % n;
    auto&& [g, inv_m, _] = egcd(m, n);
    if (k % g != 0) {
        cout << -1 << "\n";
        return;
    }
    while (inv_m < 0)
        inv_m = inv_m + n;
    k = (k / g * inv_m) % (n / g);

    ll r = x + m * k + 1;
    cout << r << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}