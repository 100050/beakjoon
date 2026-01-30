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

int dp[2][100*1000+1]; // i번째까지 고려, j원까지 사용했을 때 최대 고객 수

void solve(int CASE = -1) {
    int c, n;
    vector<pii> arr;

    cin >> c >> n;
    arr.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 100*c; j++) {
            dp[i % 2][j] = max(dp[i % 2][j], dp[(i + 1) % 2][j]);
            if (j >= arr[i].first) {
                dp[i%2][j] = max(dp[i%2][j], dp[i%2][j - arr[i].first] + arr[i].second);
            }
        }
    }

    int i;
    for (i = 0; i <= 100 * c; i++) {
        if (dp[n%2][i] >= c) break;
    }

    cout << i;
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