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
    int n, l;
    ll a, idx, min = 1e9;
    deque<pii> dq;
    vector<int> result;

    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        //dq.push_back({a, i});


        // 뒤 쪽
        while (true) {
            if (dq.size() && a < dq.back().first) {
                dq.pop_back();
            }
            else {
                dq.push_back({ a, i });
                if (dq.size() == 1) min = a;
                break;
            }
        }

        // 앞 쪽
        pii f = dq.front();
        if (i > l && f.second <= i - l) {
            dq.pop_front();
            if (min == f.first) {
                min = dq.front().first;
            }
        }

        result.push_back(min);
    }

    for (int r : result) {
        cout << r << " ";
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