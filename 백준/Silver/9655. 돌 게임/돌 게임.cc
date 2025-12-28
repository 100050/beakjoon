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

int dp[1001][2];

int dfs(int n, bool t) {
    if (1 == n && n == 3) return 1;
    if (n == 2) return 0;

    int& ret = dp[n][t];
    if (ret != -1) return ret;

    return ret = (dfs(n - 1, !t) == 0) || (dfs(n - 3, !t) == 0);
}

void solve(int CASE = -1) {
    int n;

    cin >> n;
    
    fill(&dp[0][0], &dp[1000][2], -1);

    if (dfs(n, 1)) {
        cout << "SK";
    }
    else {
        cout << "CY";
    }
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