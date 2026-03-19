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
vector<ll> dp;
vector<pil> arr;

void solve(int CASE = -1) {
    cin >> n;
    arr.resize(n + 1);
    dp.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), [](pil& a, pil& b) {
        if (a.first < b.first) return true;
        else if (a.first == b.first && a.second < b.second) return true;
        else return false;
        });
    // dp[k] = k번째 날 때 얻을 수 있는 최댓값
    for (int j = 1; j <= n; j++) {
        // k번째 수 다음에 arr[i] 넣기
        for (int i = n; i >= 1; i--) {
            dp[i] = max(dp[i], dp[i - 1] + arr[j].second + arr[j].first * (i - 1));
        }

    }

    for (int i = 1; i <= n; i++)
        cout << dp[i] << "\n";
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