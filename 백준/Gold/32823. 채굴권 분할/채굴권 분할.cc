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

const ll MOD = 1000000007;
//const ll MOD = 10007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

struct Point {
    ld x, y;
};
struct Line {
    Point a, b;
};
// CCW 결과: 1(반시계), -1(시계), 0(일직선)
int ccw(const Point& a, const Point& b, const Point& c) {
    ld cross = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return (cross > 0) - (cross < 0);
}
// 두 선분 (a,b)와 (c,d)가 교차하는지 여부
bool isIntersect(Point& a, Point& b, Point& c, Point& d) {
    ld ab = ccw(a, b, c) * ccw(a, b, d);
    ld cd = ccw(c, d, a) * ccw(c, d, b);
    return ab <= 0 && cd <= 0;
}

void trans(Point& p, ld theta, ld r) {

    p.x = r * cos(theta);
    p.y = r * sin(theta);
}

void solve(int CASE = -1) {
    int n;
    vector<Line> lines;

    cin >> n;
    lines.resize(n);
    for (int i = 0; i < n; i++) {
        ld s, e;
        cin >> s >> e;
        // 2개의 점이 주어질 때
        Point a, b;
        trans(a, s / 10 * PI / 180, 1000);
        trans(b, e / 10 * PI / 180, 1000);

        lines[i].a = a;
        lines[i].b = b;
        //cout << a.x << " " << a.y << " " << b.x << " " << b.y << "\n";
    }

    Point a;
    Line l1, l2;
    ld r, theta;
    
    // p, q 값 받고 직교 좌표계로 변환
    cin >> theta >> r;
    trans(a, theta / 10 * PI / 180, r);
    l1.a = { 0, 0 };
    l1.b = a;
    cin >> theta >> r;
    trans(a, theta / 10 * PI / 180, r);
    l2.a = { 0, 0 };
    l2.b = a;

    // 교차 판정 (짝수 개만큼 교차 시 둘 다 얻을 수 있음)
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (isIntersect(l1.a, l1.b, lines[i].a, lines[i].b)) {
            s++;
        }
        if (isIntersect(l2.a, l2.b, lines[i].a, lines[i].b)) {
            s++;
        }
    }

    cout << (s % 2 == 0 ? "YES" : "NO");
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