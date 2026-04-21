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

vector<int> z;

void getZ(string& s) {
    int n, l = 0, r = 0;
    n = s.size();
    z.resize(n);

    z[0] = n;
    for (int i = 1; i < n; i++) {
        if (r < i) {
            r = l = i;
            while (r < n && s[r] == s[r - l]) r++;
            z[i] = r - l; r--;
        }
        else {
            int k = i - l;
            if (z[k] < r - i + 1) z[i] = z[k];
            else {
                l = i;
                while (r < n && s[r] == s[r - l]) r++;
                z[i] = r - l; r--;
            }
        }
    }
}

void solve(int CASE = -1) {
    string inp;

    cin >> inp;

    reverse(inp.begin(), inp.end());

    getZ(inp);

    int m;
    cin >> m;
    while (m--) {
        int q;
        cin >> q;
        cout << z[inp.size() - q] << "\n";
    }

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