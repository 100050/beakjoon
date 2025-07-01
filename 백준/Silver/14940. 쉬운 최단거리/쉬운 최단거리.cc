#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

int arr[1001][1001];
int res[1001][1001];
int n, m;

void bfs(int y, int x, int d, bool first = true) {
    int dx[4] = { 0, -1, 0, 1 };
    int dy[4] = { -1, 0, 1, 0 };
    queue<tuple<int, int, int>> q;
    res[y][x] = d;
    arr[y][x] = 3;

    q.push(tuple<int, int, int>(y, x, d));

    while (q.size()) {
        auto f = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = get<1>(f) + dx[i];
            int ny = get<0>(f) + dy[i];

            if (0 <= ny && ny < n && 0 <= nx && nx < m && arr[ny][nx] == 1) {
                res[ny][nx] = first ? get<2>(f) + 1 : get<2>(f);
                arr[ny][nx] = 3;
                if (first) q.push(tuple<int, int, int>(ny, nx, get<2>(f) + 1));
                else q.push(tuple<int, int, int>(ny, nx, get<2>(f)));
            }
        }
    }
}

void solve() {
    int x, y;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 2) {
                y = i;
                x = j;
            }
        }
    }
    bfs(y, x, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (res[i][j] == 0 && arr[i][j] == 1) {
                bfs(i, j, -1, false);
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
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