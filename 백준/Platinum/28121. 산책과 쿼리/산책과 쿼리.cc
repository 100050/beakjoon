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
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

vector<int> par;
vector<int> sz;
int res = 0;

int Find(int x) {
    if (x == par[x]) return x;
    else return par[x] = Find(par[x]);
}

void Union(int a, int b) {
    int aa = Find(a);
    int bb = Find(b);
    if (aa != bb) {
        if (aa % 2 == 0 && Find(aa - 1) == aa) res -= sz[aa];
        if (aa % 2 != 0 && Find(aa + 1) == aa) res -= sz[aa];

        if (bb % 2 == 0 && Find(bb - 1) == bb) res -= sz[bb];
        if (bb % 2 != 0 && Find(bb + 1) == bb) res -= sz[bb];
        
        par[bb] = aa;
        sz[aa] += sz[bb];
        sz[bb] = 0;

        if (aa % 2 == 0 && Find(aa - 1) == aa) res += sz[aa];
        if (aa % 2 != 0 && Find(aa + 1) == aa) res += sz[aa];
    }
}

void solve(int CASE = -1) {
    int n, q;
    int a, b;

    cin >> n >> q;
    par.resize(2 * (n + 1));
    sz.resize(2 * (n + 1));
    for (int i = 1; i <= n * 2; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < q; i++) {
        cin >> a >> b;

        Union(2 * a - 1, 2 * b);
        Union(2 * a, 2 * b - 1);
        
        cout << (res>>1) << "\n";
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