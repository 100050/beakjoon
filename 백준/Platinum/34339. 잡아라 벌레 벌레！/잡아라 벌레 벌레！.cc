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

int n;
vector<array<int, 101>> dp;
vector<int> arr;

void solve(int CASE = -1) {

    cin >> n;
    dp.resize(n + 1);
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // dp[i][j] = i번까지 봤고 부분 합이 j가 되도록 하기 위해 넣어야 하는 
    // 원소의 인덱스 중 가장 큰 값
    //fill(&dp[0][0], &dp[0][0] + (n + 1) * 101, INF<int>);
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 100; j++) {
            if (j == arr[i]) dp[i][j] = i;
            else if (j - arr[i] < 0) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i]]);

            //cout << i << " " << j << " " << dp[i][j] << "\n";
        }
        res += dp[i][100];
    }


    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    //pre();
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}