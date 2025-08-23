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
//const ll MOD = 10000000;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int dp[1001][1001][4], arr[1001][1001];
int n, m;

int dfs(int y, int x, int d) {
    if (y == n - 1 && x == m - 1) return arr[y][x];
    
    int& ret = dp[y][x][d];
    if (ret != -1000000000) return ret;
    
    
    for (int i = 0; i < 4; i++) {
        if (i == 1) continue;
        if (d == 2 && i == 0) continue;
        if (d == 0 && i == 2) continue;
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (0 <= ny && ny < n && 0 <= nx && nx < m) {
            
            ret = max(ret, dfs(ny, nx, i));
        }
    }
    
    ret += arr[y][x];
    
    return ret;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = dp[i][j][3] = -1000000000;
        }
    }
    
    cout << dfs(0, 0, 3);
    

    return 0;
}