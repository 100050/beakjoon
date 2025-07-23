#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
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

vector<int> f;
vector<vector<int>> e;

int Find(int x) {
    if (x == f[x]) return x;
    else return f[x] = Find(f[x]);
}

void Union(int a, int b) {
    int aa = Find(a);
    int bb = Find(b);

    if (aa != bb) {
        f[aa] = bb;
    }
}

void solve(int CASE = -1) {
    int n, m;

    cin >> n >> m;

    f.resize(n + 1);
    e.resize(n + 1);
    for (int i = 1; i <= n; i++) f[i] = i;

    while (m--) {
        char r;
        int p, q;

        cin >> r >> p >> q;

        if (r == 'F') {
            Union(p, q);
        }
        else {
            for (int ee : e[p]) {
                Union(q, ee);
            }
            for (int ee : e[q]) {
                Union(p, ee);
            }
            e[p].push_back(q);
            e[q].push_back(p);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) if (f[i] == i) res++;

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