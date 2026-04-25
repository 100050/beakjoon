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

int origin[31][31];
int ne[31][31];
bool check[31][31];

void dfs(int x, int y, int n, int m, int new_color, int origin_color) {
    check[x][y] = true;
    origin[x][y] = new_color;
    int dx[4] = { 0, -1, 0, 1 };
    int dy[4] = { 1, 0, -1, 0 };

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 and nx < n and ny >= 0 and ny < m and check[nx][ny] == false and origin[nx][ny] == origin_color)
            dfs(nx, ny, n, m, new_color, origin_color);
    }
}

void solve() {
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> origin[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ne[i][j];
        }
    }

    bool flag = false;
    bool flag2 = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check[i][j]) { // 이미 본 곳
                continue;
            }
            if (ne[i][j] != origin[i][j]) {
                //check[i][j] = true;
                if (flag) {
                    cout << "NO";
                    return;
                    
                }
                flag = true;
                dfs(i, j, n, m, ne[i][j], origin[i][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ne[i][j] != origin[i][j]) {
                cout << "NO";
                return;
            }
        }
    }

    cout << "YES";
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