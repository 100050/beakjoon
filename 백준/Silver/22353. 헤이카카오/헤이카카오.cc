#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <cstdlib>   
#include <ctime> 
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

void solve() {
    long double a, d, k;

    cin >> a >> d >> k;

    long double test = d;
    int n = 0;
    while (true) {
        if (test >= 100) {
            break;
        }
        n++;
        test *= (100 + k) / 100.0;
        //cout << test;
    }

    long double res = 0;
    long double tmp = (d / 100.0);
    long double tmp2 = 1;
    bool flag = true;
    for (int i = 1; i <= n + 1; i++) {
        res += i * a * tmp * tmp2;
        if (flag) {
            tmp2 *= (1 - tmp);
            tmp *= (100 + k) / 100.0;
            if (tmp >= 1) {
                tmp = 1;
                flag = false;
            }
        }
        else {
            break;
        }
        //cout << tmp << " " << tmp2 << "\n";
    }
    cout.precision(20);
    cout << fixed;
    cout << res;
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