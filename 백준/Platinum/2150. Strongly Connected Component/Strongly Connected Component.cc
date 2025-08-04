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

vector<vector<int>> g;
vector<bool> finished;
vector<int> par;
stack<int> s;
vector<vector<int>> scc;
int id = 0;

int dfs(int node) {
    par[node] = ++id;
    s.push(node);
    
    int parent = par[node];
    for (int next : g[node]) {
        if (par[next] == 0) parent = min(parent, dfs(next));
        else if (!finished[next]) parent = min(parent, par[next]);
    }

    if (parent == par[node]) {
        vector<int> sc;
        while (true) {
            int t = s.top();
            s.pop();
            sc.push_back(t);
            finished[t] = true;
            if (t == node) break;
        }
        sort(sc.begin(), sc.end());
        scc.push_back(sc);
    }

    return parent;
}

void solve(int CASE = -1) {
    int v, e;
    cin >> v >> e;
    g.resize(v + 1);
    finished.resize(v + 1);
    par.resize(v + 1);

    for (int i = 0; i < e; i++) {
        int a, b;
        
        cin >> a >> b;
        g[a].push_back(b);
    }

    for (int i = 1; i <= v; i++)
        if (par[i] == 0) dfs(i);


    auto compare = [](vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
        };

    sort(scc.begin(), scc.end(), compare);

    cout << scc.size() << "\n";
    for (vector<int>& s : scc) {
        for (int node : s) {
            cout << node << " ";
        }
        cout << "-1\n";
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