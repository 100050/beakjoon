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

vector<Line> arr;

void solve() {
    long long a, b, c, d;
    int n;
    cin >> n;
    cin >> a >> b;
    for (int i = 1; i < n; i++) {
        cin >> c >> d;
        arr.push_back(Line(a, b, c, d));
        a = c;
        b = d;
    }
    arr.push_back(Line(a, b, arr[0].p.x, arr[0].p.y));

    for (int j = 0; j < 3; j++) {
        cin >> a >> b;
        int cnt = 0, i;
        
        pil p(a, b);
        Line l(p, pil(1000000001, b));
        for (i = 0; i < arr.size(); i++) {
            Line l1 = l, l2 = arr[i];
            if (ccw(l2.p, l1.p, l2.q) == 0) {
                if (min(l2.p.first, l2.q.first) <= p.first && p.first <= max(l2.p.first, l2.q.first)
                    && min(l2.p.second, l2.q.second) <= p.second && p.second <= max(l2.p.second, l2.q.second)) {
                    cout << "1\n";
                    break;
                }
                else {
                    continue;
                }
            }
            if (ccw(l1.p, l2.p, l1.q) * ccw(l1.p, l2.q, l1.q) <= 0 &&
                ccw(l2.p, l1.p, l2.q) * ccw(l2.p, l1.q, l2.q) <= 0) {

                if (l1.p.y == max(l2.p.y, l2.q.y))
                    continue;
                
                cnt++;
            }
        }

        if (i == arr.size())
            cout << (cnt % 2) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}