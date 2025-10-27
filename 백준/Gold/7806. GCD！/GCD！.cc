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

ll prime[31624];

void solve(int CASE = -1) {
    ll n, k;

    // 에라토스테네스의 체
    for (ll i = 2; i <= 31623; i++) {
        if (prime[i] != 0) continue;
        if (i * i > 31623) continue;
        for (ll j = i * i; j <= 31623; j += i) {
            prime[j] = i;
        }
    }

    while (cin >> n) {
        cin >> k;

        // m: k의 소인수와 개수
        vector<pil> m;
        // k 소인수 분해
        for (ll i = 2; i * i <= k; i++) {
            if (prime[i] != 0) continue;
            ll x = 0;
            while (k % i == 0) {
                x++;
                k /= i;
            }
            if (x != 0)
                m.push_back(make_pair(i, x));
        }
        if (k > 1) m.push_back(make_pair(k, 1));

        ll res = 1;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            // arr[i]의 소인수 수 세기, 최대공약수 찾기
            ll ee = 0;
            for (ll x = iter->first; x <= n; x *= iter->first) {
                ee += n / x;
            }
            ll e = min(ee, iter->second);

            res *= pow(iter->first, e);
        }

        cout << res << "\n";
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