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

vector<int> arr;
int dp[2001][2001];

int is_palindrome(int s, int e) {
    if (s >= e) {
        return 1;
    }
    
    int& ret = dp[s][e];
    if (ret != -1) return ret;

    return ret = is_palindrome(s + 1, e - 1) & (arr[s] == arr[e]);
}

void solve(int CASE = -1) {
    int n;

    cin >> n;
    arr.resize(n+1);
    fill(&dp[0][0], &dp[2000][2001], -1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int m;

    cin >> m;
    while (m--) {
        int s, e;
        cin >> s >> e;

        cout << is_palindrome(s, e) << "\n";
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