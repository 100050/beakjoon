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

const ll MOD = 1000000007;
//const ll MOD = 10007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int n, orig;
vector<int> arr;
// 각 정수들의 선분 수
int seg[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 5 };
// pos, sum일 때
ll dp[15][106][2];
ll power10[15];
const ll minll = numeric_limits<ll>::min();

ll dfs(int pos, int sum, bool same) {
    if (pos == n) {
        if (same) return minll;
        else return (orig == sum ? 0 : minll);
    }

    ll& ret = dp[pos][sum][same];
    if (ret != -1) return ret;

    for (int i = (same ? arr[pos] : 0); i < 10; i++) {
        ll r = dfs(pos + 1, sum + seg[i], same && i == arr[pos]);
        //cout << pos << " " << r << " " << i << "\n";
        if (r != minll) {
            return ret = r + (i - arr[pos]) * power10[pos];
        }
    }

    return ret = minll;
}

ll dfs2(int pos, int sum, bool same) {
    if (pos == n) {
        return (orig == sum ? 0 : minll);
    }

    ll& ret = dp[pos][sum][same];
    if (ret != -1) return ret;

    for (int i = 0; i <= (same ? arr[pos] : 9); i++) {
        ll r = dfs2(pos + 1, sum + seg[i], same && i == arr[pos]);
        if (r != minll) {
            return ret = r + (arr[pos] - i) * power10[pos];
        }
    }

    return ret = minll;
}

void solve(int CASE = -1) {
    string t;

    cin >> t;
    n = t.size();
    for (int i = 0; i < n; i++) {
        arr.push_back(t[i] - '0');
        orig += seg[arr[i]];
    }
    power10[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        power10[i] = power10[i + 1] * 10;
    }
    memset(dp, -1, sizeof(dp));
    ll r = dfs(0, 0, true);
    if (r == minll) {
        memset(dp, -1, sizeof(dp));
        r = dfs2(0, 0, true);
        r = power10[0] * 10 - r;
        cout << r << "\n";
    }
    else {
        cout << r << "\n";
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