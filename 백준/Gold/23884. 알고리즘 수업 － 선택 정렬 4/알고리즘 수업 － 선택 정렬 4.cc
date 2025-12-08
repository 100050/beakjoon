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
    vector<pii> arr2;

    cin >> n >> k;
    arr.resize(n);
    arr2.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr2[i] = make_pair(arr[i], i);
    }

    sort(arr2.begin(), arr2.end());

    int num = 0;
    for (int i = n-1; i >= 1; i--) {
        // arr2[i]의 값과 arr에서의 위치
        auto& [val, idx] = arr2[i];
        if (idx == i) continue;
        
        int idx2 = lower_bound(arr2.begin(), arr2.end(), make_pair(arr[i], 0)) - arr2.begin();

        arr2[idx2].second = idx;
        num++;
        swap(arr[idx], arr[i]);
        if (num == k) {
            for (int j = 0; j < n; j++) {
                cout << arr[j] << " ";
            }
            break;
        }
    }

    if (num != k) {
        cout << -1;
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