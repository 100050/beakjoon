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
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

void solve(int CASE = -1) {
    ll a, b, c;
    ll x1, x2, y1, y2;

    cin >> a >> b >> c;
    cin >> x1 >> x2 >> y1 >> y2;
    if (c < 0) {
        a = -a; b = -b; c = -c;
    }
    auto f = [&](const ll& x, const ll& y) {
        ll res = a * x + b * y + c;
        if (res == 0) return 0;
        else if (res < 0) return -1;
        else return 1;
        };
    bool res = false;
    if (a * b < 0) {
        if (f(x1, y2) * f(x2, y1) < 0) {
            res = true;
        }
    }
    else if (a * b >= 0) {
        if (f(x1, y1) * f(x2, y2) < 0) {
            res = true;
        }
    }

    cout << (res ? "Poor" : "Lucky");
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