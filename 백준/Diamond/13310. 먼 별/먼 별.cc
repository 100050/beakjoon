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

ll dist_sq(const pil& a, const pil& b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int ccw(const pil& a, const pil& b, const pil& c) {
    ll res = a.first * b.second + b.first * c.second + c.first * a.second;
    res -= a.first * c.second + c.first * b.second + b.first * a.second;

    if (res == 0) return 0;
    else if (res > 0) return 1;
    else return -1;
}

int ccw(const pil& a, const pil& b, const pil& c, const pil& d) {
    return ccw(
        pil(0, 0),
        pil(b.first - a.first, b.second - a.second),
        pil(d.first - c.first, d.second - c.second)
    );
}

int n;
vector<pil> v;

ll f(const ll& t, vector<pil> p) {

    for (int i = 0; i < n; i++) {
        p[i].first += v[i].first * t;
        p[i].second += v[i].second * t;
    }

    if (n == 2) {
        return dist_sq(p[0], p[1]);
    }

    swap(p[0], *min_element(p.begin(), p.end()));
    sort(p.begin() + 1, p.end(), [&](const pil& a, const pil& b) {
        if (int res = ccw(p[0], a, b)) return res > 0;
        else return dist_sq(p[0], a) < dist_sq(p[0], b);
        });

    stack<int> s;
    s.push(0); s.push(1);

    for (int i = 2; i < n; i++) {
        while (s.size() >= 2) {
            const int pre = s.top(); s.pop();
            const int ppre = s.top();
            if (ccw(p[ppre], p[pre], p[i]) > 0) {
                s.push(pre);
                break;
            }
        }
        s.push(i);
    }

    vector<pil> convex;

    if (s.size() <= 2) {
        sort(p.begin(), p.end());
        return dist_sq(p[0], p[n-1]);
    }

    while (s.size()) {
        convex.push_back(p[s.top()]);
        s.pop();
    }


    int r = 1, ans1, ans2;
    ll mx = 0;
    for (int l = 0; l < convex.size(); l++) { // l일 때 r을 어디까지 옮길 수 있는지 확인
        while (ccw(convex[l], convex[(l + 1) % convex.size()], convex[r], convex[(r + 1) % convex.size()]) < 0) {
            if (mx < dist_sq(convex[l], convex[r])) {
                mx = dist_sq(convex[l], convex[r]);
                ans1 = l;
                ans2 = r;
            }

            r = (r + 1) % convex.size();
        }

        if (mx < dist_sq(convex[l], convex[r])) {
            mx = dist_sq(convex[l], convex[r]);
            ans1 = l;
            ans2 = r;
        }
    }

    return dist_sq(convex[ans1], convex[ans2]);
}

void solve(int CASE = -1) {
    ll t;
    vector<pil> arr;

    cin >> n >> t;
    arr.resize(n); v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second >> v[i].first >> v[i].second;
    }



    ll hi = t, lo = 0;
    while (hi - lo >= 3) {
        int p = (hi + lo * 2) / 3, q = (hi * 2 + lo) / 3;
        ll retp = f(p, arr), retq = f(q, arr);

        if (retp > retq) {
            lo = p;
        }
        else {
            hi = q;
        }
    }

    ll res = INF<ll>, day = 0;
    for (ll i = lo; i <= hi; i++) {
        ll ret = f(i, arr);
        if (res > ret) {
            res = ret;
            day = i;
        }
    }

    cout << day << "\n" << res;
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