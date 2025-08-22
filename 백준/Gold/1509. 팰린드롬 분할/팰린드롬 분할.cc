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

const ll MOD = 1000000007;
//const ll MOD = 10000000;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool p[2501][2501] = { 0, };
int dp[2501] = { 0, };

void solve(int CASE = -1) {
    string s;

    cin >> s;

    // 팰린드롬 구하기
    for (int i = 0; i < s.size(); i++) p[i][i] = true;
    for (int i = 0; i < s.size() - 1; i++) p[i][i + 1] = s[i] == s[i + 1];
    for (int i = 3; i <= s.size(); i++) { // 문자열 길이가 i일 때
        for (int j = 0; j + i - 1 < s.size(); j++) {
            p[j][j + i - 1] = (s[j] == s[j + i - 1]) && (p[j + 1][j + i - 2]);
        }
    }

    // 최소 분할 구하기
    for (int i = 0; i < s.size(); i++) { // i 문자까지 봤을 때 최소 분할
        dp[i] = 2e9;
        for (int j = 0; j <= i; j++) {
            if (p[j][i]) {
                //cout << i << " " << j << " " << sum << "\n";
                dp[i] = min(dp[i], (j > 0 ? dp[j - 1] + 1 : 1));
            }
        }
        //cout << dp[i] << "\n";
    }

    cout << dp[s.size() - 1];
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