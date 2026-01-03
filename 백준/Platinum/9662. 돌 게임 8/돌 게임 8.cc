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

int dp[(1 << 23) + 1];

void solve(int CASE = -1) {
    int m, k;
    vector<int> arr;

    cin >> m >> k;
    arr.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }


    int state = 0;
    for (int i = 0; i <= 1 << 23; i++) {
        bool flag = false;
        for (int j = 0; j < k; j++) {
            if (i - arr[j] < 0) break;

            if ((state & (1 << (22 - arr[j]))) == 0) {
                flag = true;
                break;
            }
        }
        state >>= 1;
        if (flag) state = state | (1 << 21);
        dp[i] = state;
    }
    int a = 22, b = 22;
    while (true) {
        a++;
        b += 2;
        if (dp[a] == dp[b]) break;
    }

    a = 22;
    while (dp[a] != dp[b]) {
        a++;
        b++;
    }
    // a: 사이클 시작
    b = a;
    unordered_set<int> s;
    while (s.find(dp[b]) == s.end()) {
        s.insert(dp[b]);

        b++;
    }
    b--;
    //cout << a << " " << b << "\n";
    // b: 사이클 끝

    // 1~a-1
    int res = 0;
    for (int i = 1; i <= min(a-1, m); i++) {
        if ((dp[i] & (1 << 21)) == 0) {
            res++;
        }
    }
    //cout << res << "\n";
    // a~b까지 n개
    int t = 0;
    for (int i = a; i <= b; i++) {
        if ((dp[i] & (1 << 21)) == 0)
            t++;
    }
    //cout << t << " " << (m-a+1) / (b - a + 1) << "\n";
    if (m - a + 1 >= 0)
        res += ((m - a + 1) / (b - a + 1)) * t;
    
    // n*(b-a) ~ m
    for (int i = a; i <= m - ((m-a+1) / (b - a + 1)) * (b - a + 1); i++) {
        if ((dp[i] & (1 << 21)) == 0) {
            res++;
        }
    }

    cout << res;
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