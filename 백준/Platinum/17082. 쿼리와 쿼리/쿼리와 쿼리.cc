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
    int n, m, q;
    vector<int> arr, left, right, par;
    map<int, int> mp;

    cin >> n >> m >> q;
    arr.resize(n + 1);
    par.resize(n + 1, 0);
    left.resize(m);
    right.resize(m);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        par[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        cin >> left[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> right[i];
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int pl = left[0];
    int pr = right[0];
    bool flag = left[0] > right[0];
    for (int i = 1; i < m; i++) {
        if (left[i] > right[i]) {
            flag = true;
        }
        if (left[i] <= pr + 1) {
            pr = right[i];
        }
        else {
            for (int j = pl; j <= pr; j++) {
                par[j] = 1;
                mp[arr[j]]++;
            }
            pl = left[i];
            pr = right[i];
        }
    }
    for (int j = pl; j <= pr; j++) {
        par[j] = 1;
        mp[arr[j]]++;
    }

    while (q--) {
        int i, j;

        cin >> i >> j;

        if (flag) {
            cout << "1000000000\n";
            continue;
        }
        int pj = par[j], pi = par[i];
        if (arr[i] != arr[j]) {
            if (pi && !pj) {
                if (--mp[arr[i]] == 0) mp.erase(arr[i]);
                mp[arr[j]]++;
            }
            if (pj && !pi) {
                if (--mp[arr[j]] == 0) mp.erase(arr[j]);
                mp[arr[i]]++;
            }
        }
        swap(arr[i], arr[j]);


        cout << mp.rbegin()->first << "\n";
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