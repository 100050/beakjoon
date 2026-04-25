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
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

void solve(int CASE = -1) {
    int n;
    vector<int> arr;

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int idx1 = 0, idx2 = n - 1, v = 2'000'000'001;
    for (int i = 0; i < n - 1; i++) {
        int begin = i + 1, end = n - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            int s = arr[i] + arr[mid];

            if (v > abs(s)) {
                v = abs(s);
                idx1 = i; idx2 = mid;
            }

            if (s < 0) {
                begin = mid + 1;
            }
            else if (s > 0) {
                end = mid - 1;
            }
            else {
                break;
            }
        }

    }

    cout << arr[idx1] << " " << arr[idx2] << "\n";
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