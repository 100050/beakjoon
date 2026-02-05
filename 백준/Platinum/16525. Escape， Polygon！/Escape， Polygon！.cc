#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <numeric>
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
    ll n;
    vector<pil> convex;

    cin >> n;
    convex.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> convex[i].first >> convex[i].second;
    }


    ll r = 1; // r은 oo+와 시계 방향을 이루는 최초의 선의 시작점으로 초기화
    ll res = n*(n-1)*(n-2)/6;
    for (ll l = 0; l < n; l++) {
        //cout << l << " : " << r << " : " << ccw(convex[l], convex[(l + 1) % convex.size()], convex[r % n], convex[(r + 1) % convex.size()]) << "\n";
        while (((r + 1) % n != l) && (ccw(convex[l], convex[(l + 1) % convex.size()], convex[r % n], convex[(r + 1) % convex.size()]) >= 0)) {
            r = r + 1;
        }
        //cout << l << " " << r << " " << res << "\n";
        if (r - l - 1 >= 2)
            res -= (r - l - 1) * (r - l - 2) / 2;
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