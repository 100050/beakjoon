#include <bits/stdc++.h>
using namespace std;

int dp[1001];
vector<int> arr, parent;

int dfs(int d) {
    int& ret = dp[d];
    if (ret != -1) return ret;

    if (d == 0) return ret = 1;

    ret = 1;
    for (int i = 0; i < d; i++) {
        if (arr[d] > arr[i] && ret < dfs(i) + 1) {
            ret = dfs(i) + 1;
            parent[d] = i;
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    arr.resize(n); parent.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    fill(&dp[0], &dp[1000], -1);
    fill(&parent[0], &parent[n], -1);

    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, dfs(i));
    }
    cout << res << "\n";
    
    // 역추적
    vector<int> lis;
    int i;
    for (i = n - 1; i >= 0; i--) {
        if (res == dp[i]) break;
    }
    while (i != -1) {
        lis.push_back(arr[i]);
        i = parent[i];
    }
    
    reverse(lis.begin(), lis.end());
    for (int x : lis) {
        cout << x << " ";
    }

    return 0;
}