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
    
vector<int> d;
int arr[2501];

void solve() {
    int k, n;

    cin >> k >> n;

    for (int i = 2; i * i <= 2500; i++) {
        if (arr[i] == 0) {
            for (int j = 2; j * i <= 2500; j++) {
                arr[i * j] = 1;
            }
        }
    }

    for (int i = 2500; i >= 2; i--) {
        if (arr[i] == 0) {
            d.push_back(i);
        }
        if (d.size() >= k) break;
    }

    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            cout << d[i] * j << " ";
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