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

int n, m, c, d, mn;
vector<ll> dp;

void solve() {

    cin >> n >> m >> c >> d;
    dp.resize(m + 1);

    ll b;
    cin >> b;
    for (int i = 1; i <= m; i++) dp[i] = abs(b - i);
    for (int i = 1; i < n; i++) {
        ll tmp;
        cin >> b;

        for (int j = 0; j < c; j++) {
            // d/c개 먼저 삽입
            deque<pil> q;

            q.push_back(pil(dp[j + 1], j + 1));
            for (int k = c; k <= d && j + 1 + k <= m; k += c) {
                if (dp[j + 1 + k] <= q.front().first) q.push_front(pil(dp[j + 1 + k], j + 1 + k));
                else q.push_back(pil(dp[j + 1 + k], j + 1 + k));
            }
            for (int k = j + 1; k <= m; k += c) {
                while (q.front().second < k - d) q.pop_front();
                tmp = abs(b - k) + q.front().first;
                if (k + d + c <= m) {
                    if (dp[k + d + c] <= q.front().first) q.push_front(pil(dp[k + d + c], k + d + c));
                    else q.push_back(pil(dp[k + d + c], k + d + c));
                }
                dp[k] = tmp;
            }
        }
        //cout << dp[i] << "\n";
    }

    mn = dp[1];
    for (int i = 1; i <= m; i++) {
        mn = min(static_cast<ll>(mn), dp[i]);
        //cout << dp[i] << " ";
    }

    cout << n * m - mn;
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