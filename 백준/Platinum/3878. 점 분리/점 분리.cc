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

vector<pil> graham(vector<pil> arr) {
    stack<int> s;
    // sort(arr.begin(), arr.end()); // O(nlog(n))
    swap(arr[0], *min_element(arr.begin(), arr.end())); // O(n)

    // 각도를 기준으로 정렬
    sort(arr.begin() + 1, arr.end(), [&](const pil& a, const pil& b) {
        if (int res = ccw(arr[0], a, b)) return res > 0;
        else return dist_sq(arr[0], a) < dist_sq(arr[0], b);
        });

    s.push(0); s.push(1);
    for (int i = 2; i < arr.size(); i++) {
        while (s.size() >= 2) {
            const int pre = s.top(); s.pop();
            const int ppre = s.top();
            if (ccw(arr[ppre], arr[pre], arr[i]) > 0) {
                s.push(pre);
                break;
            }
        }
        s.push(i);
    }
    vector<pil> ret(s.size());

    int n = s.size();
    for (int i = 0; i < n; i++) {
        int top = s.top(); s.pop();

        ret[n - i - 1] = arr[top];
    }

    return ret;
}

bool is_inside(const vector<pil>& poly, pil p) {
    int n = poly.size();

    // check two end sides
    ll c1 = ccw(poly[0], poly[n - 1], p);
    if (c1 > 0) return false;
    if (c1 == 0) {
        if (p > max(poly[0], poly[n - 1]) || p < min(poly[0], poly[n - 1])) return false;
    }

    ll c2 = ccw(poly[0], poly[1], p);
    if (c2 < 0) return false;
    if (c2 == 0) {
        if (p > max(poly[0], poly[1]) || p < min(poly[0], poly[1])) return false;
    }

    int left = 0, right = n - 1;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (ccw(poly[0], poly[mid], p) > 0) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    return ccw(poly[left], poly[right], p) >= 0;
}

bool isIntersect(pair<pil, pil> l1, pair<pil, pil> l2) {

    pil p1 = l1.first;
    pil p2 = l1.second;
    pil p3 = l2.first;
    pil p4 = l2.second;

    ll p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4); // l1 기준
    ll p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2); // l2 기준

    // 두 직선이 일직선 상에 존재
    if (p1p2 == 0 && p3p4 == 0) {
        // 비교를 일반화하기 위한 점 위치 변경
        if (p1 > p2) swap(p2, p1);
        if (p3 > p4) swap(p3, p4);

        return p3 <= p2 && p1 <= p4; // 두 선분이 포개어져 있는지 확인
    }

    return p1p2 <= 0 && p3p4 <= 0;

}


void solve(int CASE = -1) {
    int n, m;
    vector<pil> black, white;

    cin >> n >> m;
    black.resize(n);
    white.resize(m);
    for (int i = 0; i < n; i++) {
        cin >> black[i].first >> black[i].second;
    }
    for (int i = 0; i < m; i++) {
        cin >> white[i].first >> white[i].second;
    }

    if (n == 1 && m == 1) {
        cout << "YES\n";
        return;
    }

    vector<pil> cb, cw;
    // convex hull
    if (n != 1) {
        cb = graham(black);
    }
    else {
        cb = black;
    }
    n = cb.size();

    if (m != 1) {
        cw = graham(white);
    }
    else {
        cw = white;
    }
    m = cw.size();

    // 점이 1개인 경우 할 것이 없다.
    // 2개의 점만 나온 경우 선분에 대하여 다른 컨벡스 헐과의 선분교차 확인
    // - 다른 점이 하나면 2개의 점 사이에 존재하는지 확인
    // 점이 3개 이상인 경우 점 내부 판별
    bool res = true;
    if (n == 2) {
        if (m == 1) {
            if (cb[0] <= cw[0] && cw[0] <= cb[1]) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
            return;
        }
        else {
            for (int i = 0; i < m; i++) {
                if (isIntersect(make_pair(cb[0], cb[1]), make_pair(cw[i], cw[(i + 1)%m]))) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    else if (n >= 3) {
        for (int i = 0; i < m; i++) {
            if (is_inside(cb, cw[i])) {
                cout << "NO\n";
                return;
            }
        }
    }

    if (m == 2) {
        if (n == 1) {
            if (cw[0] <= cb[0] && cb[0] <= cw[1]) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
            return;
        }
        else {
            for (int i = 0; i < n; i++) {
                if (isIntersect(make_pair(cw[0], cw[1]), make_pair(cb[i], cb[(i + 1) % n]))) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    else if (m >= 3) {
        for (int i = 0; i < n; i++) {
            if (is_inside(cw, cb[i])) {
                cout << "NO\n";
                return;
            }
        }
    }


    cout << "YES\n";
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