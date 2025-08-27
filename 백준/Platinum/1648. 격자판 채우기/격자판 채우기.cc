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

//const ll MOD = 1000000007;
const ll MOD = 9901;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int dp[15*15][1<<15];

int n, m;

int dfs(int idx, int s) {
    if (idx == n * m) {
        return s == 0 ? 1 : 0;
    }

    if ((s & 1) != 0) return dfs(idx + 1, s >> 1);

    int& ret = dp[idx][s];
    if (ret != -1) return ret;

    ret = 0;
    
    if ((s & 2) == 0 && (idx % m != m - 1)) {
        ret = dfs(idx + 2, s >> 2) % MOD;
    }
    
    ret = (ret + dfs(idx + 1, s >> 1 | 1 << (m - 1))) % MOD;

    //cout << idx << " " << s << " " << ret << "\n";
    return ret;
}

void solve(int CASE = -1) {

    memset(dp, -1, sizeof(dp));
    cin >> n >> m;

    if ((n * m) % 2 == 1) {
        cout << 0;
        return;
    }

    cout << dfs(0, 0);
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