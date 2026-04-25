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

const ll MOD = 1000000007;
//const ll MOD = 10007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };


void solve(int CASE = -1) {
    int dp[51] = { 0, };

    int n;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t, p;
        cin >> t >> p;

        dp[(i + 1) % 50] = max(dp[(i) % 50], dp[(i + 1) % 50]);
        dp[(i + t) % 50] = max(dp[(i) % 50] + p, dp[(i + t) % 50]);
    }

    cout << dp[(n+1) % 50];
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