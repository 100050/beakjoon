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

using ll = unsigned long long;
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

bool prime[500001];
int color[500001];

void solve(int CASE = -1) {
    ll n;
    int res = 1;

    cin >> n;

    // 에라토스테네스의 체
    color[1] = 1;
    for (ll i = 2; i <= n; i++) {
        if (prime[i] != 0) continue;

        color[i] = 1;
        if (i * i > n) continue;
        for (ll j = i * i; j <= n; j += i) {
            prime[j] = i;
            if (color[j] == 0) color[j] = color[j - i] + 1;
            res = max(res, color[j]);
        }
    }

    cout << res << "\n";
    for (ll i = 1; i <= n; i++) {
        cout << color[i] << " ";
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