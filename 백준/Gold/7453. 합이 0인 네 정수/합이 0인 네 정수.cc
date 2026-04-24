#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <ranges>
#include <numeric>
#include <cstring>
#include <bit>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

constexpr ll MOD = 1000000007;
//constexpr ll MOD = 1000000000;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

void solve(int CASE = -1) {
    int n;
    
    cin >> n;
    array<vector<int>, 4> arr{vector<int>(n), vector<int>(n), vector<int>(n) , vector<int>(n) };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[j][i];
        }
    }

    vector<int> s, s2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s2.push_back(- arr[0][i] - arr[1][j]);
            s.push_back(arr[2][i] + arr[3][j]);
        }
    }

    ll res = 0;

    sort(s2.begin(), s2.end());
    for (int i = 0; i < s.size(); i++) {
        auto iter = lower_bound(s2.begin(), s2.end(), s[i]);
        auto iter2 = upper_bound(s2.begin(), s2.end(), s[i]);

        if (iter != s2.end() && *iter == s[i]) res += iter2 - iter;
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