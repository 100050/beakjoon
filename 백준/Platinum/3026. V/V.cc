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

const ll MOD = 1000000007;
//const ll MOD = 10007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int used;
ll a, b, x, n, m;
// dp[pos][mod]
ll dp[13][(int)1e5][2][2];

ll dfs(int pos, int mod, bool same, bool zero, int arr[]) {
    if (pos == -1) {
        if (mod % x == 0 && !zero) return 1;
        else return 0;
    }

    ll& ret = dp[pos][mod][same][zero];
    //cout << pos << " " << same << " " <<  zero << " " << mod << " " << ret << "\n";
    if (ret != -1) return ret;

    ret = 0;
    // 아직 수를 구성하지 않았을 때
    if (zero && pos != 0) {
        ret += dfs(pos - 1, 0, same && arr[pos] == 0, zero, arr);
    }
    for (int i = zero; i < 10; i++) {
        if ((used & (1 << i)) == 0) continue;
        
        ll r;
        if (same) {
            if (i < arr[pos]) {
                r = dfs(pos - 1, (mod * 10 + i) % x, false, zero && !i, arr);
                ret = ret + r;
            }
            else if (i == arr[pos]) {
                r = dfs(pos - 1, (mod * 10 + i) % x, true, zero && !i, arr);
                ret = ret + r;
            }
        }
        else {
            r = dfs(pos - 1, (mod * 10 + i) % x, false, zero && !i, arr);
            ret = ret + r;
        }
        //cout << pos << " " << i << " " << ret << "\n";
    }

    return ret;
}

void solve(int CASE = -1) {
    string t;
    int arr[13] = { 0, }, arr2[13] = { 0, };
    ll res;

    cin >> x >> a >> b;
    cin >> t;
    for (char c : t)
        used |= (1 << (int)(c - '0'));

    if (x <= 1e5) {
        t = to_string(a - 1);
        n = t.length();
        for (int i = 0; i < n; i++) {
            arr[n - i - 1] = t[i] - '0';
        }
        t = to_string(b);
        m = t.length();
        for (int i = 0; i < m; i++) {
            arr2[m - i - 1] = t[i] - '0';
        }

        memset(dp, -1, sizeof(dp));
        res = dfs(12, 0, true, true, arr2);
        memset(dp, -1, sizeof(dp));
        res -= dfs(12, 0, true, true, arr);
    }
    else {
        ll s = 0;
        while (s < a) {
            s += x;
        }
        res = 0;
        for (ll i = s; i <= b; i += x) {
            // i에 있는 숫자들이 used에 전부 있는지 확인 후 더하기
            ll t = i;
            bool flag = true;
            while (t) {
                if ((used & (1 << (t % 10))) == 0) {
                    flag = false;
                }
                t /= 10;
            }

            if (flag) res++;
        }
    }

    cout << res << "\n";
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