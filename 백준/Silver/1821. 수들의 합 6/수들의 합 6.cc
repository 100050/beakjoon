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

constexpr ll MOD = 1000000007;
//const ll MOD = 10007;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max();
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int C[11][11];
int s[11];
int n, f;

int comb(int n, int k) {
    if (k == 0 || n == k) {
        return 1;
    }

    if (C[n][k] == 0) C[n][k] = comb(n - 1, k - 1) + comb(n - 1, k);

    return C[n][k];
}

bool dfs(int d, int sum, vector<int>& arr) {
    if (sum > f) return false;

    if (d == n) {
        if (sum != f) return false;

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        return true;
    }

    for (int i = 1; i <= n; i++) {
        if (s[i]) continue;

        arr.push_back(i);
        s[i] = 1;
        if (dfs(d + 1, sum + comb(n - 1, d) * i, arr)) {
            return true;
        }
        s[i] = 0;
        arr.pop_back();
    }

    return false;
}

void solve(int CASE = -1) {
    vector<int> arr;

    cin >> n >> f;

    dfs(0, 0, arr);
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