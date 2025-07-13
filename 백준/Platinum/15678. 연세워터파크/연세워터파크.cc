#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int n, d;
vector<ll> dp;
priority_queue<pil, vector<pil>, less<pil>> q;

void solve() {

    cin >> n >> d;
    dp.resize(n, -1e9-1);

    ll s;
    cin >> s;
    dp[0] = s;
    q.push(pil(dp[0], 0));
    for (int i = 1; i < n; i++) {
        ll tmp;
        cin >> s;
        
        while (q.top().second < i - d) q.pop();
        tmp = max(s + q.top().first, s);
        q.push(pil(tmp, i));

        dp[i] = max(tmp, dp[i - 1]);

        //cout << dp[i] << "\n";
    }

    cout << dp[n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}