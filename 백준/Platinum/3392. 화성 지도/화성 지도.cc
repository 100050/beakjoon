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
vector<ll> len;

void update(ll node, int start, int end, int left, int right, ll diff) {
    if (left > end || right < start) return;
    if (left <= start && end <= right) st[node] += diff;
    else {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, left, right, diff);
        update(node * 2 + 1, mid + 1, end, left, right, diff);
    }

    if (st[node] > 0) len[node] = end - start + 1;
    else if (end == start) len[node] = 0;
    else len[node] = len[node * 2] + len[node * 2 + 1];
}

ll get() {
    return len[1];
}

struct Line {
    int x, y1, y2, d;
};

void solve(int CASE = -1) {
    int n;
    vector<Line> lines;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lines.push_back({ x1, y1, y2, 1 });
        lines.push_back({ x2, y1, y2, -1 });
    }

    sort(lines.begin(), lines.end(), [](Line& a, Line& b) {
        return a.x < b.x;
        });

    // x 좌표가 작은 것부터 차례대로 탐색
    ll res = 0, px = lines[0].x;
    st.resize(30000 * 4, 0);
    len.resize(30000 * 4, 0);
    for (int i = 0; i < lines.size(); i++) {
        res += (lines[i].x - px) * get();
        //cout << px << " " << lines[i].x << " " << get() << "\n";
        update(1, 0, 30000-1, lines[i].y1, lines[i].y2-1, lines[i].d);
        px = lines[i].x;
    }
    
    cout << res << "\n";
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