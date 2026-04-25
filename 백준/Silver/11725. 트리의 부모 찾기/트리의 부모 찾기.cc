#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int mxN = 100001;

vector<int> tree[mxN];
int parent[mxN];
bool visited[mxN];

void dfs(int node) {

    for (int child : tree[node]) {
        if (visited[child]) continue;

        parent[child] = node;
        visited[child] = true;
        dfs(child);
    }
}

void solve() {
    int n;
    int i;

    cin >> n;

    for (i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    visited[1] = true;
    dfs(1);

    for (int i = 2; i <= n; i++) {
        cout << parent[i] << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();


    return 0;
}