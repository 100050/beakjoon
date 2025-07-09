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

int n;
vector<int> arr;

void solve() {
    
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int res = 0, len = 0, left = 0, right = 0;
    map<int, int> type;
    while (right < n) {
        len++;
        if (type.find(arr[right])->second == false)
            type[arr[right++]] = 1;
        else
            type[arr[right++]]++;

        while (type.size() > 2) {
            type[arr[left]]--;

            if (type[arr[left]] == 0) type.erase(arr[left]);
            left++;
            len--;
        }
        res = max(res, len);
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