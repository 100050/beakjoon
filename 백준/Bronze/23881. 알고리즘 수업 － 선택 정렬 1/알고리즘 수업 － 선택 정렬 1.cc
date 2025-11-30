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

void solve(int CASE = -1) {
    int n, k;
    vector<int> arr;

    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int c = 0;
    for (int i = 0; i < n; i++) {
        int idx = -1, mx = 0;

        for (int j = 0; j < n - i; j++) {
            if (mx < arr[j]) {
                mx = arr[j];
                idx = j;
            }
        }

        if (idx != n - i - 1) {
            c++;
            swap(arr[idx], arr[n - i - 1]);
            if (c == k) {
                cout << arr[idx] << " " << arr[n - i - 1];
                return;
            }

        }
    }

    cout << -1;

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