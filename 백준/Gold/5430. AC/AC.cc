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

deque<int> xs;

void parse(string x, int n) {
    int idx = 0;

    x = x.substr(1);
    x = x.substr(0, x.size() - 1);
    for (int i = 0; i < n; i++) {
        string tmp = x.substr(idx, x.find(',', idx) - idx);
        idx = x.find(',', idx) + 1;
        //cout << idx << " " << tmp << "\n";
        xs.push_back(stoi(tmp));
    }
}

void solve() {
    string p;
    int n;
    string x;

    cin >> p;
    cin >> n;
    cin >> x;
    parse(x, n);

    bool r = false;
    for (char f : p) {
        if (f == 'D') {
            if (xs.size() == 0) {
                cout << "error\n";
                xs.clear();
                return;
            }
            if (r) xs.pop_back();
            else xs.pop_front();
        }
        else {
            r = !r;
        }
    }

    cout << "[";
    while(xs.size()) {
        if (r) {
            int tmp = xs.back();
            xs.pop_back();
            cout << tmp;
        }
        else {
            int tmp = xs.front();
            xs.pop_front();
            cout << tmp;
        }
        if (xs.size() != 0) cout << ",";
    }
    cout << "]\n";

    xs.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}