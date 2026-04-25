#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;

const int mxN = 10000+1;
vector<int> tree[mxN];
vector<int> path;
int cache[mxN][2];
int visited[mxN];
vector<int> w;

int dp(bool select, int node, int prev) {
    int& c = cache[node][select];

    if (c != -1)
        return c;

    if (select) {
        c = w[node];
        for (int next : tree[node]) {
            if (prev != next)
                c += dp(false, next, node);
        }
    }
    else {
        c = 0;
        for (int next : tree[node]) {
            if (prev != next)
                c += max(dp(false, next, node), dp(true, next, node));
        }
    }

    return c;
}

void dfs(int node, int prev) {
    // 전 노드를 보지 않았다면
    if (cache[node][true] > cache[node][false] && visited[prev] == false) {
        path.push_back(node);
        visited[node] = true; 
    }

    for (auto& there : tree[node]) {
        if (there != prev) {
            dfs(there, node);
        }
    }
}

void solve() {
    int n;
    int u, v;

    cin >> n;
    w.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> u;
        w.push_back(u);
    }
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    memset(cache, -1, sizeof(cache));
    int ret = max(dp(false, 1, -1), dp(true, 1, -1));

    dfs(1, 0);
    
    sort(path.begin(), path.end());
    cout << ret << "\n";
    for (int p : path) {
        cout << p << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}