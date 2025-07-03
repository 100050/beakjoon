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

vector<ll> arr, sarr;

ll gcd(ll a, ll b) {
    ll r;

    while (b) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

bool square(ll a) {
    ll L = 1, R = 1e9;
    while (L < R) {
        ll mid = (L + R) / 2;
        if (mid * mid < a) L = mid + 1;
        else R = mid;
    }
    return L * L == a;
}

void solve() {
    int n;
    
    cin >> n;
    arr.resize(n);
    sarr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sarr[i] = arr[i];
    }
    
    sort(sarr.begin(), sarr.end());

    int i = 0;
    for (; i < n; i++) {
        ll g = gcd(arr[i], sarr[i]);
        if (!square(arr[i] / g) || !square(sarr[i] / g)) {
            break;
        }
    }

    cout << (i == n ? "YES" : "NO");
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