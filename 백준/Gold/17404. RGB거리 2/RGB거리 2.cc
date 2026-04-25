#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

int n;
vector<int> arr[3];
int dp[3][3][1001];

int dfs(int v, int d, int r) {
    if (dp[r][v][d] != 0) {
        return dp[r][v][d];
    }



    if (d == n - 1) {
        if (r == v) return 1001;
        dp[r][v][d] = arr[v][d];

        return dp[r][v][d];
    }

    dp[r][v][d] = arr[v][d];
    int mn = 1000*1000+1;
    for (int i = 0; i < 3; i++) {
        if (i != v)
            mn = min(mn, dfs(i, d + 1, r));
    }
    dp[r][v][d] += mn;
    return dp[r][v][d];
}

void solve() {
    int a, b, c;


    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        arr[0].push_back(a);
        arr[1].push_back(b);
        arr[2].push_back(c);
    }

    int mn = dfs(0, 0, 0);
    mn = min(mn, dfs(1, 0, 1));
    mn = min(mn, dfs(2, 0, 2));

    cout << mn;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}