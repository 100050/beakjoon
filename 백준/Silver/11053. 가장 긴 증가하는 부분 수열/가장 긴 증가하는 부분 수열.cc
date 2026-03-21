#include <bits/stdc++.h>
using namespace std;

int dp[1001];
vector<int> arr;

int dfs(int d) {
    int& ret = dp[d];
    if (ret != -1) return ret;

    if (d == 0) return ret = 1;

    ret = 1;
    for (int i = 0; i < d; i++) {
        if (arr[d] > arr[i])
            ret = max(ret, dfs(i) + 1);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    fill(&dp[0], &dp[1000], -1);

    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, dfs(i));
    }
    cout << res;

    return 0;
}