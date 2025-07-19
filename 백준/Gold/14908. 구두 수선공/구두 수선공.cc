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
    vector<pair<pii, int>> arr;
    int t, s;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t >> s;
        arr.push_back(make_pair(pii(t, s), i));
    }

    auto compare = [](const pair<pii, int>& a, const pair<pii, int>& b) {
        if (a.first.first * b.first.second > b.first.first * a.first.second) {
            return false;
        }
        else if (a.first.first * b.first.second < b.first.first * a.first.second){
            return true;
        }
        else {
            return a.second <= b.second;
        }
        };

    sort(arr.begin(), arr.end(), compare);
    
    
    for (auto r : arr) {
        cout << r.second << " ";
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