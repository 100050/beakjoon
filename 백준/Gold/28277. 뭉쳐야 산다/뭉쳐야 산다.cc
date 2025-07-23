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

void solve(int CASE = -1) {
    int n, q, nn, s;
    vector<set<int>> arr;

    cin >> n >> q;
    arr.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> nn;
        for (int j = 0; j < nn; j++) {
            cin >> s;
            arr[i].insert(s);
        }
    }

    while (q--) {
        int p, a, b;

        cin >> p;

        if (p == 1) {
            cin >> a >> b;

            if (arr[a].size() < arr[b].size()) {
                swap(arr[a], arr[b]);
            }
            arr[a].insert(arr[b].begin(), arr[b].end());
            arr[b].clear();
        }
        else {
            cin >> a;

            cout << arr[a].size() << "\n";
        }
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}