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
#include <unordered_map>
#include <queue>
#include <stack>
#include <ranges>
#include <numeric>
#include <cstring>
#include <bit>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

constexpr ll MOD = 1000000007;
//constexpr ll MOD = 1000000000;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

void solve(int CASE = -1) {
    ll n, day = 0, na = 0, nb = 0, nc = 0;
    bool flag = false;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b, c, p;
        cin >> a >> b >> c >> p;
        if (flag) continue;

        if (na < a) day += a - na, na = a;
        if (nb < b) day += b - nb, nb = b;
        if (nc < c) day += c - nc, nc = c;
    
        if (p <= day) flag = true;
        else day++;
    }

    cout << (flag ? "NO" : "YES") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    //pre();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}