#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <unordered_set>
#include <queue>
#include <stack>
#include <ranges>
#include <numeric>
#include <cstring>
#include <bit>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

//constexpr ll MOD = 1000000007;
constexpr ll MOD = 1000000000;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

int n;
// dp[d][n][s] = d번째 자릿수이고 이전 숫자가 n이고 s에 있는 숫자를 이미 사용했을 때 
// 만들 수 있는 계단 수의 개수
int dp[100][10][1<<10];


int dfs(int d, int pre, int s) {
    if (d == n) {
        return s == (1 << 10) - 1;
    }

    int& ret = dp[d][pre][s];
    if (ret != -1) return ret;

    if (pre == 0) {
        return ret = dfs(d + 1, 1, s | (1 << 0));
    }
    else if (pre == 9) {
        return ret = dfs(d + 1, 8, s | (1 << 8));
    }
    else {
        return ret = (dfs(d + 1, pre - 1, s | (1 << (pre - 1))) 
            + dfs(d + 1, pre + 1, s | (1 << (pre + 1)))) % MOD;
    }
}

void solve(int CASE = -1) {
    
    cin >> n;

    fill(&dp[0][0][0], &dp[99][9][1 << 10], -1);

    int res = 0;
    for (int i = 1; i < 10; i++) {
        res += dfs(1, i, (1 << i));
        res %= MOD;
    }
    
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    //pre();
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}