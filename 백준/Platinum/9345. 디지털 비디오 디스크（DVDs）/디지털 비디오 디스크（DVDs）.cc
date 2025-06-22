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

vector<int> arr;
vector<pii> st;

pii make_st(int node, int start, int end) {
    if (start == end)
        return st[node] = pii(arr[start], arr[start]);
    int mid = (start + end) / 2;
    pii left = make_st(node * 2, start, mid);
    pii right = make_st(node * 2 + 1, mid + 1, end);
    st[node] = pii(min(left.first, right.first), max(left.second, right.second));

    return st[node];
}

void update(int node, int start, int end, int index, int ne) {
    if (index < start || index > end) return;
    if (start == end) st[node] = pii(ne, ne);

    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, ne);
        update(node * 2 + 1, mid + 1, end, index, ne);
        st[node] = pii(min(st[node * 2].first, st[node * 2 + 1].first),
            max(st[node * 2].second, st[node * 2 + 1].second));
    }
}

pii get(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return pii(1000000001, -1);// todo
    if (left <= start && end <= right) return st[node];

    int mid = (start + end) / 2;

    pii l = get(node * 2, start, mid, left, right);
    pii r = get(node * 2 + 1, mid + 1, end, left, right);
    return pii(min(l.first, r.first), max(l.second, r.second));

}
void solve() {
    int n, k;
    int q, a, b;

    cin >> n >> k;
    arr.resize(n);
    st.resize(1 << ((int)ceil(log2(n)) + 1));
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    make_st(1, 0, n - 1);
    // 세그먼트 트리에 원래 위치와의 거리를 저장
    while (k--) {
        cin >> q >> a >> b;
        if (q == 0) {
            update(1, 0, n - 1, a, arr[b]);
            update(1, 0, n - 1, b, arr[a]);
            swap(arr[b], arr[a]);
        }
        else {
            pii ret = get(1, 0, n-1, a, b);
            //cout << ret.first << " " << ret.second << "\n";
            if (ret.first == a and ret.second == b)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    arr.clear();
    st.clear();
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