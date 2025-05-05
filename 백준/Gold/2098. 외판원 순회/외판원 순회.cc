#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

int n;
int arr[21][21];
int dp[17][(1 << 17)+1];

int dfs(int v, int bit) {
    if (dp[v][bit] != 0)
        return dp[v][bit];
            //cout << bit << " " << v << " " << d << "\n";

    if (bit == 0) {
        if (arr[v][0] != 0) {
            return arr[v][0];
        }
        return  1000001*17; 
    }
    int nm = 1000001 * 17;
    for (int i = 0; i < n; i++) {
        if ((bit & (1 << i)) && arr[v][i] != 0) {
            nm = min(nm, dfs(i, bit & ~(1 << i)) + arr[v][i]);
        }
    }
    dp[v][bit] = nm;
    return dp[v][bit];
}

void solve() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int res = dfs(0, ((1 << n) - 1)-1);

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}