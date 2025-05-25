#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

const int mxN = 100001;
int dp[1001][1001][2];

void fun(vector<int>& arr, int b, int e, bool turn, int dp[][1001][2]) {
    if (b == e) {
        dp[b][e][turn] = arr[b];
        dp[b][e][!turn] = 0;
        return;
    }
    if (dp[b][e][turn]) {
        return;
    }
    fun(arr, b + 1, e, !turn, dp);
    fun(arr, b, e - 1, !turn, dp);
    
    if (dp[b + 1][e][turn] + arr[b] > dp[b][e - 1][turn] + arr[e]) {
        dp[b][e][turn] = dp[b + 1][e][turn] + arr[b];
        dp[b][e][!turn] = dp[b + 1][e][!turn];
    }
    else {
        dp[b][e][turn] = dp[b][e - 1][turn] + arr[e];
        dp[b][e][!turn] = dp[b][e - 1][!turn];
    }
}

void solve() {
    int n, a;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }

    fun(arr, 0, n-1, 0, dp);

    cout << dp[0][n-1][0] << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j][0] = dp[i][j][1] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}