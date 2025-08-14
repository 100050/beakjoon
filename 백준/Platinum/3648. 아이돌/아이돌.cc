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


int find_scc(int node, int& id, vector<int>& par, int& scc_count, vector<int>& scc_id, vector<vector<int>>& scc, stack<int>& ss, vector<bool>& finished, vector<vector<int>>& graph) {
    par[node] = ++id;
    int parent = par[node];
    ss.push(node);

    for (int next : graph[node]) {
        if (par[next] == 0) parent = min(parent, find_scc(next, id, par, scc_count, scc_id, scc, ss, finished, graph));
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

bool bfs(int node, vector<bool>& res, vector<vector<int>>& graph) {
    queue<int> q;
    auto NOT = [](int x) {
        return x & 1 ? x + 1 : x - 1;
        };
    res[node] = true;
    q.push(node);
    while (q.size()) {
        int f = q.front(); q.pop();


        if (res[f] && res[NOT(f)]) {
            return true;
        }

        for (int next : graph[f]) {
            if (res[next]) continue;
            res[next] = true;
            q.push(next);
        }
    }

    return false;
}

void solve(int CASE = -1) {
    while (true) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(2 * n + 1);
        if (cin.eof()) break;

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
        vector<int> ind, scc_id(2 * n + 1), par(2 * n + 1);
        vector<vector<int>> scc, scc_graph;
        vector<bool> finished(2 * n + 1);
        stack<int> ss;

        for (int i = 1; i <= 2 * n; i++) {
            if (par[i] == 0)
                find_scc(i, id, par, scc_count, scc_id, scc, ss, finished, graph);
        }

        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if (scc_id[i * 2 - 1] == scc_id[i * 2]) {
                cout << "no\n";
                flag = true;
                break;
            }
        }
        if (flag) continue;

        vector<bool> res(2 * n + 1, 0);

        // bfs로 1에서 a와 ~a로 가는 경로가 둘다 있는지 확인

        if (bfs(1, res, graph)) {
            cout << "no\n";
        }
        else {
            cout << "yes\n";
        }

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