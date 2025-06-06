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

vector<int> arr[1001];
int arr2[1001];

void dfs(int node, int idx) {
    arr2[node] = idx;
    //cout << 1;
    for (int next : arr[node]) {
        if (arr2[next] != 0) continue;
        dfs(next, idx);
    }
}

void solve() {
    int n, m;
    int u, v;
    int idx;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    idx = 1;
    for (int i = 1; i <= n; i++) {
        if (arr2[i] != 0) continue;
        dfs(i, idx);
        idx++;
    }

    cout << (idx - 1);
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