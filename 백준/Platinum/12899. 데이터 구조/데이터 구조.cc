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

vector<int> st(1 << ((int)ceil(log2(2000000)) + 1));

void update(int x) {
    int node = 1;
    int start = 1, end = 2000000;

    while (start != end) {
        int mid = (start + end) / 2;
        st[node]++;
        if (mid >= x) {
            node = node << 1;
            end = mid;
        }
        else {
            node = (node << 1) | 1;
            start = mid + 1;
        }
    }
    st[node]++;
}

int find_and_delete(int x) {
    int ret;
    int node = 1;
    int start = 1, end = 2000000;

    while (start != end) {
        st[node]--;
        if (st[node * 2] >= x) {
            node = node << 1;
            end = (start + end) / 2;
        }
        else {
            x -= st[node * 2];
            node = (node << 1) | 1;
            start = (start + end) / 2 + 1;
        }
    }
    st[node]--;

    ret = start;

    return ret;
}

void solve() {
    int n;
    int x, t;

    cin >> n;
    while (n --) {
        cin >> t >> x;
        if (t == 1) {
            update(x);
        }
        else {
            cout << find_and_delete(x) << "\n";
        }
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