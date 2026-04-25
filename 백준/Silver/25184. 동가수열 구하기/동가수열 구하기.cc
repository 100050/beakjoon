#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;

void solve() {
    int n, m;

    cin >> n;
    m = (n + 1) / 2;

    for (int i = 0; i < n; i++) {
        cout << (i % 2 == 0 ? m-i/2 : n-i/2) << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}