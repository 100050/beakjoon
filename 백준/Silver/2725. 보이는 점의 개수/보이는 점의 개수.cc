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
    int c;
    int arr[1001] = { 0, 3, };

    // arr 전처리, arr[n] = 0 <= x, y <= n에 대하여 0,0에서 보이는 점의 개수
    for (int i = 2; i <= 1000; i++) {
        for (int j = 1; j <= i - 1; j++) {
            if (gcd(i, j) == 1) {
                arr[i]++;
            }
        }
        arr[i] = arr[i] * 2 + arr[i - 1];
    }

    cin >> c;
    while (c--) {
        int n;

        cin >> n;
        cout << arr[n] << "\n";
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