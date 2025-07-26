#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ranges>
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

void solve(int CASE = -1) {
    map<ll, ll> m;
    ll k;

    cin >> k;
    while (k--) {
        char c;
        ll n;
        cin >> c >> n;

        if (c == 'I') {
            m[n]++;
        }
        else {
            if (m.empty()) continue;
            if (n == 1) {
                if (--(m.rbegin()->second) == 0) m.erase(m.rbegin()->first);

            }
            else {
                if (--(m.begin()->second) == 0) m.erase(m.begin());
            }
        }
    }

    if (m.empty()) cout << "EMPTY\n";
    else cout << m.rbegin()->first << " " << m.begin()->first << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}