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

int r, c, mx = 0;
vector<vector<char>> arr;

void dfs(int y, int x, array<bool, 26>& alphabet, int count) {
    mx = max(mx, count);

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (0 <= ny && ny < r && 0 <= nx && nx < c && !alphabet[arr[ny][nx]-'A']) {
            alphabet[arr[ny][nx] - 'A'] = true;
            dfs(ny, nx, alphabet, count + 1);
            alphabet[arr[ny][nx] - 'A'] = false;
        }
    }
}

void solve(int CASE = -1) {

    cin >> r >> c;
    arr.resize(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    array<bool, 26> alphabet = { 0, };
    alphabet[arr[0][0] - 'A'] = true;

    dfs(0, 0, alphabet, 1);

    cout << mx << "\n";
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