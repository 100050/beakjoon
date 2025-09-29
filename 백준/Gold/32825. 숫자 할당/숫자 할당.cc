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

pii ntc[13] = {
    make_pair(2, 2),
    make_pair(2, 3),
    make_pair(2, 4),
    make_pair(2, 5),
    make_pair(3, 2),
    make_pair(3, 3),
    make_pair(3, 4),
    make_pair(3, 5),
    make_pair(4, 2),
    make_pair(4, 3),
    make_pair(4, 4),
    make_pair(5, 2),
    make_pair(5, 3),
};
int num[6][6] = { 0, };
int n[6] = { 0, 0, 5, 5, 4, 3 };

int dfs(int d, int s) {

    if (d == 13) {
        // 2^0을 제외한 2^1~2^13승까지의 합
        return s == ((1<<14)-1-1);
    }

    int ret = 0;
    pii& p = ntc[d];
    if (n[p.second] == p.first) {
        int t = num[1][p.second];
        if (t > 13 || t == 0 || ((s & (1 << t)) != 0)) return 0;

        num[p.first][1] -= t;
        num[1][p.second] -= t;

        if (num[p.first][1] >= 0 && num[1][p.second] >= 0)
            ret += dfs(d + 1, s | (1 << t));

        num[p.first][1] += t;
        num[1][p.second] += t;

        return ret;
    }

    if (n[p.first] == p.second) {
        int t = num[p.first][1];
        if (t > 13 || t == 0 || ((s & (1 << t)) != 0)) return 0;

        num[p.first][1] -= t;
        num[1][p.second] -= t;

        if (num[p.first][1] >= 0 && num[1][p.second] >= 0)
            ret += dfs(d + 1, s | (1 << t));

        num[p.first][1] += t;
        num[1][p.second] += t;

        return ret;
    }

    int end = min(num[p.first][1], 13);
    end = min(end, num[1][p.second]);
    for (int i = 1; i <= end; i++) {
        if ((s & (1 << i)) != 0) continue;

        num[p.first][1] -= i;
        num[1][p.second] -= i;

        if (num[p.first][1] >= 0 && num[1][p.second] >= 0)
            ret += dfs(d + 1, s | (1 << i));
        
        num[p.first][1] += i;
        num[1][p.second] += i;
    }

    return ret;
}

void solve(int CASE = -1) {
    for (int i = 2; i <= 5; i++) {
        cin >> num[1][i];
    }
    for (int i = 2; i <= 5; i++) {
        cin >> num[i][1];
    }
    
    cout << dfs(0, 0);
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