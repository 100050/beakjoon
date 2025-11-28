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

int digits[17];
ll dp[17][17*9+1][2];

ll dfs(int d, int s, bool small) {
    ll& ret = dp[d][s][small];
    if (ret != -1) return ret;

    ret = 0;
    if (d == 0) {
        return ret = s; // 확인 필요
    }
    
    for (int i = 0; i <= (small ? 9 : digits[d]); i++) {
        //cout << d << " " << s + i << " " << digits[d] << "\n";
        ret += dfs(d - 1, s + i, small || (digits[d] > i));
    }

    return ret;
}

void solve(int CASE = -1) {
    string sl, su;
    ll l, u;
    int i;

    cin >> l >> u;
    l--;
    l = max(0LL, l);
    
    su = to_string(u);
    for (i = 1; i <= su.size(); i++) {
        digits[su.size() - i + 1] = su[i - 1] - '0';
    }
    fill(&dp[0][0][0], &dp[16][17*9][2], -1LL);
    ll res = dfs(su.size(), 0, false);

    sl = to_string(l);
    for (i = 1; i <= sl.size(); i++) {
        digits[sl.size() - i + 1] = sl[i - 1] - '0';
    }
    fill(&dp[0][0][0], &dp[16][17 * 9][2], -1LL);
    res -= dfs(sl.size(), 0, false);

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}