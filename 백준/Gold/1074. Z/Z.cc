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
ll n, c, r;

void dfs(ll i, ll j, ll ii, ll jj, ll res, ll n) {

    ll ti = (i + ii) / 2;
    ll tj = (j + jj) / 2;
    //cout << ti << " " << tj << " " << n << endl;
    if (n == -1) {
        if (ti == c && tj == r) {
            cout << res;
        }
        return;
    }
    
    if (c <= ti && r <= tj)
        dfs(i, j, ti, tj, res, n-1); // 좌상
    else if (c <= ti && r > tj)
        dfs(i, tj+1, ti, jj, res + (1 << n) * (1 << n), n - 1); // 우상
    else if (c > ti && r <= tj)
        dfs(ti+1, j, ii, tj, res + 2 * (1 << n) * (1 << n), n - 1); // 좌하
    else
        dfs(ti+1, tj+1, ii, jj, res + 3 * (1 << n) * (1 << n), n - 1); // 우하
}

void solve() {
    
    cin >> n >> c >> r;

    dfs(0, 0, (1<<n) - 1, (1<<n) - 1, 0, n-1);
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