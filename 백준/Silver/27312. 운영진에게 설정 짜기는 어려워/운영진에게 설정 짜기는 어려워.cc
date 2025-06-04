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
    int m, n, q;
    int a;
    vector<int> arr;
    vector<int> res;

    cin >> m >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }

    for (int i = 0; i < m; i++) {
        int t;
        cout << "? " << (i + 1) << " " << (i + 1) << endl;
        cin >> t;

        res.push_back((t) % arr[i] + 1);
    }

    for (int i = 0; i < n - m; i++) {
        res.push_back(1);
    }

    cout << "! ";
    for (int r : res) {
        cout << r << " ";
    }
    cout << endl;
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