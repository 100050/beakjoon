#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
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

constexpr ll MOD = 1000000007;
//const ll MOD = 10007;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max();
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

vector<int> st;

int find_min_idx(ll node, int begin, int end) {
    if (begin == end) {
        return st[node] = begin;
    }

    int mid = (begin + end) / 2;

    int idx1 = find_min_idx(node * 2, begin, mid);
    int idx2 = find_min_idx(node * 2 + 1, mid + 1, end);

    cout << "? " << idx1 << " " << idx2 << endl;
    char res;
    cin >> res;
    if (res == '<') {
        return st[node] = idx1;
    }
    else {
        return st[node] = idx2;
    }
}

int find_2nd_min_idx(ll node, int begin, int end, int pre) {
    if (begin == end) {
        return pre;
    }

    int mid = (begin + end) / 2;
    int ret;
    if (st[node] == st[node * 2]) {
        cout << "? " << pre << " " << st[node * 2 + 1] << endl;
        
        char res;
        cin >> res;

        ret = find_2nd_min_idx(node * 2, begin, mid, (res == '<' ? pre : st[node * 2 + 1]));
    }
    else {
        cout << "? " << pre << " " << st[node * 2] << endl;

        char res;
        cin >> res;

        ret = find_2nd_min_idx(node * 2 + 1, mid + 1, end, (res == '<' ? pre : st[node * 2]));
    }

    return ret;
}

void solve(int CASE = -1) {
    int n;

    cin >> n;
    st.resize(4*n);

    int min_idx = find_min_idx(1, 0, n-1);

    int pre;
    int _2th_min_idx;
    if (st[1] == st[2]) {
        pre = st[3];
        _2th_min_idx = find_2nd_min_idx(2, 0, (n - 1) / 2, pre);
    }
    else {
        pre = st[2];
        _2th_min_idx = find_2nd_min_idx(3, (n - 1) / 2 + 1, n - 1, pre);
    }

    cout << "! " << _2th_min_idx << endl;
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