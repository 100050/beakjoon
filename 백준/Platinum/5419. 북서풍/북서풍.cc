#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ranges>
#include <numeric>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

//const ll MOD = 1000000007;
const ll MOD = 10000000;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

vector<ll> st;

void update(ll node, int start, int end, int index, ll diff) {
    if (index < start || index > end) return;
    st[node] += diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

ll get(ll node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return st[node];

    int mid = (start + end) / 2;
    return get(node * 2, start, mid, left, right)
        + get(node * 2 + 1, mid + 1, end, left, right);
}

void solve(int CASE = -1) {
    int n;
    vector<pii> coord;

    cin >> n;
    coord.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> coord[i].first >> coord[i].second;
    }

    // y축 좌표 압축
    vector<int> newY(n);
    
    sort(coord.begin(), coord.end(), [](pii& a, pii& b) {
        return a.second < b.second;
        });

    int t = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && coord[i].second != coord[i - 1].second) t++;
        newY[i] = t;
    }
    for (int i = 0; i < n; i++) {
        coord[i].second = newY[i];
    }

    // x축을 기준으로 정렬, x 값이 같다면 y좌표가 작아지는 순으로 정렬
    sort(coord.begin(), coord.end(), [](pii& a, pii& b) {
        if (a.first == b.first) return a.second > b.second;
        else return a.first < b.first;
        });

    // x 좌표가 작은 것부터 차례대로 탐색
    ll res = 0;
    st.resize(n*4, 0);
    for (int i = 0; i < n; i++) {
        res += get(1, 0, n - 1, coord[i].second, t);
        update(1, 0, n - 1, coord[i].second, 1);
    }
    
    cout << res << "\n";

    coord.clear();
    newY.clear();
    st.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}