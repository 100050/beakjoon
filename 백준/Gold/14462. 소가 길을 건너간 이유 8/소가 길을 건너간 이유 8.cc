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

int dp[1001][1001];

int dfs(int left, int right, vector<pii>& arr) {
    if (left < 0 || right < 0) {
        return 0;
    }

    int& ret = dp[left][right];
    if (ret != -1) return ret;

    ret = dfs(left - 1, right, arr);
    for (int i = right; i >= 0; i--) {
        if (abs(arr[left].first - arr[i].second) <= 4)
            ret = max(ret, dfs(left - 1, i - 1, arr) + 1);
    }

    return ret;
}

void solve(int CASE = -1) {
    int n;
    vector<pii> arr;

    cin >> n;
    arr.resize(n);
    fill(&dp[0][0], &dp[n - 1][n], -1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i].second;
    }

    cout << dfs(n - 1, n - 1, arr);
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