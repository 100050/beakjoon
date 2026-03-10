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

int ccw(const pil& a, const pil& b, const pil& c) {
    // 3개의 점이 주어질 때
    ll op = a.first * b.second + b.first * c.second + c.first * a.second;
    op -= (a.second * b.first + b.second * c.first + c.second * a.first);

    if (op > 0) return 1;
    else if (op == 0)return 0;
    else return -1;
}

bool isIntersect(pair<pil, pil> l1, pair<pil, pil> l2) {

    pil p1 = l1.first;
    pil p2 = l1.second;
    pil p3 = l2.first;
    pil p4 = l2.second;

    ll p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4); // l1 기준
    ll p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2); // l2 기준

    // 두 직선이 일직선 상에 존재
    if (p1p2 == 0 && p3p4 == 0) {
        // 비교를 일반화하기 위한 점 위치 변경
        if (p1 > p2) swap(p2, p1);
        if (p3 > p4) swap(p3, p4);

        return p3 <= p2 && p1 <= p4; // 두 선분이 포개어져 있는지 확인
    }

    return p1p2 <= 0 && p3p4 <= 0;

}

const int MAX = 300 + 3;
array<vector<int>, MAX> adj;
array<array<int, MAX>, MAX> flow, cap;

int maxFlow(int start, int end) {
    int total{ 0 };

    while (true) {
        queue<int> q;
        array<int, MAX> par{ 0, };
        // v + e
        q.push(start);
        while (!q.empty()) {
            int f{ q.front() }; q.pop();

            for (const int nxt : adj[f]) {
                if (par[nxt] == 0 && cap[f][nxt] - flow[f][nxt] > 0) {
                    par[nxt] = f;
                    q.push(nxt);
                }
            }
        }

        if (par[end] == 0) break;

        int amount{ INF<int> };
        for (int v{ end }; v != start; v = par[v])
            amount = min(amount, cap[par[v]][v] - flow[par[v]][v]);

        for (int v{ end }; v != start; v = par[v]) {
            flow[par[v]][v] += amount;
            flow[v][par[v]] -= amount;
        }

        total += amount;
    }

    return total;
}

void insert_edge(int a, int b, int cost) {
    adj[a].push_back(b);
    adj[b].push_back(a);
    cap[a][b] = cost;
}

void solve(int CASE = -1) {
    int n, k, h, m;
    vector<pil> corner, hole, mouse;

    cin >> n >> k >> h >> m;
    corner.resize(n);
    hole.resize(h);
    mouse.resize(m);
    for (int i = 0; i < n; i++) {
        cin >> corner[i].first >> corner[i].second;
    }
    corner.push_back(corner[0]);
    for (int i = 0; i < h; i++) {
        cin >> hole[i].first >> hole[i].second;
    }
    for (int i = 0; i < m; i++) {
        cin >> mouse[i].first >> mouse[i].second;
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < m; j++) {
            bool flag = false;
            for (int k = 0; k < n; k++) {
                if (ccw(corner[k], corner[k + 1], hole[i]) == 0) continue;
                flag = flag || isIntersect(
                    make_pair(hole[i], mouse[j]),
                    make_pair(corner[k], corner[k + 1])
                );
            }

            if (flag) continue;

            insert_edge(j + 1 + 2, i + 1 + 2 + m, 1);
        }
    }

    for (int i = 0; i < h; i++) {
        insert_edge(i + 1 + 2 + m, 2, k);
    }
    for (int i = 0; i < m; i++) {
        insert_edge(1, i + 1 + 2, 1);
    }

    cout << (maxFlow(1, 2) == m ? "Possible" : "Impossible");
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