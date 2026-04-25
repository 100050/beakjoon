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

int dp[50001];

void solve() {
    int n, t = 1;

    cin >> n;
    // dp n보다 작은 제곱 수로 나누고 나머지를 dp에서 가져옴 둘의 합
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if ((t+1)*(t+1) <= i) t++;

        dp[i] = 5;

        for (int j = 1; j <= t; j++) {
            dp[i] = min(dp[i], 1 + dp[i - (j * j)]);
        }
    }

    cout << dp[n];
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