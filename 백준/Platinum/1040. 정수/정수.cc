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
#include <cstring>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

//const ll MOD = 1000000007;
const ll MOD = 10007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

ll n, k;
string t;
int arr[19];
// dp[used][num][isBig][zero]
ll dp[20][1 << 10][2], ten[19];

ll dfs(int pos, int used, bool isBig, bool zero) {
    ll& ret = dp[pos + 1][used][isBig];
    if (ret != -1) return ret;

    if (pos == -1) {
        //cout << pos << "\n";
        if (!isBig) return ret = -2;
        int cnt = 0;
        for (int i = 0; i < 10; i++) {
            if (used & (1 << i)) cnt++;
        }
        if (cnt == k) return ret = 0;
        else return ret = -2;
    }


    if (zero && arr[pos] == 0) {
        ll r = dfs(pos - 1, used, isBig, zero);
        //cout << pos << " " << r << "\n";
        if (r >= 0)
            return ret = r;
    }

    //cout << pos << " " << arr[pos] << " " << used << " " << ret << "\n";
    for (int i = (isBig ? 0 : arr[pos]); i < 10; i++) {
        if (zero && i == 0) continue;
        ll r = dfs(pos - 1, used | (1 << i), isBig || (i > arr[pos]), zero && !i);
        if (r >= 0) {
            //cout << pos << " " << r << " " << i << " " << r + i * ten[pos] << "\n";
            return ret = r + i * ten[pos];
        }
    }

    return ret = -2;
}

void solve(int CASE = -1) {
    cin >> n >> k;

    t = to_string(n - 1);
    n = t.length();
    for (int i = 0; i < n; i++) {
        arr[n - i - 1] = t[i] - '0';
    }
    for (int i = n; i <= 18; i++) {
        arr[i] = 0;
    }

    ten[0] = 1;
    for (int i = 1; i <= 18; i++) {
        ten[i] = ten[i - 1] * 10;
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(18, 0, false, true);
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