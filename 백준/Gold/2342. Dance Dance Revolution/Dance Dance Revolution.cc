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
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

int dp[100'001][25];

int mov(int p1, int p2) {
    int left1 = p1 / 5, right1 = p1 % 5;
    int left2 = p2 / 5, right2 = p2 % 5;

    if (right1 == right2) {
        swap(left1, right1);
        swap(left2, right2);
    }

    // left 고정
    if (right1 == 0) {
        return 2;
    }
    else if (right1 == right2) {
        return 1;
    }
    else if (abs(right1 - right2) == 2) {
        return 4;
    }
    else {
        return 3;
    }

}

void solve(int CASE = -1) {
    vector<int> arr;

    arr.push_back(0);
    while (true) {
        int t;
        cin >> t;
        if (t == 0) break;
        arr.push_back(t);
    }

    fill(&dp[0][0], &dp[100'001 - 1][25], INF<int> / 2);

    dp[0][0] = 0;
    for (int i = 1; i < arr.size(); i++) {
        int pre = arr[i - 1];
        int nxt = arr[i];
        for (int j = 0; j < 5; j++) {
            if (i != 1 && pre == j) continue;

            if (nxt != j) {
                dp[i][nxt * 5 + j] = min(dp[i][nxt * 5 + j], dp[i - 1][pre * 5 + j] + mov(pre * 5 + j, nxt * 5 + j));
                dp[i][j * 5 + nxt] = min(dp[i][j * 5 + nxt], dp[i - 1][j * 5 + pre] + mov(j * 5 + pre, j * 5 + nxt));
                //cout << dp[i][nxt * 5 + j] << " " << dp[i][j * 5 + nxt] << " ";
            }
            if (pre != nxt) {
                dp[i][pre * 5 + nxt] = min(dp[i][pre * 5 + nxt], dp[i - 1][pre * 5 + j] + mov(pre * 5 + j, pre * 5 + nxt));
                dp[i][nxt * 5 + pre] = min(dp[i][nxt * 5 + pre], dp[i - 1][j * 5 + pre] + mov(j * 5 + pre, nxt * 5 + pre));
                //cout << dp[i][pre * 5 + nxt] << " " << dp[i][nxt * 5 + pre] << " ";
            }
            //cout << "\n";
        }
    }

    int res = INF<int>;
    for (int i = 0; i < 25; i++) {
        res = min(res, dp[arr.size() - 1][i]);
    }

    cout << res;
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