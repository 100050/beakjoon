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

int n, a, b;
vector<int> t;

void solve() {

    cin >> n >> a >> b;
    t.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int x = 0; x <= a - 1; x++) {
            int l = 0;
            int time = i == 0 ? b * x : 0;
            for (int j = 1; j <= n; j++) {
                if (j > i) {
                    if (time + (a - x) <= t[j - 1]) {
                        l++;
                        time += a - x;
                    }
                }
                else {
                    if (time + a <= t[j - 1]) {
                        l++;
                        time += a;
                    }
                }
                if (j == i) {
                    time += b * x;
                }
            }
            res = max(res, l);
        }
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