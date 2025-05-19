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

int arr[20][200001];

void solve() {
    int m, n, x, q;

    cin >> m; 
    for (int i = 0; i < m; i++) {
        cin >> x;
        arr[0][i+1] = x;
    }
    for (int k = 1; k <= 19; ++k) {
        for (int i = 1; i <= m; ++i) {
            int tmp = arr[k - 1][i];

            arr[k][i] = arr[k - 1][tmp];
        }
    }
    cin >> q;
    while (q--) {
        cin >> n >> x;
        
        int num = 0;

        while (n) {
            //cout << n << "\n";
            if (n & 1) {
                x = arr[num][x];
            }
            num++;
            n = n >> 1;
        }

        cout << x << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}