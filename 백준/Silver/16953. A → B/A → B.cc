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
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int a, b;

void bfs(int start, int end, int time) {
    //queue<pii> q;
    pii t(start, time);

    //q.push(make_pair(start, time));
    while (true) {
        if (t.first == 0) {
            cout << -1;
            break;
        }
        if (t.first == end) {
            cout << (t.second + 1);
            break;
        }
        else {
            if (t.first % 10 == 1 && t.first / 10 >= end)
                t.first /= 10, t.second += 1;
            else if (t.first % 2 == 1)
                t.first = 0;
            else
                t.first /= 2, t.second += 1;
        }
    }
}

void solve(int CASE = -1) {

    cin >> a >> b;

    bfs(b, a, 0);


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