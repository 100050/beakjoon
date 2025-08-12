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

int n, m;
int arr[16][16];
int dp[16][16][3];
enum Direction
{
    down, right, diagonal
};

int dfs(int y, int x, Direction pre) {
    int& ret = dp[y][x][pre];
    //cout << y << " " << x << " " << ret << "\n";
    if (ret != -1) return ret;

    if (y == n - 1 && x == n - 1) return ret = 1;

    ret = 0;
    
    int ny = y + 1;
    int nx = x + 1;

    if (0 <= ny && ny < n && arr[ny][x] != 1 && pre != Direction::right) {
        ret += dfs(ny, x, Direction::down);
    }
    if (0 <= nx && nx < n && arr[y][nx] != 1 && pre != Direction::down) {
        ret += dfs(y, nx, Direction::right);
    }
    if (0 <= ny && ny < n && 0 <= nx && nx < n 
        && arr[ny][nx] != 1 && arr[y][nx] != 1 && arr[ny][x] != 1) {
        ret += dfs(ny, nx, Direction::diagonal);
    }

    //cout << y << " " << x << " " << ret << "\n";

    return ret;
}

void solve(int CASE = -1) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
        }
    }

    int res = dfs(0, 1, Direction::right);

    cout << res;
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