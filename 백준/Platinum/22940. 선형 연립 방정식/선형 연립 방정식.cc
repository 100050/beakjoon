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
#include <queue>
#include <stack>
#include <ranges>
#include <numeric>
#include <cstring>
#include <bit>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

constexpr ll MOD = 1000000007;
//constexpr ll MOD = 10007;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

int n;
array<array<ld, 7>, 7> arr;

void solve(int CASE = -1) {
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        ld x = arr[i][i];
        for (int j = 0; j < n + 1; j++) {
            arr[i][j] /= x;
        }

        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            ld x = arr[j][i];
            for (int k = 0; k < n + 1; k++) {
                arr[j][k] -= x * arr[i][k];
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << arr[i][n] << " ";
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