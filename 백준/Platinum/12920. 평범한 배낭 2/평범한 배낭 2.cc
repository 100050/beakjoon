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

//const ll MOD = 1000000007;
const ll MOD = 9901;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

// dp[i][j]: 1~i번까지 물건을 보고 최대 무게가 j일 때 최대 가치
ll dp[1501][10001]; 
ll n, nn, m;
vector<pil> arr; // (무게, 가치)

void solve(int CASE = -1) {

    cin >> n >> m;
    arr.push_back(make_pair(0, 0));
    for (int i = 0; i < n; i++) {
        ll v, c, k;

        cin >> v >> c >> k;

        // k개의 물건을 x=1, 2, 4, .. 개로 나눔
        ll x = 1, all = 0;
        while (k > all + x) {
            arr.push_back(make_pair(v * x, c * x));
            all += x;
            x <<= 1;
            nn++;
        }
        x = k - all; 
        arr.push_back(make_pair(v * x, c * x));
        nn++;
    }

    // 냅색 문제
    for (int i = 1; i <= nn; i++) {
        for (int j = 0; j <= m; j++) {
            if (j >= arr[i].first)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i].first] + arr[i].second);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[nn][m];
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