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


void solve(int CASE = -1) {
    int n;
    vector<ll> arr, m, p;

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    array<ll, 3> res;
    ll mn = INF<ll>;
    for (int i = 0; i < n; i++) {
        for (int j = i + 2; j < n; j++) {
            ll s = arr[i] + arr[j];
            int idx = upper_bound(arr.begin() + i + 1, arr.begin() + j, -s) - arr.begin();
            if (idx - 1 > i) idx--;

            if (mn > abs(s + arr[idx])) {
                mn = abs(s + arr[idx]);
                res[0] = arr[i]; res[1] = arr[idx]; res[2] = arr[j];
            }
            if (idx + 1 < j && mn > abs(s + arr[idx+1])) {
                mn = abs(s + arr[idx+1]);
                res[0] = arr[i]; res[1] = arr[idx+1]; res[2] = arr[j];
            }
        }
    }

    cout << res[0] << " " << res[1] << " " << res[2];
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