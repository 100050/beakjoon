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
    ll n, k, s = 0, c = 0;
    map<ll, ll> m;

    cin >> n >> k;
    m[0] = 1;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        s += t;

        if (m.find(s - k) != m.end()) {
            c += m[s-k];
        }

        if (m.find(s) != m.end()) {
            m[s]++;
        }
        else {
            m[s] = 1;
        }
    }

    cout << c;
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