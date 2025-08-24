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

const ll MOD = 1000000007;
//const ll MOD = 10000000;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int n;
string t;
vector<int> s, e;
int dp[10001][10];

int dfs(int d, int l) {
    if (d == n) {
        return 0;
    }

    int& ret = dp[d][l % 10];
    if (ret != -1) return ret;

    ret = 1000000000;
    for (int i = 0; i < 10; i++) { // 왼쪽으로 돌린 횟수
        int ns = (s[d] + i + l) % 10; // 왼쪽으로 i번 돌렸으면 s[d] 위치
        if (ns >= e[d])
            ret = min(ret, i + dfs(d + 1, l + i) + ns - e[d]);
        else
            ret = min(ret, i + dfs(d + 1, l + i) + 10 + ns - e[d]);
        //cout << d << " " << l << " " << i << " " << ret << "\n";
    }

    return ret;
}

void solve(int CASE = -1) {
    
    cin >> n;
    cin >> t;
    for (int i = 0; i < n; i++) {
        s.push_back(t[i] - '0');
    }
    cin >> t;
    for (int i = 0; i < n; i++) {
        e.push_back(t[i] - '0');
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) dp[i][j] = -1;
    }


    int ret = 1000000000;
    for (int i = 0; i < 10; i++) {// 왼쪽으로 돌린 횟수
        int ns = (s[0] + i) % 10; // 왼쪽으로 i번 돌렸으면 s[d] 위치
        if (ns >= e[0])
            ret = min(ret, i + dfs(1, i) - e[0] + ns);
        else
            ret = min(ret, i + dfs(1, i) + 10 + ns - e[0]);

    }
    
    cout << ret;
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