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

constexpr ll MOD = 1000000007;
//const ll MOD = 10007;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max();
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n, t;
ll arr[100][100];
vector<ll> dist(30000, INF<ll>);

void dijkstra(int y, int x) {
    priority_queue<tuple<ll, int, int>, 
        vector<tuple<ll, int, int>>, 
        greater<tuple<ll, int, int>>> pq;

    dist[y*n + x] = 0;
    pq.push(make_tuple(0LL, 1, y * n + x));
    while (pq.size()) {
        auto [d, c, coef] = pq.top();  pq.pop();
        coef %= n * n;
        //if (coef / n == n - 1 && coef % n == n - 1) continue;

        for (int i = 0; i < 4; i++) {
            int ny = coef / n + dy[i];
            int nx = coef % n + dx[i];
            int tc = c;

            if (0 <= ny && ny < n && 0 <= nx && nx < n) {
                ll nxt_d = d + t;
                int nxt_n = (c-1)*n*n +  ny * n + nx;
                if (c == 3) nxt_d += arr[ny][nx], tc = 0;
                if (dist[nxt_n] > nxt_d) {
                    if (coef / n != n - 1 || coef % n != n - 1)
                        pq.push(make_tuple(nxt_d, tc + 1, nxt_n));
                    dist[nxt_n] = nxt_d;
                }
            }
        }
    }

}

void solve(int CASE = -1) {

    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    dijkstra(0, 0);
    
    ll res = min(dist[n*n + (n - 1) * n + n - 1], dist[(n - 1) * n + n - 1]);
    res = min(res, dist[2*n*n + (n - 1) * n + n - 1]);
    cout << res;
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