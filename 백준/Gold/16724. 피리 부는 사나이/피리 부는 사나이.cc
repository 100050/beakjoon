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


int n, m;
char arr[1000][1000];
int p[1000 * 1000];

int Find(int x) {
    if (x == p[x]) return x;
    else return p[x] = Find(p[x]);
}

void Union(int a, int b) {
    int pa = Find(a), pb = Find(b);

    if (pa == pb) return;

    p[pb] = pa;
}

void solve(int CASE = -1) {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            p[i * m + j] = i * m + j;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            switch (arr[i][j]) {
            case 'D':
                Union(i * m + j, (i + 1) * m + j);
                break;
            case 'L':
                Union(i * m + j, i * m + j - 1);
                break;
            case 'R':
                Union(i * m + j, i * m + j + 1);
                break;
            case 'U':
                Union(i * m + j, (i - 1) * m + j);
                break;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n * m; i++) {
        if (p[i] == i) res++;
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