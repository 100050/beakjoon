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
    ll l, r;
    cin >> n;
    l = 1;
    r = n;

    while (l <= r) {
        int ans;
        ll mid = (l + r) / 2;

        cout << "? " << mid << endl;
        cin >> ans;

        if (ans == -1) {
            l = mid + 1;
        }
        else if (ans == 1) {
            r = mid - 1;
        }
        else {
            cout << "= " << mid << endl;
            break;
        }
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