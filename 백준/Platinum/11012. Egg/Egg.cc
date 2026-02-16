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
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

vector<ll> st; // 4*n or 1 << ((int)ceil(log2(n)) + 1)으로 초기화

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
    int n, m;
    vector<pil> folk;
    vector<tuple<ll, int, pil>> parade;

    cin >> n >> m;
    folk.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> folk[i].first >> folk[i].second;
    }
    for (int i = 0; i < m; i++) {
        pil t;
        ll begin, end;
        cin >> begin >> end >> t.first >> t.second;

        parade.push_back(make_tuple(begin-1, -1, t));
        parade.push_back(make_tuple(end, 1, t));
    }

    sort(folk.begin(), folk.end());
    sort(parade.begin(), parade.end(), [](tuple<ll, int, pil>& a, tuple<ll, int, pil>& b) {
        return get<0>(a) < get<0>(b);
        });

    ll res = 0;
    int j = 0;
    st.resize(4 * 100'001);
    for (int i = 0; i < parade.size(); i++) {
        if (get<0>(parade[i]) == -1) continue;

        while (j != n && folk[j].first <= get<0>(parade[i])) {
            update(1, 0, 100'000, folk[j].second, 1);
            //cout << j << "\n";
            j++;
        }

        res += get<1>(parade[i]) * 
            get(1, 0, 100'000, get<2>(parade[i]).first, get<2>(parade[i]).second);
        //cout << get<2>(parade[i]).first << " " << get<2>(parade[i]).second << " " << res << "\n";
    }

    cout << res << "\n";
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