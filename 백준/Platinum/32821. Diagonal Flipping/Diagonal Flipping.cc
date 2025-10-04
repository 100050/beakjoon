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

constexpr ll MOD = 1000000007;
//const ll MOD = 10007;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max();
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n, m;
// 보드
int arr[1000][1000];

int bfs(int start, int c) {
    int cnt = c;

    // 플립했는지 저장
    int flipped[2][2000] = { 0, };
    // 방문했는지 저장
    bool visited[2][2000] = { 0, };

    flipped[0][start] = c;
    visited[0][start] = true;
    // (정점, 연산)
    queue<pii> q;
    q.push(make_pair(start, 0));
    while (q.size()) {
        pii f = q.front(); q.pop();

        int nxt_op = (f.second + 1) % 2;
        for (int y = 0; y < m; y++) {
            int x = (f.second ? y - (f.first - n + 1) : f.first - y);
            int nxt_idx = (f.second ? y + x : y - x + n - 1);

            if (x >= n || x < 0) continue;


            if (!visited[nxt_op][nxt_idx]) {
                flipped[nxt_op][nxt_idx] = flipped[f.second][f.first] ^ arr[y][x];
                visited[nxt_op][nxt_idx] = true;

                // 현재 대각선 연산을 해야할 때만 cnt에 1 더함
                cnt += flipped[nxt_op][nxt_idx]; 
                q.push(make_pair(nxt_idx, nxt_op));
            }
            else if (arr[y][x] != (flipped[nxt_op][nxt_idx] ^ flipped[f.second][f.first])){
                return INF<int>;
            }
        }

    }
    
    return cnt;
}

void solve(int CASE = -1) {

    cin >> m >> n;
    int ret = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (m == 1 || n == 1) {
                ret += arr[i][j];
            }
        }
    }

    if (m == 1 || n == 1) {
        cout << ret;
        return;
    }

    ret = min(bfs(0, 0), bfs(0, 1));
    if (ret >= INF<int>) {
        cout << -1;
        return;
    }
    int ret2 = min(bfs(1, 0), bfs(1, 1));
    if (ret2 >= INF<int>) {
        cout << -1;
        return;
    }

    cout << ret + ret2 << "\n";
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