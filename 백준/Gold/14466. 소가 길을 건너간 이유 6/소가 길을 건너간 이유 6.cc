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

int n;
int arr[101][101][5];

int dfs(int r, int c, bool visited[][101]) {
    int res = arr[r][c][4];
    visited[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int nr = r + dy[i];
        int nc = c + dx[i];

        if (1 <= nr && nr <= n && 1 <= nc && nc <= n && arr[r][c][i] == 0 && visited[nr][nc] == false) {
            int tmp = dfs(nr, nc, visited);
            //cout << r << " " << c << " " << tmp << "\n";
            res += tmp;
                
            
        }
    }

    return res;
}

void solve(int CASE = -1) {
    int k, r;

    cin >> n >> k >> r;
    for (int i = 0; i < r; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int d;
        for (d = 0; d < 4; d++) {
            int nr = r1 + dy[d];
            int nc = c1 + dx[d];
            if (nr == r2 && nc == c2) break;
        }
        arr[r1][c1][d] = 1;
        arr[r2][c2][(d + 2) % 4] = 1;
    }
    vector<pii> cow;
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        cow.push_back(make_pair(r, c));
        arr[r][c][4] = 1;
    }

    int res = 0;
    for (const pii& c : cow) {
        bool visited[101][101] = { 0, };
        res += k - dfs(c.first, c.second, visited);
        //cout << res << "\n";
    }

    cout << res / 2;
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