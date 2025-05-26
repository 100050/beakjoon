#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

void solve() {
    int n;
    map<string, int> mp;
    string a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        
        if (mp[b])
            mp[b]++;
        else
            mp[b] = 1;

    }

    int s = 1;
    for (auto node : mp) {
        s *= node.second + 1;
    }
    cout << s - 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}