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
#include <bit>
using namespace std;

using ll = long long;
using ull = unsigned long long;
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

ull power(ull a, ull b, ull mod = MOD) {
    ull res = 1;
    while (b) {
        if (b & 1) res = (a * res) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }

    return res % mod;
}

bool millerRabin(const ull& n, ull& p) {
    ull s = 0, d = n - 1;

    while (d % 2 == 0) s++, d /= 2;

    ull x = power(p, d, n);
    if (x == 1 || x + 1 == n) return true;

    for (ull i = 0; i < s - 1; i++) {
        x = power(x, 2, n);
        if (x + 1 == n) return true;
    }

    return false;
}

bool isPrime(const ull& n) {
    array<ull, 13> base = { 2,3,5,7,11,13,17,19,23,29,31,37,41 };

    for (ull& p : base) if (p == n) return true;
    if (n == 1 || n % 2 == 0) return  true;

    for (ull& p : base)
        if (!millerRabin(n, p)) return false;
    
    return true;
}

void solve(int CASE = -1) {
    int n, res = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        ull A;
        cin >> A;

        if (isPrime(2uLL * A + 1uLL)) res++;
    }

    cout << res;
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