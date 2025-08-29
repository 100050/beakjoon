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

//const ll MOD = 1000000007;
const ll MOD = 9901;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int n, m, all, mx, v;
int arr[8][8], arr2[8][8];
void dfs(int y, int x) {
    arr2[y][x] = 3;
    v++;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (0 <= ny && ny < n && 0 <= nx && nx < m && (arr2[ny][nx] == 0 || arr2[ny][nx] == 2)) {
            dfs(ny, nx);
        }
    }
}

void wall(int d, vector<pii>& w) {
    if (d == 3) {
        v = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr2[i][j] = arr[i][j];
            }
        }
        for (int i = 1; i <= 3; i++) {
            pii& ww = w[i];
            //cout << ww.first << " " << ww.second << "\n";
            arr2[ww.first][ww.second] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr2[i][j] == 2)
                    dfs(i, j);
            }
        }

        mx = max(mx, all-v);
        //cout << all-v << "\n";
        return;
    }

    for (int i = w[w.size() - 1].first; i < n; i++) {
        for (int j = i == w[w.size() - 1].first ? w[w.size() - 1].second+1 : 0; j < m; j++) {
            if (arr[i][j] != 0) continue;
            w.push_back(make_pair(i, j));
            wall(d + 1, w);
            w.pop_back();
        }
    }
}

void solve(int CASE = -1) {
    cin >> n >> m;
    all = n * m - 3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) all--;
        }
    }
    
    vector<pii> w;
    w.push_back(make_pair(0, -1));
    wall(0, w);
    

    cout << mx;
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