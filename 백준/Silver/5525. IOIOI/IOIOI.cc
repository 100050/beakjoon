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
    string str;
    string target = "";

    cin >> n >> m;
    cin >> str;

    for (int i = 0; i < 2 * n + 1; i++) {
        target = target + (i % 2 == 0 ? 'I' : 'O');
    }
    int j = 0, res = 0;
    for (int i = 0; i < m; i++) {
        if (str[i] == (j % 2 == 0 ? 'I' : 'O')) {
            j++;
        }
        else {
            j = 0;
            if (str[i] == 'I') j = 1;
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