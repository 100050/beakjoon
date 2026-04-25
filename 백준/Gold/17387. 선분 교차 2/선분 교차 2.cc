#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

#define x first
#define y second

class Line {
public:
    pil p, q;

    Line() = default;
    Line(pil p, pil q) : p(p), q(q) {}
    Line(long long p1, long long p2, long long q1, long long q2) : p(p1, p2), q(q1, q2) {}
};

int ccw(pil p1, pil p2, pil p3) {
    long long s = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    s -= (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
    //cout << s << "\n";
    if (s > 0) return 1;
    else if (s == 0) return 0;
    else return -1;
}

void solve() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    Line l1 = Line(a, b, c, d);
    cin >> a >> b >> c >> d;
    Line l2 = Line(a, b, c, d);

    if (ccw(l1.p, l2.p, l1.q) * ccw(l1.p, l2.q, l1.q) == 0 &&
        ccw(l2.p, l1.p, l2.q) * ccw(l2.p, l1.q, l2.q) == 0) {
        if (l1.p > l1.q) swap(l1.p, l1.q);
        if (l2.p > l2.q) swap(l2.p, l2.q);

        cout << (l2.p <= l1.q && l1.p <= l2.q);
        return ;
    }
    if (ccw(l1.p, l2.p, l1.q) * ccw(l1.p, l2.q, l1.q) <= 0 &&
        ccw(l2.p, l1.p, l2.q) * ccw(l2.p, l1.q, l2.q) <= 0) {
        cout << 1;
    }
    else {
        cout << 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}