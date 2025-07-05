#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;
const ll mod = 1000000007;

string str[501];
int arr[501][501][26];
char res[501][501];

void solve() {
    int n, m, k;

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    for (int g = 0; g < k*k; g++) {
        for (int i = g / k; i < n; i += k) {
            for (int j = g % k; j < m; j += k) {
                arr[g / k][g % k][str[i][j] - 'A']++;
            }
        }
    }

    int mx = 0;
    int all = 0;
    char mxc;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            for (int g = 0; g < 26; g++) {
                if (mx < arr[i][j][g]) {
                    mx = arr[i][j][g];
                    mxc = g + 'A';
                }
            }
            //cout << mxc << " " << mx << endl;
            res[i][j] = mxc;
            all += mx;
            mx = 0;
        }
    }

    cout << n * m - all << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i % k][j % k];
        }
        cout << "\n";
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