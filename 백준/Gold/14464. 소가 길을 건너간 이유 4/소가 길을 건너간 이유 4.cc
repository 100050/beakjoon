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
    int c, n, a, b;
    multiset<int> t;
    priority_queue<pii, vector<pii>, greater<pii>> ab;

    cin >> c >> n;
    for (int i = 0; i < c; i++) {
        cin >> a;
        t.insert(a);
    }
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        ab.push(pii(b, a));
    }

    int res = 0, tt;
    while (ab.size()) {
        pii tab = ab.top();
        //cout << tt << endl;
        
        auto itr = t.lower_bound(tab.second);
        
        if (itr != t.end() && *itr <= tab.first) {
            res++;
            t.erase(itr);
        }

        ab.pop();
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