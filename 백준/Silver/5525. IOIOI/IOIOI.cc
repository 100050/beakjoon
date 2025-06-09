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
    int n, m;
    char c;

    cin >> n >> m;

    int j = 0, res = 0;
    for (int i = 0; i < m; i++) {
        cin >> c;
        if (c == (j % 2 == 0 ? 'I' : 'O')) {
            j++;
        }
        else {
            j = 0;
            if (c == 'I') j = 1;
        }
        if (j == 2 * n + 1) {
            j -= 2;
            res++;
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