#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
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

constexpr ll MOD = 1000000007;
//const ll MOD = 10007;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max();
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

int n, m;
int arr[101][101];

int dfs(int y, int x, int visited[][101]) {
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (0 <= nx && nx < m && 0 <= ny && ny < n) {
            if (visited[ny][nx] == 0) {
                visited[ny][nx] = 1;

                if (arr[ny][nx] == 0)
                    ret += dfs(ny, nx, visited);
            }
            else if (visited[ny][nx] == 1) {
                if (arr[ny][nx] == 1) visited[ny][nx] = -1, ret++;
            }
        }
    }

    //cout << y << " " << x << " " << ret << "\n";
    return ret;
}

void solve(int CASE = -1) {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int x = 0;
    while (true) {
        int visited[101][101] = { 0, };
        if (dfs(0, 0, visited) == 0) break;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == -1)
                    arr[i][j] = 0;
            }
        }
        x++;
    }

    cout << x;
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