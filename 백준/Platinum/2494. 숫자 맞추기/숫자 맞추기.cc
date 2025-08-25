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
pii choice[10001][10];

int dfs(int d, int lc) {
    if (d == n) {
        return 0;
    }

    int& ret = dp[d][lc % 10];
    if (ret != -1) return ret;

    ret = 1000000000;
    int ns = (s[d] + lc) % 10;
    int l = ns > e[d] ? 10 - ns + e[d] : e[d] - ns;
    int next = dfs(d + 1, l + lc) + l;
    //cout << d << " " << lc << " " << ns << " " << next << "\n";
    if (ret > next) {
        ret = next;
        choice[d][lc % 10] = pii(l, l + lc);
    }
    int r = ns < e[d] ? 10 - e[d] + ns : ns - e[d];
    next = dfs(d + 1, lc) + r;
    if (ret > next) {
        ret = next;
        choice[d][lc % 10] = pii(-r, lc);
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
    
    int l = s[0] > e[0] ? 10 - s[0] + e[0] : e[0] - s[0];
    int next = dfs(1, l) + l;
    if (ret > next) {
        ret = next;
        choice[0][0 % 10] = pii(l, l);
    }
    int r = s[0] < e[0] ? 10 - e[0] + s[0] : s[0] - e[0];
    next = dfs(1, 0) + r;
    if (ret > next) {
        ret = next;
        choice[0][0 % 10] = pii(-r, 0);
    }

    int d = 0, lc = 0;
    cout << ret << "\n";
    while (d != n) {
        cout << d + 1 << " " << choice[d][lc % 10].first << "\n";
        lc = choice[d][lc % 10].second;
        d++;
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