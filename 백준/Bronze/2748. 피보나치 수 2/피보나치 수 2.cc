#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[91];

ll dfs(int n) {
    ll& ret = dp[n];
    if (ret != -1) return ret;

    if (n < 2) return ret = n;
    else return ret = dfs(n - 1) + dfs(n - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    fill(&dp[0], &dp[91], -1);

    cout << dfs(n);

    return 0;
}