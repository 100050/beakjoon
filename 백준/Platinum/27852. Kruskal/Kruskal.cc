#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
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

ll find_p(ll t) {
    if (t != 2 && t % 2 == 0) t--;

    for (ll p = t; p > 2; p -= 2) {
        ll i = 3;
        for (; i * i <= p; i += 2) {
            if (p % i == 0) break;
        }
        if (i * i > p) return p;
    }

    return 2;
}

void solve(int CASE = -1) {
    int n, k, c = 0;
    ll res = 0;
    bool flag = false;

    cin >> n >> k;
    if (n == 1) {
        //cout << n << "\n";
        ll t;
        cin >> t;
        ll p = find_p(t - 1);
        if (t - p <= k) {
            cout << "YES\n";
            return;
        }
        else if ((t - p) % (k + 1) == 0) {
            cout << "NO\n";
            return;
        }
        else {
            cout << "YES\n";
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        ll p = find_p(t);
        if (t == p && n >= 2) {
            flag = true;
        }
        if (t - p <= k) {
            flag = true;
        }
        //cout << p << " " << t - p << "\n";
        res ^= ((t - p) % (k + 1));
    }

    if (flag) {
        cout << "YES\n";
    }
    else {
        cout << (res == 0 ? "NO" : "YES") << "\n";
    }
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