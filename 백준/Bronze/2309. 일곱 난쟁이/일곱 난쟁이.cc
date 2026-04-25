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
    vector<pii> arr(9);
    int s = 0;
    for (int i = 0; i < 9; i++) {
        cin >> arr[i].first;
        s += arr[i].first;
    }

    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (s - arr[i].first - arr[j].first == 100) {
                arr[i].second = 1; arr[j].second = 1;
                i = 10; break;
            }
        }
    }

    sort(arr.begin(), arr.end());
    for (int i = 0; i < 9; i++) {
        if (arr[i].second) continue;
        cout << arr[i].first << "\n";
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