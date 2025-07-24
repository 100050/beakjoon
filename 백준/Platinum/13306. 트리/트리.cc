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

int Find(int x) {
    if (x == par[x]) return x;
    else return par[x] = Find(par[x]);
}

void Union(int a, int b) {
    int aa = Find(a);
    int bb = Find(b);

    if (aa != bb) {
        par[aa] = bb;
    }
}

void solve(int CASE = -1) {
    int n, q;
    vector<int> p;
    vector<array<int, 3>> query;

    cin >> n >> q;
    p.resize(n + 1);
    par.resize(n + 1);
    q += n - 1;
    p[1] = 1;
    par[1] = 1;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        par[i] = i;
    }
    for (int i = 0; i < q; i++) {
        int x, c, d;
        cin >> x;

        if (x == 0) {
            cin >> c;
            query.push_back({ x, c, 0 });
        }
        else {
            cin >> c >> d;
            query.push_back({ x, c, d });
        }
    }

    vector<bool> res;
    for (int i = q - 1; i >= 0; i--) {
        if (query[i][0] == 0) {
            Union(query[i][1], p[query[i][1]]);
        }
        else {
            res.push_back(Find(query[i][1]) == Find(query[i][2]));
        }
    }
    auto itr = res.rbegin();
    for (; itr != res.rend(); itr++) cout << (*itr ? "YES\n" : "NO\n");
    
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