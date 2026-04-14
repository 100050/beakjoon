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

//constexpr ll MOD = 1000000007;
constexpr ll MOD = 1000000000;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };


using T = ll;
int n, m;
vector<vector<T>> ft;

void update(int x, int y, int v) {
    for (; x <= n; x += (x & -x)) for (int yy = y; yy <= m; yy += (yy & -yy)) ft[x][yy] += v;
}

T get(int x, int y) {
    T ret = 0;

    for (; x; x -= (x & -x)) for (int yy = y; yy; yy -= (yy & -yy)) ret += ft[x][yy];

    return ret;
}

void solve(int CASE = -1) {
    int q;

    cin >> n >> m >> q;
    ft.resize(n+2, vector<T>(m+2));

    while (q--) {
        int s;
        cin >> s;
        if (s == 1) {
            int x1, x2, y1, y2, d;
            cin >> x1 >> y1 >> x2 >> y2 >> d;
            
            update(x1, y1, d);
            update(x2+1, y2+1, d);
            update(x2+1, y1, -d);
            update(x1, y2+1, -d);
        }
        else {
            int x, y;
            cin >> x >> y;
            
            cout << get(x, y) << "\n";
        }
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