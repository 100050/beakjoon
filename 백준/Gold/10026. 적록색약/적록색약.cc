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
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void dfs(int x, int y, int color, int arr[][101], int n) {
    arr[x][y] = -1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < n && 0 <= ny && ny < n && arr[nx][ny] == color) {
            dfs(nx, ny, color, arr, n);
        }
    }
}

void solve(int CASE = -1) {
    int n;
    int normal[101][101] = { 0, };
    int blind[101][101] = { 0, };
    char color;

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> color;
            
            switch (color) {
            case 'R':
                normal[i][j] = 1;
                blind[i][j] = 1;
                break;
            case 'G':
                normal[i][j] = 2;
                blind[i][j] = 1;
                break;
            case 'B':
                normal[i][j] = 3;
                blind[i][j] = 2;
                break;
            }
        }
    }

    int bn = 0, nn = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (normal[i][j] != -1) {
                dfs(i, j, normal[i][j], normal, n);
                nn++;
            }

            if (blind[i][j] != -1) {
                dfs(i, j, blind[i][j], blind, n);
                bn++;
            }
        }
    }

    cout << nn << " " << bn;
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