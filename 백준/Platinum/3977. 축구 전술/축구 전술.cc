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

int scc(int node, vector<vector<int>>& g, vector<int>& par, int& id, stack<int>& s, vector<vector<int>>& SCC, vector<bool>& finished, int& count, vector<int>& scc_id) {
    par[node] = ++id;

    
    s.push(node);
    int parent = par[node];

    for (int next : g[node]) {
        if (par[next] == 0)
            parent = min(parent, scc(next, g, par, id, s, SCC, finished, count, scc_id));
        else if (!finished[next])
            parent = min(parent, par[next]);
    }

    if (par[node] == parent) {
        vector<int> sc;
        while (true) {
            int t = s.top();  s.pop();
            scc_id[t] = count;
            finished[t] = true;
            sc.push_back(t);
            par[t] = parent;
            if (t == node) break;
        }
        count++;
        SCC.push_back(sc);
    }

    return parent;
}

void solve(int CASE = -1) {
    int n, m;
    vector<vector<int>> g;
    vector<int> ind;
    vector<int> par;
    int id;

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
    vector<int> scc_id(n + 1);
    vector<vector<int>> SCC;
    vector<bool> finished(n + 1);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (par[i] == 0) scc(i, g, par, id, s, SCC, finished, count, scc_id);
    }

    vector<int> ind2(count);
    for (vector<int>& t : SCC) {
        for (int i : t) {
            for (int next : g[i]) {
                if (scc_id[i] == scc_id[next]) continue;

                ind2[scc_id[next]]++;
                //cout << i << " " << next << " " << ind2[par[next]] << "\n";
            }
        }
    }

    // 위상 정렬
    vector<int> res;
    int c = 0;
    for (int i = 0; i < count; i++) {
        if (ind2[i] == 0) {
            if (c++ > 1) break;
            for (int node : SCC[i]) {
                res.push_back(node);
            }
        }
    }

    sort(res.begin(), res.end());
    if (c > 1) {
        cout << "Confused" << "\n\n";
    }
    else {
        for (int i : res) {
            cout << i << "\n";
        }
        cout << "\n";
    }
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