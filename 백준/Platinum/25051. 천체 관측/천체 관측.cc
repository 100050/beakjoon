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

int ccw(const pil& a, const pil& b, const pil& c) {
    ll op = a.first * b.second + b.first * c.second + c.first * a.second;
    op -= (a.second * b.first + b.second * c.first + c.second * a.first);

    if (op > 0) return 1;
    else if (op == 0)return 0;
    else return -1;
}

ll dist_sq(const pil& a, const pil& b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

ll dot_product(const pil& a, const pil& b, const pil& c) {
    pil aa(a.first - b.first, a.second - b.second), cc(c.first - b.first, c.second - b.second);

    return aa.first * cc.first + aa.second * cc.second;
}

void solve(int CASE = -1) {
    int n, m;
    using type = pair<pil, ll>;
    vector<type> s;
    vector<ll> p;

    cin >> n >> m;
    s.resize(n); p.resize(m);
    for (int i = 0; i < n; i++) {
        cin >> s[i].first.first >> s[i].first.second >> s[i].second;
    }
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }

    sort(s.begin(), s.end(), [&](const type& a, const type& b) {
        pil z(0, 0);
        if ((a.first > z) ^ (b.first > z)) return a > b;
        int res = ccw(z, a.first, b.first);

        if (res == 0) {
            return dist_sq(z, a.first) < dist_sq(z, b.first);
        }
        else return res > 0;
        });

    ll res = INF<ll>+1;
    for (int i = 0; i < m; i++) {
        int begin = 0, end = 0;
        ll ss = 0;
        while (begin != n) {
            int count = 0;
            //cout << i << " " << s[begin].first.first << " " << s[begin].first.second << " " << end << "\n";
            while (dot_product(s[begin].first, pil(0, 0), s[end].first) >= 0 && ccw(pil(0, 0), s[begin].first, s[end].first) >= 0) {
                //cout << angle(s[begin].first, pil(0, 0), s[end].first) / PI * 180 << " " << end << "\n";
                if (dist_sq(pil(0LL, 0LL), s[end].first) <= p[i]) {
                    ss += s[end].second;
                }
                end = (end + 1) % n;
                count++;
                if (end == begin) {
                    break;
                }
            }
            res = max(res, ss - p[i]);
            if (count == n) break;
            if (dist_sq(pil(0LL, 0LL), s[begin].first) <= p[i]) {
                ss -= s[begin].second;
            }
            begin++;
        }
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