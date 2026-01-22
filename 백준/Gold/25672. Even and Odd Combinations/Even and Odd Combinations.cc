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
    int t;

    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        vector<int> arr;
        cin >> n >> k;
        arr.resize(k);
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }

        if (k == 0) {
            cout << n << " " << k+1 << "\n";
            cout << 1 << "\n";
        }
        else if (arr[0] == 1) {
            cout << n << " " << k-1 << "\n";
            for (int i = 1; i < k; i++) {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
        else {
            cout << n << " " << k+1 << "\n";
            cout << 1 << " ";
            for (int i = 0; i < k; i++) {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
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