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
constexpr T INF = numeric_limits<T>::max();
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

int n;
vector<int> arr;
int dp[1001];

int dfs(int n) {
    if (n == 0) {
        return 0;
    }

    int& ret = dp[n];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 1; i <= n; i++) {
        ret = max(ret, dfs(n - i) + arr[i]);
    }

    return ret;
}

void solve(int CASE = -1) {
    
    fill(&dp[0], &dp[1001], -1);
    cin >> n;
    arr.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cout << dfs(n);
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