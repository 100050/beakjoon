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

vector<int> p, party;
vector<bool> truth;

int Find(int x) {
    if (p[x] == x) return x;
    else return p[x] = Find(p[x]);
}

void Union(int a, int b) {
    int pa = Find(a);
    int pb = Find(b);

    if (truth[pa]) {
        p[pb] = pa;
    }
    else {
        p[pa] = pb;
    }
}

void solve(int CASE = -1) {
    int n, m, nn, h1, h2, res;

    cin >> n >> m;
    res = m;
    p.resize(n + 1);
    iota(p.begin(), p.end(), 0);
    truth.resize(n + 1);
    party.resize(m + 1);
    cin >> nn;
    for (int i = 0; i < nn; i++) {
        cin >> h1;
        truth[h1] = true;
    }
    for (int i = 0; i < m; i++) {
        cin >> nn;
        cin >> h2;
        party[i] = h2;
        for (int j = 1; j < nn; j++) {
            cin >> h1;
            Union(h1, h2);
            h2 = h1;
        }
    }

    for (int i = 0; i < m; i++) {
        if (truth[Find(party[i])]) res--;
    }

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