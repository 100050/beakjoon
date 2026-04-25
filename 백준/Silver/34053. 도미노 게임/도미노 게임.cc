#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

const ll MOD = 1000000007;
const ld PI = acos(-1.0L);

int n, m;
ll res = 0;
vector<vector<int>> arr;
vector<vector<bool>> visited;


void dfs(int x, int y) {
    int dx[4] = { 0, -1, 0, 1 };
    int dy[4] = { 1, 0, -1, 0 };

    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny]) {
            if (arr[nx][ny] != 0) {
                res += arr[nx][ny];
                arr[nx][ny] = 0;
            }
            dfs(nx, ny);
        }
    }
}

void solve() {
    
    cin >> n >> m;
    arr.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, 0));
    int mn = 1e9 + 1;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (mn > arr[i][j]) {
                x = i;
                y = j;
                mn = arr[i][j];
            }
        }
    }
    if (mn != 0) {
        if (0 < x) {
            arr[x - 1][y] -= arr[x][y];
        }
        else {
            arr[x + 1][y] -= arr[x][y];
        }
        res += arr[x][y];
        arr[x][y] = 0;
    }
    dfs(x, y);/*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0 && !visited[i][j]) {
                dfs(i, j);
            }
        }
    }*/

    cout << res;
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