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

struct Problem {
    // 보상, 패널티, 푸는데 걸리는 시간
    ll m, p, r;
};

ll dp[51][100001];

void solve(int CASE = -1) {
    int n, t;
    vector<Problem> p;

    cin >> n >> t;
    p.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i].m;
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i].p;
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i].r;
    }
    p[0].r = 0;
    p[0].p = 1;
    sort(p.begin(), p.end(), [](const Problem& a, const Problem& b) {
        return b.r * a.p > a.r * b.p;
        });

    ll res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= t; j++) {
            if (j >= p[i].r) {
                dp[i][j] = max(dp[i - 1][j], dp[i-1][j-p[i].r] + p[i].m - j * p[i].p);
                dp[i][j] = max(dp[i][j], 0LL);
            }
            else {
                dp[i][j] = max(dp[i - 1][j], 0LL);
            }

            if (i == n) {
                res = max(res, dp[i][j]);
            }
        }
    }

    cout << res << "\n";
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