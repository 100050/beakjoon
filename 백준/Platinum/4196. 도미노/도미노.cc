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

void dfs(int node, vector<vector<int>>& g, vector<bool>& visited) {
    visited[node] = true;

    for (int next : g[node]) {
        if (visited[next]) continue;
        
        dfs(next, g, visited);
    }
}

int scc(int node, vector<vector<int>>& g, vector<int>& par, int& id, stack<int>& s, vector<vector<int>>& SCC, vector<bool>& finished, vector<bool>& is) {
    par[node] = ++id;

    
    s.push(node);
    int parent = par[node];

    for (int next : g[node]) {
        if (par[next] == 0)
            parent = min(parent, scc(next, g, par, id, s, SCC, finished, is));
        else if (!finished[next])
            parent = min(parent, par[next]);
    }

    if (par[node] == parent) {
        is[parent] = true;
        vector<int> sc;
        while (node) {
            int t = s.top();  s.pop();

            finished[t] = true;
            sc.push_back(t);
            par[t] = parent;
            if (t == node) break;
        }
        SCC.push_back(sc);
    }

    return parent;
}

void solve(int CASE = -1) {
    int n, m, res;
    vector<vector<int>> g;
    vector<int> ind;
    vector<int> par;
    int id;

    res = 0;
    id = 0;
    cin >> n >> m;
    g.resize(n + 1);
    ind.resize(n + 1);
    par.resize(n + 1);
    while (m--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        ind[y]++;
    }

    // SCC
    stack<int> s;
    vector<vector<int>> SCC;
    vector<bool> finished(n + 1), is(n + 1);
    for (int i = 1; i <= n; i++) {
        if (par[i] == 0) scc(i, g, par, id, s, SCC, finished, is);
    }

    vector<vector<int>> g2;
    vector<int> ind2(n + 1);
    g2.resize(n + 1);
    for (vector<int>& t : SCC) {
        for (int i : t) {
            for (int next : g[i]) {
                if (par[i] == par[next]) continue;

                g2[par[i]].push_back(par[next]);
                ind2[par[next]]++;
                //cout << i << " " << next << " " << ind2[par[next]] << "\n";
            }
        }
    }

    // 위상 정렬
    for (int i = 1; i <= n; i++) {
        if (ind2[i] == 0 && is[i]) {
            res++;
        }
    }

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}