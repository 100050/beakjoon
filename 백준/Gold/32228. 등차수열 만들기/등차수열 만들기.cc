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

ll phi(ll n) {
	ll result = n;

	for (ll p = 2; p * p <= n; p++)
	{
		if (n % p == 0) {
			result -= result / p;
			while (n % p == 0)
				n /= p;
		}
	}

	if (n > 1)
		result -= result / n;

	return result;
}

void solve(int CASE = -1) {
    ll n, m;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
    }

    cout << phi(m);
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