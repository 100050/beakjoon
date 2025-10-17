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
    int n;
    string res;

    cin >> n;
    while (n != 0 && n != 1) {
        int r = n % (-2);

        //cout << n << " " << r << "\n";
        if (r == -1) {
            res += '1';
            n = n / (-2) + 1;
        }
        else if (r == 1) {
            res += '1';
            n = n / (-2);
        }
        else {
            res += '0';
            n = n / (-2);
        }
        
    }
    if (n == 1) res += '1';
    else res += '0';

    reverse(res.begin(), res.end());
    cout << res;
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