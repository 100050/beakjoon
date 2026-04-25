#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;

const int mxN = 32001;

void solve() {
    int n, m;
    int a, b;
    vector<int> arr[mxN];
    queue<int> q;

    cin >> n >> m;
    vector<int> degree(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a].push_back(b);
        degree[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        int x = q.front();
        q.pop();

        cout << x << " ";
        for (int y : arr[x]) {
            if (--degree[y] == 0) {
                q.push(y);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}