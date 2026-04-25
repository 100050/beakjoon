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
    ll p, q, n, r;
    vector<ll> arr;

    cin >> p >> q >> n;

    if (n * q < p) {
        ll i = n;
        if (i >= 36) {
            cout << (char)(i - 36 + 'a');
        }
        else if (i >= 10) {
            cout << (char)(i - 10 + 'A');
        }
        else {
            cout << i;
        }
        return;
    }

    while (true) {
        r = n % p;
        arr.push_back(r);

        n /= p;
        if (n * q < p) break;
        n *= q;
    }
    if (n != 0)
        arr.push_back(n * q);

    for (ll i : arr | views::reverse) {
        if (i >= 36) {
            cout << (char)(i - 36 + 'a');
        }
        else if (i >= 10) {
            cout << (char)(i - 10 + 'A');
        }
        else {
            cout << i;
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