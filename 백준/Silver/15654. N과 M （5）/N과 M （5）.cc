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

vector<int> arr;

void dfs(int vis[], vector<int> res, int d, int m) {
    if (d == m) {
        for (int r : res) {
            cout << r << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        if (vis[i] == 1) continue;
        vis[i] = 1;
        res.push_back(arr[i]);
        dfs(vis, res, d + 1, m);
        res.pop_back();
        vis[i] = 0;
    }
}

void solve() {
    int n, m;
    int a;
    int vis[8] = { 0, };

    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    vector<int> res;
    dfs(vis, res, 0, m);
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