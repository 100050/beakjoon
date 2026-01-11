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

int arr[21][21];
int dp[21][21][21][21];

int dfs(int h1, int w1, int h2, int w2) {
    if (h1 > h2 || w1 > w2) {
        return 0;
    }
    else if (h1 == h2 && w1 == w2) {
        return arr[h1][w1];
    }

    int& ret = dp[h1][w1][h2][w2];
    if (ret != -1) return ret;
    
    ret = 0;
    vector<bool> map(401);
    for (int i = h1; i <= h2; i++) {
        for (int j = w1; j <= w2; j++) {
            if (arr[i][j] == 1) {
                map[dfs(h1, w1, i-1, j-1) ^ 
                    dfs(h1, j+1, i-1, w2) ^ 
                    dfs(i+1, w1, h2, j-1) ^ 
                    dfs(i+1, j+1, h2, w2)] = true;
            }
        }
    }

    for (int i = 0; i < map.size(); i++) {
        if (!map[i]) {
            ret = i;
            break;
        }
    }

    return ret;
}

void solve(int CASE = -1) {
    int h, w;

    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            arr[i][j] = static_cast<int>(c == '.');
        }
    }

    fill(&dp[0][0][0][0], &dp[20][20][20][21], -1);

    cout << (dfs(0, 0, h - 1, w - 1) == 0 ? "Second" : "First");
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