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

vector<int> p;
void manacher(string& s) {
    int c, n, r;
    n = s.size();
    p.resize(n);

    r = 0; c = 0;
    for (int i = 0; i < n; i++) {
        if (r < i) p[i] = 0;
        else p[i] = min(p[2 * c - i], r - i);

        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n 
            && s[i - p[i] - 1] == s[i + p[i] + 1]) p[i]++;
        
        if (r < i + p[i]) {
            r = i + p[i];
            c = i;
        }
    }
}

void solve(int CASE = -1) {
    string inp, str = "*";

    cin >> inp;

    for (char c : inp) str += c, str += "*";
    //cout << str << "\n";
    manacher(str);


    ll mx = 0;
    for (int i = 0; i < p.size(); i++) {
        //cout << p[i] << "\n";
        mx += (p[i] + (i & 1)) / 2;
    }

    cout << mx;
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