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

ll sieve[1000001];
ll s[1000001];
void solve(int CASE = -1) {
    for (ll i = 2; i <= 1000000; i++) {
        //if (sieve[i] != 0) continue;
        
        for (ll j = i; j <= 1000000; j+= i) {
            sieve[j] += i;
        }
    }
    for (ll i = 2; i <= 1000000; i++)
        s[i] = s[i - 1] + sieve[i];

    int t;

    cin >> t;
    while (t--) {
        ll n;

        cin >> n;

        cout << s[n] + n << "\n";
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