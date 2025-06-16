#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <cstdlib>   
#include <ctime> 
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

ll dp[100001][11];
vector<pil> arr[100001];
int n, m, k, s, t;
ll a, b, d;

ll dfs(int node, int k) {
    ll& tmp = dp[node][k];
    if (tmp != -100000000000001) return tmp;
    if (k == 0 && node >= t) {
        //cout << node << " " << k << " " << tmp << "\n";
        if (node > t) return tmp;
        else if (node == t) return tmp = 0;
    }
    for (pil next : arr[node]) {
        //cout << node << " " << next.second << " " << k << "\n";
        if (next.second > node) {
            ll tmp2 = dfs(next.second, k);
            //cout << tmp2 << endl;
            tmp = max(tmp, tmp2 + next.first);
            //dp[next.second][k] = dp[node][k] + next.first;
        }
        else if (k != 0) {
            //dp[next.second][k-1] = dp[node][k];
            ll tmp2 = dfs(next.second, k - 1);
            //cout << tmp2 << endl;
            tmp = max(tmp, tmp2);
        }
        //cout << node << " " << next.second << " " << k << " " << tmp << "\n";
    }

    return tmp;
}

void solve() {
    cin >> n >> m >> k >> s >> t;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> d;
        arr[b].push_back({ d, a });
        arr[a].push_back({ d, b });
    }

    for (int i = 0; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[j][i] = -100000000000001;
        }
    }

    dfs(s, k);

    if (dp[s][k] < 0) dp[s][k] = -1;
    cout << dp[s][k];
    
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