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

void solve() {
    long double x1, x2, y1, y2, r1, r2;
    long double theta1, theta2, d, s;

    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if (d >= r1 + r2) {
        s = 0.000L;
    }
    else if (d+r2 <= r1) {// r1이 r2를 포함한 경우
        s = r2 * r2 * M_PI;
    }
    else if (d + r1 <= r2) { // r2가 r1을 포함한 경우
        s = r1 * r1 * M_PI;
    }
    else {
        theta1 = 2 * acos((d * d + r1 * r1 - r2 * r2) / (2 * d * r1));
        theta2 = 2 * acos((d * d + r2 * r2 - r1 * r1) / (2 * d * r2));
        //cout << (d * d + r2 * r2 - r1 * r1) / (2 * d * r1);
        s = r1 * r1 * (theta1 - sin(theta1)) / 2;
        s += r2 * r2 * (theta2 - sin(theta2)) / 2;

    }


    printf("%.3Lf", s);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}