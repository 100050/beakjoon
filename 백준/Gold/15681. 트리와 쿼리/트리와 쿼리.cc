#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;

const int mxN = 100000+1;
vector<int> tree[mxN];
vector<int> vN;
vector<int> visited;

void dfs(int node) {

    vN[node] = 1;
    for (int child : tree[node]) {
        if (vN[child]) continue;

        visited[child] = 1;
        dfs(child);

        vN[node] += vN[child];
    }

    //vN[node] = n;

}

void solve() {
    int n, r, q;
    int u, v;

    cin >> n >> r >> q;
    vN = vector<int>(n + 1);
    visited = vector<int>(n + 1);
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(r);

    for (int i = 0; i < q; i++) {
        cin >> u;

        cout << vN[u] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}