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

const ll MOD = 1000000007;
const ld PI = acos(-1.0L);

vector<ll> origin;
vector<ll> arr;
vector<ll> rarr;

void solve() {
    int n, k;

    cin >> n >> k;
    arr.resize(n + 1, 0);
    rarr.resize(n + 1, 0);
    origin.resize(n + 1, 0);
    cin >> origin[1];
    arr[1] = origin[1] - k;
    for (int i = 2; i <= n; i++) {
        cin >> origin[i];
        arr[i] = min(arr[i - 1], origin[i] - k * i);
    }
    rarr[n] = origin[n] - k;
    for (int i = n-1; i >= 1; i--) {
        rarr[i] = min(rarr[i + 1], origin[i] - k * (n - i + 1));
    }

    ll res = -1e9;
    for (int i = 2; i <= n; i++) {
        res = max(res, origin[i] - k * i - arr[i - 1]);
        //cout << res << "\n";
    }
    for (int i = n - 1; i >= 1; i--) {
        res = max(res, origin[i] - k * (n - i + 1) - rarr[i + 1]);
        //cout << res << "\n";
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