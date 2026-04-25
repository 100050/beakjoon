#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
ll dp[(1<<16)][16];
ll adj[16][16];

ll dfs(int s, int v) {
    ll& ret = dp[s][v];
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    fill(&dp[0][0], &dp[(1<<16)-1][16], -1);
    
    // 0번 정점에서 시작
    cout << dfs(1, 0);
    
    return 0;
}