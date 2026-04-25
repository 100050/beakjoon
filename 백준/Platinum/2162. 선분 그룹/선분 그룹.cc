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

bool intersect(Line& l1, Line& l2) {
    if (ccw(l1.p, l2.p, l1.q) == 0 && ccw(l1.p, l2.q, l1.q) == 0 &&
        ccw(l2.p, l1.p, l2.q) == 0 && ccw(l2.p, l1.q, l2.q) == 0) {
        if (l1.p > l1.q) swap(l1.p, l1.q);
        if (l2.p > l2.q) swap(l2.p, l2.q);

        return (l2.p <= l1.q && l1.p <= l2.q);
    }
    if (ccw(l1.p, l2.p, l1.q) * ccw(l1.p, l2.q, l1.q) <= 0 &&
        ccw(l2.p, l1.p, l2.q) * ccw(l2.p, l1.q, l2.q) <= 0) {
        return true;
    }

    return false;
}

vector<Line> arr;
int group[3000];
int num[3000];

int F(int i) {
    if (num[i] == i) {
        return i;
    }
    else {
        return num[i] = F(num[i]);
    }
}

void U(int i, int j) {
    int ii = F(i);
    int jj = F(j);

    if (ii == jj) { // 그룹 사이즈도 저장
        return;
    }
    else if (ii < jj) {
        num[jj] = ii;
        group[ii] += group[jj];
        group[jj] = 0;
    }
    else {
        num[ii] = jj;
        group[jj] += group[ii];
        group[ii] = 0;
    }
}

void solve() {
    long long a, b, c, d;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        arr.push_back(Line(a, b, c, d));
        num[i] = i;
        group[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // union find
            if (intersect(arr[i], arr[j])) {
                U(i, j);
            }
        }
    }
    

    int mx = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (group[i] != 0) l++;
        mx = max(mx, group[i]);
    }
    cout << l << "\n" << mx;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}