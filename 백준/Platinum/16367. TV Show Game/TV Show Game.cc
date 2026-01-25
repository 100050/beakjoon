#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <ranges>
#include <numeric>
#include <cstring>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

constexpr ll MOD = 1000000007;
//const ll MOD = 10007;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };


int n, m;
int s, p;
vector<vector<int>> graph;
vector<int> cross;
vector<int> cash;

auto NOT = [](int x) { // 짝수: true, 홀수: false, 1 base
    return x & 1 ? x + 1 : x - 1;
    };

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
    int n, k;

    cin >> k >> n;
    graph.resize(2 * k + 1);
    for (int i = 0; i < n; i++) {
        char c;
        pair<int, bool> t[3];

        cin >> t[0].first >> c;
        t[0].second = (c == 'R' ? true : false);
        t[0].first *= 2;
        t[0].first -= static_cast<int>(!t[0].second);
        cin >> t[1].first >> c;
        t[1].second = (c == 'R' ? true : false);
        t[1].first *= 2;
        t[1].first -= static_cast<int>(!t[1].second);
        cin >> t[2].first >> c;
        t[2].second = (c == 'R' ? true : false);
        t[2].first *= 2;
        t[2].first -= static_cast<int>(!t[2].second);

        graph[NOT(t[0].first)].push_back(t[1].first);
        graph[NOT(t[0].first)].push_back(t[2].first);
        graph[NOT(t[1].first)].push_back(t[0].first);
        graph[NOT(t[1].first)].push_back(t[2].first);
        graph[NOT(t[2].first)].push_back(t[1].first);
        graph[NOT(t[2].first)].push_back(t[0].first);
    }

    int scc_count = 0, id = 0;
    vector<int> ind, scc_id(2 * k + 1), par(2 * k + 1);
    vector<vector<int>> scc, scc_graph;
    vector<bool> finished(2 * k + 1);
    stack<int> ss;

    for (int i = 1; i <= 2 * k; i++) {
        if (par[i] == 0)
            find_scc(i, id, par, scc_count, scc_id, scc, ss, finished);
    }

    for (int i = 1; i <= k; i++) {
        if (scc_id[i * 2 - 1] == scc_id[i * 2]) {
            cout << -1;
            return;
        }
    }

    vector<int> res(2 * k + 1, -1);
    for (int i = scc_count - 1; i >= 0; i--) {
        for (int v : scc[i]) {
            //cout << v << "\n";
            if (res[v] != -1) continue;
            res[v] = 0;
            res[NOT(v)] = 1;
        }
    }

    for (int i = 1; i <= k; i++) {
        cout << (res[2 * i - 1] == 1 ? "B" : "R");
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