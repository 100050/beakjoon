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

int find_scc(int node, int& id, vector<int>& par, int& scc_count, vector<int>& scc_id, vector<vector<int>>& scc, vector<int>& scc_cash, stack<int>& ss, vector<bool>& finished) {
    par[node] = ++id;
    int parent = par[node];
    ss.push(node);

    for (int next : graph[node]) {
        if (par[next] == 0) parent = min(parent, find_scc(next, id, par, scc_count, scc_id, scc, scc_cash, ss, finished));
        else if (!finished[next]) parent = min(parent, par[next]);
    }
    //cout << node << " " << parent << "\n";
    if (par[node] == parent) {
        vector<int> sc;
        int cash_sum = 0;
        while (true) {
            int t = ss.top(); ss.pop();
            
            finished[t] = true;
            scc_id[t] = scc_count;
            cash_sum += cash[t];
            sc.push_back(t);

            //cout << t << " " << scc_id[t] << "\n";
            if (t == node) break;
        }
        scc_count++;
        scc.push_back(sc);
        scc_cash.push_back(cash_sum);
    }

    return parent;
}

void solve(int CASE = -1) {
    cin >> n >> m;
    graph.resize(n + 1);
    cash.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        cin >> cash[i];
    }
    cin >> s >> p;
    for (int i = 0; i < p; i++) {
        int t;
        cin >> t;
        cross.push_back(t);
    }

    // scc
    int scc_count = 0, id = 0;
    vector<int> ind, scc_id(n + 1), scc_cash, par(n + 1);
    vector<vector<int>> scc, scc_graph;
    vector<bool> finished(n + 1);
    stack<int> ss;

    for (int i = 1; i <= n; i++) {
        if (par[i] == 0)
            find_scc(i, id, par, scc_count, scc_id, scc, scc_cash, ss, finished);
    }
    
    cash.clear();

    scc_graph.resize(scc_count);
    ind.resize(scc_count);
    for (int i = 0; i < scc_count; i++) {
        for (int node : scc[i]) {
            for (int next : graph[node]) {
                if (scc_id[node] == scc_id[next]) continue;

                scc_graph[scc_id[node]].push_back(scc_id[next]);
                ind[scc_id[next]]++;
            }
        }
    }

    graph.clear();

    // 위상정렬 + dp
    queue<int> q;
    vector<int> dp(scc_count);
    for (int i = 0; i < scc_count; i++) {
        if (ind[i] == 0) q.push(i);
    }
    
    bool flag = false;
    dp[scc_id[s]] = scc_cash[scc_id[s]];
    while (q.size()) {
        int f = q.front(); q.pop();
        if (f == scc_id[s]) flag = true;
        for (int next : scc_graph[f]) {
            if (--ind[next] == 0) q.push(next);

            if (flag) dp[next] = max(dp[next], dp[f] + scc_cash[next]);
        }
    }

    int res = 0;
    for (int i = 0; i < p; i++) {
        res = max(res, dp[scc_id[cross[i]]]);
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