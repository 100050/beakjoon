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

vector<pil> rarr;

void solve() {
    int n;
    ll m;
    ll x, y;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (x > y) rarr.push_back(make_pair(y, x));
    }

    if (rarr.size() == 0) {
        cout << m;
        return;
    }
    sort(rarr.begin(), rarr.end());

    ll res = m;
    ll begin, end;
    tie(begin, end) = rarr[0];
    for (int i = 1; i < rarr.size(); i++) {
        pil& a = rarr[i];
        if (begin <= a.first && a.first <= end && a.second > end) {
            end = a.second;
        }
        else if (end < a.first) {
            res += 2 * (end - begin);
            end = a.second;
            begin = a.first;
        }
    }

    cout << res + 2 * (end - begin);
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