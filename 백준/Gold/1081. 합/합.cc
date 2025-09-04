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
const ll MOD = 10007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int l, u;
ll power10[12];
ll dp[12][10];



ll dfs(int n) {
    if (n == 0) return 0LL;

    ll s = 0, ret = 0;
    
    // 숫자 -> 배열
    int arr[11] = { 0, };
    int idx = 0;
    while (n != 0) {
        arr[idx] = n % 10;
        n /= 10;
        idx++;
    }

    // 0~n까지 합 구하기
    idx--;
    while (idx >= 1) {
        if (arr[idx] == 0) {
            idx--;
            continue;
        }

        ret += dp[idx][arr[idx]-1] + s * ((arr[idx]) * power10[idx]);
        s += arr[idx];
        //cout <<idx << " " << s << " " << ret << "\n";
        idx--;
    }
    ret += dp[idx][arr[idx]] + s * (arr[idx] + 1);

    return ret;
}

void solve(int CASE = -1) {

    cin >> l >> u;

    power10[0] = 1;
    for (int i = 1; i <= 11; i++) {
        power10[i] = power10[i - 1] * 10;
    }

    for (int i = 1; i < 10; i++) {
        dp[0][i] += dp[0][i - 1] + i;
    }
    for (int i = 1; i <= 11; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j] = power10[i] * j + dp[i - 1][9];
            if (j != 0) dp[i][j] += dp[i][j - 1];
        }
    }

    if (l != 0) l--;

    cout << dfs(u) - dfs(l);
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