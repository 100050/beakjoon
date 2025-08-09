#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ranges>
#include <numeric>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int n;
int dp[100000][2][2];

void solve(int CASE = -1) {
    array<vector<int>, 2> arr;

    cin >> n;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            int t;
            cin >> t;
            arr[i].push_back(t);
            dp[j][i][true] = dp[j][i][false] = 0;
        }
    }

    int res = 0;

    dp[0][0][true] = arr[0][0];
    dp[0][0][false] = 0;
    dp[0][1][true] = arr[1][0];
    dp[0][1][false] = arr[0][0];


    for (int i = 1; i < n; i++) {
        // 위
        dp[i][0][true] = max(dp[i][0][true], arr[0][i] + dp[i - 1][1][true]);
        dp[i][0][true] = max(dp[i][0][true], arr[0][i] + dp[i - 1][0][false]);
            
        dp[i][0][false] = max(dp[i][0][false], dp[i - 1][1][true]);
        dp[i][0][false] = max(dp[i][0][false], dp[i - 1][1][false]);
        //cout << dp[i][0][false] << " " << dp[i][0][true] << "\n";

        // 아래
        dp[i][1][true] = max(dp[i][1][true], arr[1][i] + dp[i - 1][1][false]);

        dp[i][1][false] = max(dp[i][1][false], dp[i][0][true]);
        dp[i][1][false] = max(dp[i][1][false], dp[i][0][false]);
        //cout << dp[i][1][false] << " " << dp[i][1][true] << "\n";
    }

    res = max(dp[n - 1][1][false], dp[n - 1][1][true]);

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}