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

int h, w;
char arr[41][41][2] = {0,};
int dp[41][41][41][41][2];

int dfs(int h1, int w1, int h2, int w2, int x) {
    if (h1 > h2 || w1 > w2) {
        return 0;
    }
    else if (h1 == h2 && w1 == w2) {
        return static_cast<int>(arr[h1][w1][x] != 0);
    }

    int& ret = dp[h1][w1][h2][w2][x];
    if (ret != -1) return ret;
    
    ret = 0;
    vector<bool> map(2001);
    for (int i = h1; i <= h2; i++) {
        for (int j = w1; j <= w2; j++) {
            if (arr[i][j] == 0) continue;

            if (arr[i][j][x] == 'X') {
                map[dfs(h1, w1, i-1, j-1, x) ^ 
                    dfs(h1, j+1, i-1, w2, x) ^ 
                    dfs(i+1, w1, h2, j-1, x) ^ 
                    dfs(i+1, j+1, h2, w2, x)] = true;
            }
            else if (arr[i][j][x] == 'R') {
                map[dfs(h1, w1, h2, j - 1, x) ^
                    dfs(h1, j + 1, h2, w2, x)] = true;
            }
            else if (arr[i][j][x] == 'L') {
                map[dfs(i + 1, w1, h2, w2, x) ^
                    dfs(h1, w1, i - 1, w2, x)] = true;
            }
        }
    }

    for (int i = 0; i < map.size(); i++) {
        if (!map[i]) {
            ret = i;
            break;
        }
    }

    //cout << w1 << " " << w2 << " " << h1 << " " << h2 << " " << ret << "\n";

    return ret;
}

void solve(int CASE = -1) {

    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> arr[i + j][h - 1 + j - i][(i + j) % 2];
        }
    }

    fill(&dp[0][0][0][0][0], &dp[40][40][40][40][2], -1);

    cout << ((dfs(0, 0, h + w - 2, h + w - 2, 0) ^
        dfs(0, 0, h + w - 2, h + w - 2, 1)) == 0 ? "cubelover" : "koosaga");
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