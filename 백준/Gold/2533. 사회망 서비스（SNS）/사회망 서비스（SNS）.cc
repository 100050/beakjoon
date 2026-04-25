#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;

const int mxN = 1000001;
int n;
vector<int> arr[mxN];
//bool visited[mxN];
int cache[mxN][2];

int dp(bool select, int node, int prev) {
    int& c = cache[node][select];

    if (c != -1) return c;

    if (select) {
        c = 1;
        for (int n : arr[node]) {
            if (prev == n) continue;

            c += min(dp(true, n, node), dp(false, n, node));
        }
    }
    else {
        c = 0;
        for (int n : arr[node]) {
            if (prev == n) continue;

            c += dp(true, n, node);
        }
    }

    return c;
}

void solve() {
    int a, b;

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;

        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    memset(cache, -1, sizeof(cache));
    
    cout << min(dp(true, 1, -1), dp(false, 1, -1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}