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
    int g, p, m, res;
    set<int> s;

    cin >> g >> p;

    for (int i = 1; i <= g; i++) s.insert(i);

    res = 0;
    for (int i = 0; i < p; i++) {
        cin >> m;

        auto itr = s.upper_bound(m);
        if (s.begin() != itr && s.size() != 1) itr--;
        else if (s.size() == 1 &&  *itr <= m) {
            res++; break;
        }
        else break;
        s.erase(itr);
        res++;
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