#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
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
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

int n, m, k;
ll adj[21][21];

void floyd() {
    for (int k = 1; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

ll dp[(1 << 21)][21]; // 0에서 출발해 set을 방문하고 here일 때 최소 비용

ll cost[21];

ll dp2[100001];

void solve(int CASE = -1) {

    cin >> n >> m >> k;
    fill(&adj[0][0], &adj[20][21], INF<int>);
    for (int i = 0; i < n; i++) adj[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        if (adj[a][b] > c) adj[a][b] = c, adj[b][a] = c;
    }

    // 최단 경로 그래프 구하기
    floyd();

    // 외판원 순회로 가치 (n-1)^2, 비용 c를 가지는 아이템 찾기
    fill(&dp[0][0], &dp[(1 << 21) - 1][21], INF<int>);
    fill(&cost[0], &cost[21], INF<int>);
    
    dp[1][0] = 0;
    for (int s = 1; s <= (1 << n) - 1; s++) {
        if ((s & 1) == 0) continue;

        int t = s, c = 0;
        while (t) {
            if (t & 1) c++;
            t >>= 1;
        }
        for (int here = 0; here < n; here++) {
            
            if ((s & (1 << here)) == 0) continue;
            ll& r = dp[s][here];
            for (int i = 0; i < n; i++) {
                if ((s & (1 << i)) != 0) continue;
                
                dp[s | (1 << i)][i] = min(
                    dp[s | (1 << i)][i], r + adj[here][i]
                );
            }
            cost[c] = min(cost[c], r + adj[here][0]);

        }
    }

    vector<pil> item;
    item.push_back(pil());
    for (int i = 2; i <= n; i++) {
        //if (cost[i] > k) continue;
        item.push_back(make_pair(cost[i], (i - 1) * (i - 1)));
        //cout << item.back().first << " " << i << "\n";
    }

    // 냅섹
    ll ans = 0;
    for (int i = 1; i < item.size(); i++) {
        for (int j = 1; j <= k; j++) {
            if (j - item[i].first >= 0)
                dp2[j] = max(dp2[j], dp2[j - item[i].first] + item[i].second);
        }
        ans = max(ans, dp2[k]);
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    //pre();
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}