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

int mid;
bool arr[3 * 1024][3 * 1024 * 2 - 1] = { 0, };

void dfs(int n, int h, int w) {
    if (n == 3) {
        h--;
        arr[h - 2][w + 2] = true;
        arr[h - 1][w + 1] = arr[h - 1][w + 3] = true;
        arr[h][w] = arr[h][w + 1] = arr[h][w + 2] = arr[h][w + 3] = arr[h][w + 4] = true;
        //cout << "  *  ";
        //
        //cout << " * * ";
        //
        //cout << "*****";
        
        return;
    }

    dfs(n / 2, h - n / 2, w + n / 2); // 위
    dfs(n / 2, h, w); // 왼쪽
    dfs(n / 2, h, n + w); // 오른쪽
}

void solve(int CASE = -1) {
    int n;

    cin >> n;
    mid = n - 1;

    dfs(n, n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            cout << (arr[i][j] ? '*' : ' ');
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