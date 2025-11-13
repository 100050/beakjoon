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
#include <cstring>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

constexpr ll MOD = 1000000007;
//const ll MOD = 10007;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max();
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n;
int dp[(1 << 15) + 1][5][183];

void solve(int CASE = -1) {
    for (int i = 0; i <= 182; i++) {
        dp[0][0][i] = 1;
    }
    // p1 + p2 = q1 + q2, 5 = 4 + 1 = 1 + 4
    for (int i = 1; i <= (1 << 15); i++) {
        for (int k = 1; k <= 4; k++) {
            //dp[i][k] += dp[i - 1][k - 1];
            for (int j = 1; j <= 182; j++) { 
                if (i - j * j < 0) dp[i][k][j] = dp[i][k][j - 1];
                else dp[i][k][j] = dp[i][k][j - 1] + dp[i - j * j][k - 1][j];
            }
            //cout << i << " " << k << " " << dp[i][k][182] << "\n";
        }
    }

    while (true) {
        cin >> n;
        if (n == 0) break;
        ll res = 0;
        for (int k = 1; k <= 4; k++)
                res += dp[n][k][182];

        cout << res << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}