#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
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

struct pa {
    int first, second;
};

bool c(pa& a, pa& b) {
    return a.first * b.second < a.second * b.first;
}
int n, k, idx = 0;
pa arr[3800230];

void solve(int CASE = -1) {
    cin >> n >> k;

    if (n == 1) [[unlikely]] {
        if (k == 1)
            cout << "0 1";
        else if (k == 2)
            cout << "1 1";
        return;
    }

    arr[idx++] = { 0, 1 };
    arr[idx++] = { 1, 2 };
    for (int i = 3; i <= n; i++) {
        for (int j = ((i + 1) >> 1) - 1; j >= 1; j--) {
            if (j != 1 && gcd(i, j) != 1) continue; // 기약분수가 아니라면
            arr[idx++] = { j, i };
        }
    }

    //cout << idx << "\n";
    if (idx >= k) {
        nth_element(arr, arr + k - 1, arr + idx, c);
        cout << arr[k - 1].first << " " << arr[k - 1].second;
    }
    else {
        int kk = 2 * idx - k;
        nth_element(arr, arr + kk - 1, arr + idx, c);

        cout << arr[kk - 1].second - arr[kk - 1].first << " " << arr[kk - 1].second;
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