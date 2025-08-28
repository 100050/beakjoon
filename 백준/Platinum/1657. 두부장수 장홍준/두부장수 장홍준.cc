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

//const ll MOD = 1000000007;
const ll MOD = 9901;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int score[6][6] = {
    10, 8, 7, 5, 0, 1,
    8, 6, 4, 3, 0, 1,
    7, 4, 3, 2, 0, 1,
    5, 3, 2, 2, 0, 1,
    0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 0, 0,
};
char arr[15][15];
int dp[15*15][(1<<15)+1];

int n, m;

int dfs(int idx, int s) {
    if (idx == n * m) {
        return 0;
    }
    if (s & 1) {
        return dfs(idx + 1, s >> 1);
    }

    int y = idx / m;
    int x = idx % m;

    int& ret = dp[idx][s];
    if (ret != -1) return ret;

    ret = dfs(idx + 1, s >> 1);

    if ((s & 2) == 0 && (x != m - 1))
        ret = max(ret, dfs(idx + 2, s >> 2) + score[arr[y][x]][arr[y][x+1]]);

    if (y != n - 1)
        ret = max(ret, dfs(idx + 1, s >> 1 | 1 << (m - 1)) + score[arr[y][x]][arr[y+1][x]]);

    //cout << y << " " << x << " " << ret << "\n";
    return ret;
}

void solve(int CASE = -1) {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            arr[i][j] -= 'A';
        }
    }

    fill(dp[0], dp[n * m], -1);

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