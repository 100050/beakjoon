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

int n, m;
int s, p;
vector<vector<int>> graph;
vector<int> cross;
vector<int> cash;

int find_scc(int node, int& id, vector<int>& par, int& scc_count, vector<int>& scc_id, vector<vector<int>>& scc, stack<int>& ss, vector<bool>& finished) {
    par[node] = ++id;
    int parent = par[node];
    ss.push(node);

    for (int next : graph[node]) {
        if (par[next] == 0) parent = min(parent, find_scc(next, id, par, scc_count, scc_id, scc, ss, finished));
        else if (!finished[next]) parent = min(parent, par[next]);
    }
    //cout << node << " " << parent << "\n";
    if (par[node] == parent) {
        vector<int> sc;
        while (true) {
            int t = ss.top(); ss.pop();
            
            finished[t] = true;
            scc_id[t] = scc_count;
            sc.push_back(t);

            //cout << t << " " << scc_id[t] << "\n";
            if (t == node) break;
        }
        scc_count++;
        scc.push_back(sc);
    }

    return parent;
}

void solve(int CASE = -1) {
    cin >> n >> m;
    graph.resize(2*n + 1);

    auto NOT = [](int x) {
        return x & 1 ? x + 1 : x - 1;
        };
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a = a < 0 ? abs(a) * 2 : a * 2 - 1;
        b = b < 0 ? abs(b) * 2 : b * 2 - 1;
        graph[NOT(a)].push_back(b);
        graph[NOT(b)].push_back(a);
    }

    // scc
    int scc_count = 0, id = 0;
    vector<int> ind, scc_id(2*n + 1), par(2*n + 1);
    vector<vector<int>> scc, scc_graph;
    vector<bool> finished(2*n + 1);
    stack<int> ss;

    for (int i = 1; i <= 2*n; i++) {
        if (par[i] == 0)
            find_scc(i, id, par, scc_count, scc_id, scc, ss, finished);
    }
        
    for (int i = 1; i <= n; i++) {
        if (scc_id[i * 2 - 1] == scc_id[i * 2]) {
            cout << 0;
            return;
        }
    }
    cout << 1;
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