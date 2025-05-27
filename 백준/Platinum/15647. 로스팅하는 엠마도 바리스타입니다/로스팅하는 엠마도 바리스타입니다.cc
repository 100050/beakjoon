#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

vector<vector<pil>> arr;
vector<vector<pil>> dp;

pil dfs(pil node, int pre, int index) {
    if (arr[node.second].size() == 0) {
        return { index == -1 ? 0 : arr[pre][index].first, 1};
    }
    if (index != -1 && dp[pre][index].first != 0) {
        return dp[pre][index];
    }
    ll sum = index == -1 ? 0 : arr[pre][index].first, n = 1;
    for (int i = 0; i < arr[node.second].size(); i++) {
        pil no = arr[node.second][i];
        if (no.second == pre) continue;
    //cout << sum << " " << n << "\n";
        pil tmp = dfs(no, node.second, i);
        sum += tmp.first + tmp.second*node.first;
        n += tmp.second;
    }

    if (index != -1)
        dp[pre][index] = { sum, n };
    return { sum, n };
}

void solve() {
    int n, u, v, d;

    cin >> n;
    arr = vector<vector<pil>>(n + 1);
    dp = vector<vector<pil>>(n + 1);
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v >> d;
        arr[u].push_back({ d, v });
        arr[v].push_back({ d, u });
        dp[u].push_back({ 0, v });
        dp[v].push_back({ 0, u });
    }
    
    for (int i = 1; i <= n; i++) {
        cout << dfs(pil(0, i), -1, -1).first << "\n";
    }
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