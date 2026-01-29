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

void solve(int CASE = -1) {
    int n, m, k;
    vector<pil> sign, a, b;
    cin >> n >> m >> k;
    a.resize(n);
    b.resize(m);
    sign.resize(k);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i].first >> b[i].second;
    }
    for (int i = 0; i < k; i++) {
        cin >> sign[i].first >> sign[i].second;
    }

    int c = 0;
    for (int i = 0; i < k; i++) {
        int idx = upper_bound(a.begin()+1, a.end(), sign[i], [&](const pil& x, const pil& y) {
            int res = ccw(a[0], x, y);
            auto dist = [](const pil& a, const pil& b) {
                return (a.first - b.first) * (a.first - b.first)
                    + (a.second - b.second) * (a.second - b.second);
                };
            // 일직선이라면 거리를 기준으로 정렬
            if (res == 0) return dist(a[0], x) < dist(a[0], y);
            else          return res > 0;
            }) - a.begin() - 1;


        int idx2 = (idx + 1) % n;
        if (ccw(a[idx], sign[i], a[idx2]) > 0 || ccw(a[0], a[1], sign[i]) < 0 || ccw(a[n - 1], a[0], sign[i]) < 0) {
            //cout << idx << " " << idx2 << " " << i << "\n";
            c++;
            continue;
        }

        idx = upper_bound(b.begin()+1, b.end(), sign[i], [&](const pil& x, const pil& y) {
            int res = ccw(b[0], x, y);
            auto dist = [](const pil& a, const pil& b) {
                return (a.first - b.first) * (a.first - b.first)
                    + (a.second - b.second) * (a.second - b.second);
                };
            // 일직선이라면 거리를 기준으로 정렬
            if (res == 0) return dist(b[0], x) < dist(b[0], y);
            else          return res > 0;
            }) - b.begin() - 1;

        idx2 = (idx + 1) % m;

        if (ccw(b[0], b[1], sign[i]) < 0 || ccw(b[m - 1], b[0], sign[i]) < 0) continue;

        if (ccw(b[idx], sign[i], b[idx2]) < 0) {
            //cout << 2  << " " << idx << " " << idx2 << " " << i << " " << ccw(b[idx], sign[i], b[idx2]) << "\n";
            c++;
        }
    }

    if (c == 0) {
        cout << "YES";
    }
    else {
        cout << c;
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