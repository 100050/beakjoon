#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int mxN = 10001;

vector<pii> tree[mxN];
int r[mxN];
bool visited[mxN];

int dfs(int node) {
    int max = 0, max2 = 0;


    for (pii child : tree[node]) {
        if (visited[child.first]) continue;
        
        visited[child.first] = true;
        int sum = dfs(child.first) + child.second;

        if (sum > max) {
            max2 = max;
            max = sum;
        }
        else if (sum > max2) { 
            max2 = sum;
        }
    }

    r[node] = max + max2;

    return max;
}

void solve() {
    int n;
    int i, dummy;

    cin >> n;

    for (i = 0; i < n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        tree[a].push_back({ b, c });
        tree[b].push_back({ a, c });
    }

    visited[1] = true;

    dfs(1);
    int max = 0;
    for (i = 1; i <= n; i++) {
        if (max < r[i])
            max = r[i];
    }

    cout << max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();


    return 0;
}