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

int n;
vector<pid> p, v;

ld f(ld t) {
    pid mx{ p[0].first + v[0].first * t, p[0].second + v[0].second * t }, mn{ p[0].first + v[0].first * t, p[0].second + v[0].second * t };
    for (int i = 1; i < n; i++) {
        mx.first = max(mx.first, p[i].first + v[i].first * t);
        mx.second = max(mx.second, p[i].second + v[i].second * t);
        mn.first = min(mn.first, p[i].first + v[i].first * t);
        mn.second = min(mn.second, p[i].second + v[i].second * t);
    }

    ld l{ max((mx.first - mn.first), (mx.second - mn.second)) };
    
    return l;
}

void solve(int CASE = -1) {

    cin >> n;
    p.resize(n); v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second >> v[i].first >> v[i].second;
    }

    ld hi = 2000.L, lo = 0.L;
    for (int i = 0; i < 1000; i++) {
        ld p = (hi + lo * 2.L) / 3.L, q = (hi * 2.L + lo) / 3.L;

        if (f(p) >= f(q)) {
            lo = p;
        }
        else {
            hi = q;
        }
    }
    
    cout.precision(11);
    cout << fixed;
    cout << f(lo);
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