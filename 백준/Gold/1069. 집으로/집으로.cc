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
    long double x, y, d, t;
    long double dist, time = 0;

    cin >> x >> y >> d >> t;
    dist = sqrt(x * x + y * y);
    cout << fixed;
    cout.precision(100);
    // d <= t
    if (d <= t) {
        cout << dist;

        return;
    }

    if (dist < d) {
        long double mn = dist;
        mn = min(mn, t * 2);
        mn = min(mn, t + d - dist);

        time += mn;
        cout << time;
        return;
    }

    // dist > d * 2
    while (dist > d*2) {
        dist -= d;
        time += t;
    }

    // dist < d * 2
    if (dist < d*2) {
        long double mn = dist;
        mn = min(mn, t * 2);
        mn = min(mn, t + dist - d);
        mn = min(mn, t + t + d*2 - dist);

        time += mn;
    }
    // dist == d*2
    else if (dist == d*2) {
        time += t*2;
    }
        
    cout << time;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}