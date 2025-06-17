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
    ll n;

    cin >> n;

    ll j;
    ll res = n;
    for (ll i = 1; i <= n - 1; i = j + 1) {
        j = (n-1) / ((n-1) / i);
        res += (j - i + 1) * ((n - 1) / i);
    }

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