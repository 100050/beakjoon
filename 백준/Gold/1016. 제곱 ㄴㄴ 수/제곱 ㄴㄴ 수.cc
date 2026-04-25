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

int prime[1000002];
bool nono[1000001];

void solve(int CASE = -1) {
    ll mn, mx;

    cin >> mn >> mx;

    // 에라토스테네스의 체
    for (ll i = 2; i <= 1000001; i++) {
        if (prime[i] != 0) continue;
        
        ll p = i * i;
        for (ll x = (mn / p) * p; x <= mx; x += i * i) {
            if (mn <= x) nono[x-mn] = 1;
        }

        if (i * i > 1000001) continue;
        for (ll j = i * i; j <= 1000001; j += i) {
            prime[j] = i;
        }
    }

    int res = mx-mn + 1;
    for (ll i = 0; i <= mx-mn + 1; i++) {
        res -= nono[i];
    }

    cout << res;
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