#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void solve() {
    int n;
    vector<string> arr;
    string num;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        arr.push_back(num);
    }

    auto compare = [](const string& a, const string& b) {
        return a + b > b + a;
        };

    sort(arr.begin(), arr.end(), compare);
    
    
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i == 0 && arr[i][0] == '0') break;
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