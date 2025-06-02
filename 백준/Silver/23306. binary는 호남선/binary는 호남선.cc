#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <cstdlib>   
#include <ctime> 
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;


void solve() {
    ll n;
    ll a, b;

    cin >> n;

    cout << "? " << 1 << endl;
    cin >> a;
    cout << "? " << n << endl;
    cin >> b;

    if (a > b) {
        cout << "! -1" << endl;
    }
    else if (a < b) {
        cout << "! 1" << endl;
    }
    else {
        cout << "! 0" << endl;
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