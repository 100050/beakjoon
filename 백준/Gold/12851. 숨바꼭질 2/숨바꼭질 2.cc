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
const ll MOD = 10000000;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int dp[200001];

int bfs(int s, int e) {
    queue<pii> q;
    int res = 0, t;
    bool flag = false;
    q.push(pii(s, 0));
    while (q.size()) {
        pii f = q.front(); q.pop();
        if (dp[f.first] != -1 && dp[f.first] < f.second) continue;
        dp[f.first] = f.second; 
        //cout << f.first << " " << f.second << " " << res << "\n";
        
        if (f.first == e) res++;

        if (f.first > 0 && abs(f.first * 2 - e) <= abs(f.first - e))
            q.push(pii(f.first * 2, f.second + 1));
        if (e > f.first) q.push(pii(f.first + 1, f.second + 1));
        if (f.first != 0) q.push(pii(f.first - 1, f.second + 1));
    }

    return res;
}

void solve(int CASE = -1) {
    int n, k;

    cin >> n >> k;

    for (int i = 0; i <= 200000; i++) dp[i] = -1;

    int res = bfs(n, k);

    cout << dp[k] << "\n" << res;
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