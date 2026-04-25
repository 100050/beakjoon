#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

int n;
int arr[21][21];
int dp[1 << 21+1];

int dfs(int d, unsigned int bit) {
    if (dp[bit] != 0)
        return dp[bit];

    if (d == n) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (bit & (1 << i)) {
            if (dp[bit] != 0)
                dp[bit] = min(dp[bit], dfs(d + 1, bit & ~(1 << i)) + arr[d][i]);
            else
                dp[bit] = dfs(d + 1, bit & ~(1 << i)) + arr[d][i];
        }
    }

    return dp[bit];
}

void solve() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << dfs(0, (1 << n) - 1);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}