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

bool arr[1001][1001] = { 0, };
int tmp[101] = { 0, };

void dfs(int d, int n) {
    if (d > n) return;

    for (int i = 1; i <= tmp[d]; i++) {
        arr[(n - d) * 2 + i][(n - d) * 2 + 1] = true;
        arr[(n - d) * 2 + 1][(n - d) * 2 + i] = true;
        arr[(n - d) * 2 + i][(n - d) * 2 + tmp[d]] = true;
        arr[(n - d) * 2 + tmp[d]][(n - d) * 2 + i] = true;
    }

    dfs(d + 1, n);
}

void solve(int CASE = -1) {
    int n;

    cin >> n;

    tmp[0] = -3;
    for (int i = 1; i <= n; i++) {
        tmp[i] = tmp[i - 1] + 4;
    }

    dfs(1, n);

    for (int i = 1; i <= tmp[n]; i++) {
        for (int j = 1; j <= tmp[n]; j++) {
            cout << (arr[i][j] ? "*" : " ");
        }
        cout << "\n";
    }
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