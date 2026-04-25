#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ranges>
#include <numeric>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int n;
int mx[3][2];
int mn[3][2];

void solve(int CASE = -1) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mx[j][i % 2];
            mn[j][i % 2] = mx[j][i % 2];
        }

        mx[0][i % 2] += max(mx[1][(i + 1) % 2], mx[0][(i + 1) % 2]);
        mn[0][i % 2] += min(mn[1][(i + 1) % 2], mn[0][(i + 1) % 2]);

        mx[1][i % 2] += max(max(mx[1][(i + 1) % 2], mx[0][(i + 1) % 2]), mx[2][(i + 1) % 2]);
        mn[1][i % 2] += min(min(mn[1][(i + 1) % 2], mn[0][(i + 1) % 2]), mn[2][(i + 1) % 2]);

        mx[2][i % 2] += max(mx[1][(i + 1) % 2], mx[2][(i + 1) % 2]);
        mn[2][i % 2] += min(mn[1][(i + 1) % 2], mn[2][(i + 1) % 2]);
    }

    cout << max(max(mx[0][n % 2], mx[1][n % 2]), mx[2][n % 2]) << " ";
    cout << min(min(mn[0][n % 2], mn[1][n % 2]), mn[2][n % 2]);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}