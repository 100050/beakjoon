#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
int n;
ld dp[(1<<16)][16];
ld adj[16][16];

ld dfs(int s, int v) {
    ld& ret = dp[s][v];
    if (ret != -1) return ret;

    ret = numeric_limits<int>::max();
    if (s == (1 << n) - 1) {
        if (adj[v][0] == 0) return ret;
        else return ret = adj[v][0];
    }
    
    for (int nxt = 0; nxt < n; nxt++) {
        if ((s & (1 << nxt)) == 0 && adj[v][nxt])
            ret = min(ret, dfs(s | (1 << nxt), nxt) + adj[v][nxt]);
    }

    return ret;
}

ld dist(pair<ld, ld>& a, pair<ld, ld>& b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second-b.second)*(a.second-b.second));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    vector<pair<ld, ld>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = dist(arr[i], arr[j]);
        }
    }
    fill(&dp[0][0], &dp[(1<<16)-1][16], -1);
    cout.precision(10);
    cout << fixed;
    // 0번 정점에서 시작
    cout << dfs(1, 0);
    
    return 0;
}