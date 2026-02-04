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

void solve(int CASE = -1) {
    int n;
    vector<pil> p;

    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    if (n == 2) {
        cout << p[0].first << " " << p[0].second << " " << p[1].first << " " << p[1].second;
        return;
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
            int pre = s.top(); s.pop();
            int ppre = s.top();
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
        cout << p[0].first << " " << p[0].second << " " << p[n - 1].first << " " << p[n - 1].second << "\n";
        return;
    }

    while (s.size()) {
        convex.push_back(p[s.top()]);
        s.pop();
    }


    int r = 1, ans1, ans2;
    ll mx = 0;
    for (int l = 0; l < convex.size(); l++) {
        while (ccw(convex[l], convex[(l+1) % convex.size()], convex[r], convex[(r+1) % convex.size()]) < 0) {
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

    cout << convex[ans1].first << " " << convex[ans1].second << " "
        << convex[ans2].first << " " << convex[ans2].second << "\n";
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