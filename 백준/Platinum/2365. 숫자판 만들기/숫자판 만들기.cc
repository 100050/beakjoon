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

struct Edge {
    int v, cap, rev;
    Edge(int _v, int _cap, int _rev) : v(_v), cap(_cap), rev(_rev) {}
};


const int MAX = 50*50+50*50+50*2+2+1;
int n;
array<vector<Edge>, MAX> adj, ans;
array<int, MAX> level, work;

void insert_edge(int a, int b, int cost) {
    adj[a].emplace_back(b, cost, adj[b].size());
    adj[b].emplace_back(a, 0, adj[a].size() - 1);
}

bool bfs(int start, int end) {
    fill(level.begin(), level.end(), -1);
    queue<int> q;
    q.push(start);
    level[start] = 0;

    while (q.size()) {
        int f = q.front(); q.pop();

        for (Edge& nxt : adj[f]) {
            if (level[nxt.v] == -1 && nxt.cap > 0) {
                level[nxt.v] = level[f] + 1;
                q.push(nxt.v);
            }
        }
    }

    return level[end] != -1;
}

int dfs(int v, int end, int f) {
    if (v == end) return f;
    for (int& i = work[v]; i < adj[v].size(); i++) {
        Edge& nxt = adj[v][i];
        if (level[nxt.v] == level[v] + 1 && nxt.cap > 0) {
            int df = dfs(nxt.v, end, min(f, nxt.cap));

            if (df > 0) {
                nxt.cap -= df;
                adj[nxt.v][nxt.rev].cap += df;
                return df;
            }
        }
    }

    return 0;
}

int s = 0;
vector<int> b, r;

int f(int x) {
    for (auto& a : adj)
        a.clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            insert_edge(n * n + i * n + j + 3, i * n + j + 3, x);
            insert_edge(n * n * 2 + j + 3, n * n + i * n + j + 3, INF<int>); // 들어오는 쪽
            insert_edge(i * n + j + 3, n * n * 2 + n + i + 3, INF<int>); // 나가는 쪽
        }
    }
    for (int i = 0; i < n; i++) {
        insert_edge(1, n * n * 2 + i + 3, b[i]); // 들어오는 쪽
        insert_edge(n * n * 2 + n + i + 3, 2, r[i]); // 나가는 쪽
    }

    int res = 0;
    while (bfs(1, 2)) {
        fill(work.begin(), work.end(), 0);
        //cout << res << "\n";
        while (1) {
            int flow = dfs(1, 2, INF<int>);
            if (flow == 0) break;
            res += flow;
        }
    }
    //cout << res << " " << s << "\n";
    return res == s;
}

void solve(int CASE = -1) {
    cin >> n;

    b.resize(n);
    r.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
        s += r[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    


    int begin = -1, end = 10001;
    while (begin + 1 < end) {
        int mid = (begin + end) / 2;

        //cout << mid << "\n";
        if (f(mid)) {
            end = mid;
            ans = adj;
        }
        else {
            begin = mid;
        }
    }

    cout << end << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto& k : ans[n * n + i * n + j + 3]) {
                if (k.v == i * n + j + 3) {
                    cout << end - k.cap << " ";
                    break;
                }
            }
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    //pre();
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}