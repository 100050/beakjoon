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
vector<set<int>> color;

int Find(int x) {
    if (x == par[x]) return x;
    else return par[x] = Find(par[x]);
}

void Union(int a, int b) {
    int aa = Find(a);
    int bb = Find(b);

    if (aa != bb) {
        if (color[aa].size() > color[bb].size()) swap(aa, bb);
        par[aa] = bb;
        color[bb].merge(color[aa]);
        color[aa].clear();
    }
}

void solve(int CASE = -1) {
    int n, q;
    vector<int> p;
    vector<array<int, 2>> query;

    cin >> n >> q;
    query.resize(q + n - 1);
    p.resize(n + 1);
    par.resize(n + 1);
    color.resize(n + 1);
    par[1] = 1;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        par[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        color[i].insert(c);
    }

    for (int i = 0; i < q + n - 1; i++) {
        cin >> query[i][0] >> query[i][1];
    }

    vector<int> res;
    for (int i = q + n - 2; i >= 0; i--) {
        if (query[i][0] == 1) {
            Union(query[i][1], p[query[i][1]]);
        }
        else {
            int pa = Find(query[i][1]);

            res.push_back(color[pa].size());
        }
    }

    auto itr = res.rbegin();
    for (; itr != res.rend(); itr++) {
        cout << *itr << "\n";
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