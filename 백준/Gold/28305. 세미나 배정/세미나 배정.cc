#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
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

vector<ll> arr, dp;
int n;
ll t;

bool cal(int c) {
    for (int i = 0; i < n; i++) {
        dp[i] = arr[i];
    }
    if (c == 0)
        return false;
    for (int i = 0; i < n; i++) {
        if (i < c) {
            if (dp[i] >= t) {
                dp[i] = arr[i] + 1;
            }
            else {
                dp[i] = t + 1;
            }
        }
        else {
            if (dp[i - c] > arr[i])
                return false;
            if (dp[i - c] + t <= arr[i] + 1) {
                dp[i] = arr[i] + 1;
            }
            else
                dp[i] = dp[i - c] + t;
        }
    }
    return true;
}

void solve() {

    cin >> n >> t;
    arr.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    
    int l, r, mid;
    l = 1, r = n;
    while (l <= r) {
        mid = (l + r) / 2;

        if (cal(mid)) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    if (!cal(mid)) mid++;
    cout << mid;
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