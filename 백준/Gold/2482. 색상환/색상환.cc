#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

ll k;
ll n;
ll dp[1001][1001];

void solve() {

    cin >> n;                   
    cin >> k;
    for (int i = 1; i <= n; i++) {
        dp[i][1] = i;
    }
    dp[1][1] = 1;
    dp[2][1] = 2;
    for (int i = 4; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % 1000000003;
        }
    }

    cout << dp[n][k] % 1000000003;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}