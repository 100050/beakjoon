#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

struct Line {
    pid s;
    pid e;
    ll w;

    Line() = default;
    Line(ld x1, ld y1, ld x2, ld y2, ll ww) 
        : s(pid(x1, y1)), e(pid(x2, y2)), w(ww) {}
};

int ccw(pid p1, pid p2, pid p3) {
    ld s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

    if (s > 0) return 1;
    else if (s == 0) return 0;
    else return -1;
}

bool intersect(const Line a, const Line b) {
    pid p1 = a.s;
    pid p2 = a.e;
    pid p3 = b.s;
    pid p4 = b.e;

    int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4); // l1 기준
    int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2); // l2 기준

    // 두 직선이 일직선 상에 존재
    if (p1p2 == 0 && p3p4 == 0) {
        // 비교를 일반화하기 위한 점 위치 변경
        if (p1 > p2) swap(p2, p1);
        if (p3 > p4) swap(p3, p4);

        return p3 <= p2 && p1 <= p4; // 두 선분이 포개어져 있는지 확인
    }

    return p1p2 <= 0 && p3p4 <= 0;
}

bool compare(const Line& a, const Line& b) {
    return a.w <= b.w;
}

void solve() {
    int n;
    ll s = 0;
    vector<Line> lines;

    cin >> n;
    for (int i = 0; i < n; i++) {
        ld x1, y1, x2, y2;
        ll w;
        cin >> x1 >> y1 >> x2 >> y2 >> w;

        lines.push_back(Line(x1, y1, x2, y2, w));
        s += w;
    }

    //sort(lines.begin(), lines.end(), compare);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (intersect(lines[i], lines[j])) {
                s += min(lines[i].w, lines[j].w);
            }
        }
    }

    cout << s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}