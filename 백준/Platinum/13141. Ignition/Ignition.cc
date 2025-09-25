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
#include <cstring>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

const ll MOD = 1000000007;
//const ll MOD = 10007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int n, m;
vector<int> adj[201][201];
// 정점을 방문한 시간 저장
int when[201];

ld dijkstra(int start) {
    // (시간, 정점)
    using pidi = pair<ld, int>;
    ld mx = 0;
    priority_queue<pidi, vector<pidi>, greater<pidi>> pq;

    pq.push(make_pair(0, start));
    while (pq.size()) {
        pidi top = pq.top(); pq.pop();
        
        if (when[top.second] == -1) {
            mx = max(mx, top.first);
            when[top.second] = top.first;
        }
        else {
            continue;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < adj[top.second][i].size(); j++) {
                int d = adj[top.second][i][j];
                if (d == 0) continue;

                if (top.second == i) {
                    mx = max(mx, top.first + d / 2.0L);
                    //if (start == 4) cout << top.second << " " << i << " " << top.first << " " << d << "\n";
                    continue;
                }
                else if (when[i] != -1) {
                    if (when[i] + d - top.first > 0) {
                        mx = max(mx, (when[i] + d - top.first) / 2.0L + top.first);
                    }
                    continue;
                }

                pq.push(make_pair(top.first + d, i));
            }
            //if (start == 4) cout << top.second << " " << mx << "\n";
        }
    }

    return mx;
}

void solve(int CASE = -1) {

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, e, l;
        cin >> s >> e >> l;
        
        adj[s][e].push_back(l);
        adj[e][s].push_back(l);
    }

    ld res = numeric_limits<ld>::max();
    // 모든 정점을 다익스트라로 시도
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            when[j] = -1;

        res = min(res, dijkstra(i));
    }

    cout.precision(1);
    cout << fixed;

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