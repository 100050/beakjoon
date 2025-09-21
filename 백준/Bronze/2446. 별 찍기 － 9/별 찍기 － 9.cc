#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ranges>
#include <numeric>
#include <cstring>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

const ll MOD = 1000000007;
//const ll MOD = 10007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int n;
void dfs(int d) {
    if (d == n - 1) {
        for (int i = 0; i < d; i++) {
            cout << " ";
        }
        cout << "*\n";
        return;
    }

    for (int i = 0; i < d; i++) {
        cout << " ";
    }
    for (int i = 0; i < 2 * n - 1 - 2 * d; i++) {
        cout << "*";
    }
    cout << "\n";

    dfs(d + 1);
    
    for (int i = 0; i < d; i++) {
        cout << " ";
    }
    for (int i = 0; i < 2 * n - 1 - 2 * d; i++) {
        cout << "*";
    }
    cout << "\n";

}

void solve(int CASE = -1) {

    cin >> n;
    dfs(0);
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