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

vector<pii> arr;

void solve() {
    int n;
    int x, y;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        arr.push_back(make_pair(x, y));
    }

    sort(arr.begin(), arr.end());

    int res = 0;
    int begin, end;
    tie(begin, end) = arr[0];
    for (int i = 1; i < n; i++) {
        pii& a = arr[i];
        if (begin <= a.first && a.first <= end && a.second > end) {
            end = a.second;
        }
        else if (end < a.first) {
            res += end - begin;
            end = a.second;
            begin = a.first;
        }
    }

    cout << res + end - begin;
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