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

const ll MOD = 1000000007;
//const ll MOD = 10000000;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

vector<pil> st;


void update(ll node, int start, int end, int index, pil diff) {
    if (index < start || index > end) return;
    st[node].first = (st[node].first + diff.first) % MOD;
    st[node].second = (st[node].second + diff.second) % MOD;

    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

pil get(ll node, int start, int end, int left, int right) {
    if (left > end || right < start) return pil(0, 0);
    if (left <= start && end <= right) return st[node];

    int mid = (start + end) / 2;
    pil a = get(node * 2, start, mid, left, right);
    pil b = get(node * 2 + 1, mid + 1, end, left, right);
    return pil((a.first + b.first) % MOD, (a.second + b.second) % MOD);
}

struct Line {
    int x, y;
};

void solve(int CASE = -1) {
    int n;
    vector<Line> lines;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        lines.push_back({ x, y + 200000 });
    }


    sort(lines.begin(), lines.end(), [](Line& a, Line& b) {
        return a.x < b.x;
        });
    lines.push_back({ 1000000000, 0 });
    // x 좌표가 작은 것부터 차례대로 탐색
    ll res = 0;
    st.resize(400001 * 4);
    queue<pil> q;
    for (int i = 0; i < lines.size()-1; i++) {
        pil a(0, 0);
        if (lines[i].y != 400000)
            a = get(1, 0, 400001 - 1, lines[i].y + 1, 400000);
        pil b(0, 0);
        if (lines[i].y != 0)
            b = get(1, 0, 400001 - 1, 0, lines[i].y - 1);

        res = (res + b.first) % MOD;
        q.push(pil(a.second, i));
        //cout << "out: " <<  a.second << " " << b.first << " " << lines[i].y << "\n";
        if (lines[i].x != lines[i + 1].x) {
            while (q.size()) {
                update(1, 0, 400001 - 1, lines[q.front().second].y, pil(q.front().first, 1));
                q.pop();
            }
        }
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