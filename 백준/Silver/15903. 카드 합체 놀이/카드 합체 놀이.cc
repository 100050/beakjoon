#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <cstdlib>   
#include <ctime> 
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

void solve() {
    int n, m;
    ll a;
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a;
        pq.push(a);
    }

    for (int i = 0; i < m; i++) {
        ll tmp = pq.top();
        pq.pop();
        ll tmp2 = pq.top();
        pq.pop();

        pq.push(tmp + tmp2);
        pq.push(tmp + tmp2);
    }

    ll res = 0;
    while (pq.size()) {
        res += pq.top();
        pq.pop();
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}