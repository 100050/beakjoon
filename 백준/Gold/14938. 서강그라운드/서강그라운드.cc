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

//const ll MOD = 1000000007;
const ll MOD = 9901;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int n, m, r;
ll items[101] = { 0, };
ll adj[101][101] = { 0, };

void solve(int CASE = -1) {
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        cin >> items[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) adj[i][j] = 0;
            else adj[i][j] = numeric_limits<int>::max();
        }
    }
    for (int i = 0; i < r; i++) {
        int a, b, l;

        cin >> a >> b >> l;
        adj[a][b] = l;
        adj[b][a] = l;
    }

    // 플로이드 워셜
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
            }
        }
    }

    // 얻을 수 있는 최대 아이템 개수 찾기
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        // i정점에 낙하했을 때 얻을 수 있는 아이템 수
        int item = 0;
        for (int j = 1; j <= n; j++) {
            if (adj[i][j] <= m) item += items[j];
        }

        mx = max(mx, item);
    }

    cout << mx;
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