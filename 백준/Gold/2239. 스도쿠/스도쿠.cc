#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
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

constexpr ll MOD = 1000000007;
//const ll MOD = 10007;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

int p[9][9];
// row, column, block
bool r[9][10], c[9][10], b[9][10];

void fill_number(int y, int x, int num) {
    r[y][num] = true;
    c[x][num] = true;
    b[(y / 3) * 3 + x / 3][num] = true;
    p[y][x] = num;
}

void empty_number(int y, int x, int num) {
    r[y][num] = false;
    c[x][num] = false;
    b[(y / 3) * 3 + x / 3][num] = false;
    p[y][x] = 0;
}

bool dfs(int y, int x) {
    if (y == 9) return true;

    if (p[y][x] != 0)
        return dfs(y + (x + 1 == 9), (x + 1) % 9);
    
    for (int i = 1; i <= 9; i++) {
        if (r[y][i] || c[x][i] || b[(y / 3) * 3 + x / 3][i]) continue;

        fill_number(y, x, i);
        if (dfs(y + (x + 1 == 9), (x + 1) % 9)) return true;
        empty_number(y, x, i);

    }

    return false;
}

void solve(int CASE = -1) {
    for (int i = 0; i < 9; i++) {
        string t;
        cin >> t;
        for (int j = 0; j < 9; j++) {
            fill_number(i, j, static_cast<int>(t[j] - '0'));
        }
    }

    dfs(0, 0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << p[i][j];
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