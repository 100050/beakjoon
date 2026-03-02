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

int n, m;
vector<bool> b(10);

bool possible(int x) {
    if (x == 0) return !b[x];
    while (x) {
        if (b[x % 10]) return false;
        x /= 10;
    }
    return true;
}

int count(int x) {
    if (x == 0) return 1;
    int c = 0;
    while (x) {
        c++;
        x /= 10;
    }
    return c;
}

void solve(int CASE = -1) {

    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int j;
        cin >> j;
        b[j] = true;
    }

    int ans = INF<int>;
    ans = min(ans, abs(100 - n));
    for (int i = 0; i <= 1'000'000; i++) {
        if (!possible(i)) continue;

        ans = min(ans, abs(i - n)+count(i));
    }

    cout << ans;
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