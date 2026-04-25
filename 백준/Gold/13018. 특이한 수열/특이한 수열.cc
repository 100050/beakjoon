#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;


void solve() {
    int n, k;

    cin >> n >> k;
    if (n == k) {
        cout << "Impossible";
        return;
    }
    int i;
    if ((n ^ k) & 1) cout << 1 << " ";
    for (i = 1+((n^k)&1); i < n - k; i += 2) {
        cout << i + 1 << " ";
        cout << i << " ";
    }
    for (i = n - k + (n - k != i); i <= n; i++) {
        cout << i << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}