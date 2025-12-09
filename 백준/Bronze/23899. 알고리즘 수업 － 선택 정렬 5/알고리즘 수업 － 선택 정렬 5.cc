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
    int n;
    vector<int> arr;
    vector<int> arr2;

    cin >> n;
    arr.resize(n);
    arr2.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    for (int i = n-1; i >= 1; i--) {
        // arr2[i]의 값과 arr에서의 위치
        
        int mx = 0, idx = -1;
        for (int j = 0; j <= i; j++) {
            if (mx < arr[j]) {
                mx = arr[j];
                idx = j;
            }
        }

        
        swap(arr[idx], arr[i]);
        
        if (arr[i] > arr2[i]) {
            swap(arr2[idx], arr2[i]);
        }

        if (arr[i] != arr2[i]) {
            cout << 0;
            return;
        }
    }

    cout << 1;
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