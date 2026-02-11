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

vector<int> arr, res, check;

void solve(int CASE = -1) {
    int n;
    
    cin >> n;
    arr.resize(n);
    res.resize(n);
    check.resize(1'000'001, -1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        check[arr[i]] = i;
    }


    for (int i = 0; i < n; i++) {
        for (int j = arr[i] * 2; j <= 1'000'000; j += arr[i]) {
            if (check[j] != -1) {
                res[check[j]]--;
                res[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
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