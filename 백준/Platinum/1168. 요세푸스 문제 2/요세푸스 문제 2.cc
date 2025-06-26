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

vector<int> st;

void update(int x, int n) {
    int node = 1;
    int start = 1, end = n;

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

int find_and_delete(int left, int x, int start, int end, int node) {
    int ret;

    //cout << "in: " << left << " " << x << " "<< st[node*2] << " " << start << " " << end << "\n";
    if (start == end) {
        st[node]--;
        return end;
    }
    int mid = (start + end) / 2;
    
    if (st[node * 2] >= x)
        ret = find_and_delete(left, x, start, mid, node * 2);
    else 
        ret = find_and_delete(left, x - st[node * 2], mid + 1, end, node * 2 + 1);

    st[node] = st[node * 2] + st[node * 2 + 1];

    return ret;
}

int get(int left, int right, int start, int end, int node) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return st[node];

    int mid = (start + end) / 2;
    return get(left, right, start, mid, node * 2) +
        get(left, right, mid + 1, end, node * 2 + 1);
}

void solve() {
    int n, k;
    int x, t;

    cin >> n >> k;
    x = k;
    st.resize(1 << ((int)ceil(log2(n)) + 1));
    for (int i = 1; i <= n; i++) {
        update(i, n);
    }

    vector<int> res;
    int i = 0, left = 1, kk = k;
    while (i != n) {

        int tmp = get(left, n, 1, n, 1);
        //cout << "this " << tmp << "\n";
        while (kk - tmp > 0) {
            kk -= tmp;
            left = 1;
            tmp = get(left, n, 1, n, 1);
        }
        int t;
        if (left != 1) t = find_and_delete(left, get(1, left, 1, n, 1) + kk, 1, n, 1);
        else t = find_and_delete(left, kk, 1, n, 1);
        //cout << left << " " << kk << " " << t << "\n";
        left = t;
        kk = k;
        res.push_back(t);
        i++;
    }

    cout << "<";
    for (int i = 0; i < n-1; i++) {
        cout << res[i] << ", ";
    }
    cout << res[n - 1];
    cout << ">";

    
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