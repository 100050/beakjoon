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
    char c;

    int all = 0, idx;
    for (int i = 0; i < 12; i++) {
        cin >> c;
        if (c != '*') {
            all += (c - '0') * (i % 2 ? 3 : 1);
        }
        else {
            idx = i;
        }
    }
    int m;
    cin >> c;
    m = c - '0';

    for (int i = 9; i >= 0; i--) {
        int check = 10 - ((all + i * (idx % 2 ? 3 : 1)) % 10);
        if (check == 10) check = 0;
        if (check == m) {
            cout << i;
            return;
        }
    }
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