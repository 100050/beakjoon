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
const ll mod = 1000000007;

void solve() {
    int t;
    int s = 0;

    for (int i = 0; i < 10; i++) {
        cin >> t;

        switch (t) {
        case 1: s += 90; break;
        case 2: s += 180; break;
        case 3: s += 270; break;
        }
    }

    s %= 360;

    switch (s) {
    case 0: cout << "N"; break;
    case 90: cout << "E"; break;
    case 180: cout << "S"; break;
    case 270: cout << "W"; break;
    }
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