#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void solve() {
    ll k, f;
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> f;
        pq.push(f);
    }

    ll res = 0;
    while (true) {
        ll p = pq.top(); pq.pop();
        ll n = pq.top(); pq.pop();

        res += p + n;

        if (pq.empty()) break;

        pq.push(p+n);
    }

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}