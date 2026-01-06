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
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int dp[2001];

int dfs(int n) {
    if (n < 0) return 0;
    else if (n == 0) return 0;
    else if (n == 1) return 1;
    else if (n == 2) return 1;
    else if (n == 3) return 1;
    else if (n == 4) return 2;
    else if (n == 5) return 2;
    
    int& ret = dp[n];
    if (ret != -1) return ret;

    vector<bool> v(n+1, false);
    for (int i = 1; i <= n; i++) {
        v[dfs(i - 3) ^ dfs(n - 2 - i)] = true;
    }

    for (int i = 0; i <= n; i++) {
        if (v[i] == false) {
            ret = i;
            break;
        }
    }

    return ret;
}

void solve(int CASE = -1) {
    int n;

    cin >> n;
    fill(&dp[0], &dp[2001], -1);

    cout << (dfs(n) == 0 ? 2 : 1);
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