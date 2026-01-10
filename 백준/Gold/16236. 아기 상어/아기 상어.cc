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

int n, s = 2, c = 0;
int arr[21][21];

int bfs(int& y, int& x) {
    queue<pair<pii, int>> q;
    bool visited[21][21] = { 0, };
    int ty = 100, tx = 100, td = 1000;
    q.push(make_pair(make_pair(y, x), 0));
    visited[y][x] = true;

    while (q.size()) {
        auto [c, d] = q.front(); q.pop();

        if ((arr[c.first][c.second] != 0 && arr[c.first][c.second] < s) &&
            ((ty > c.first) || (ty == c.first && tx > c.second)) && td >= d) {
            ty = c.first; tx = c.second;
            td = d;
        }

        for (int i = 0; i < 4; i++) {
            int ny = c.first + dy[i];
            int nx = c.second + dx[i];

            if ((0 <= ny && ny < n && 0 <= nx && nx < n) 
                && (arr[ny][nx] == 0 || arr[ny][nx] <= s)
                && !visited[ny][nx]) {
                q.push(make_pair(make_pair(ny, nx), d+1));
                visited[ny][nx] = true;
            }
        }
    }

    if (td != 1000) {
        y = ty, x = tx;
        arr[y][x] = 0;
        return td;
    }
    else {
        return -1;
    }
}

void solve(int CASE = -1) {
    int x, y;

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) y = i, x = j, arr[i][j] = 0;
        }
    }

    int t = 0;
    while (true) {
        int ret = bfs(y, x);

        if (ret == -1) break;

        t += ret;
        c++;
        if (c == s) {
            c = 0;
            s++;
        }
    }

    cout << t;
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