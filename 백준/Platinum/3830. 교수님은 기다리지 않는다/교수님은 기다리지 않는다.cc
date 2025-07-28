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
vector<map<int, ll>> r;
int res = 0;

int Find(int x) {
    if (x == par[x]) return x;
    else return par[x] = Find(par[x]);
}

void Union(int a, int b, int w) {
    int aa = Find(a);
    int bb = Find(b);
    if (aa != bb) {
        ll d = r[bb][b] - w - r[aa][a];
        if (r[aa].size() < r[bb].size()) swap(aa, bb), d = -d; // 수정
        par[bb] = aa;
        for (auto itr : r[bb]) {
            r[aa][itr.first] = itr.second - d;
        }
        r[bb].clear();
    }
}
/*
1 0
2 100
3 200
4 
*/
void solve(int CASE = -1) {
    int n, m;

    while (true) {
        cin >> n >> m;
        if (n == 0) break;
        par.resize(n + 1);
        r.resize(n + 1);

        for (int i = 1; i <= n; i++) par[i] = i, r[i][i] = 0;
        while (m--) {
            char q;
            int a, b, w;
            cin >> q;

            if (q == '!') {
                cin >> a >> b >> w;

                Union(a, b, w);
            }
            else {
                cin >> a >> b;

                int bb = Find(b);
                int aa = Find(a);
                if (aa == bb) {
                    cout << r[aa][b] - r[aa][a] << "\n";
                }
                else cout << "UNKNOWN\n";
            }
        }

        par.clear();
        r.clear();
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