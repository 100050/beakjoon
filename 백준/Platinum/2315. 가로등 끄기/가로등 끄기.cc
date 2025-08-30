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

int n, m;
// dp[left][right][isRight] = 
// left부터 right까지 가로등의 전원을 껐을 때 낭비된 전력의 최솟값
ll dp[1001][1001][2];
// (d, w)
vector<pil> arr;
vector<ll> s;

ll dfs(int left, int right, int isRight) {
    if (left == 1 && right == n)
        return 0;

    ll& ret = dp[left][right][isRight];
    if (ret != -1) return ret;

    ret = numeric_limits<ll>::max();
    if (right < n) {
        ll t = arr[right + 1].first - (isRight ? arr[right].first : arr[left].first);
        ret = min(ret, dfs(left, right + 1, 1) + t * (s[n] - (s[right] - s[left - 1])));
    }
    if (1 < left) {
        ll t = (isRight ? arr[right].first : arr[left].first) - arr[left - 1].first;
        ret = min(ret, dfs(left - 1, right, 0) + t * (s[n] - (s[right] - s[left - 1])));
    }

    //cout << left << " " << right << " " << ret << "\n";

    return ret;
}

void solve(int CASE = -1) {
    cin >> n >> m;
    arr.resize(n + 1);
    s.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
        s[i] += s[i - 1] + arr[i].second;
    }
    
    cout << dfs(m, m, 0);
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