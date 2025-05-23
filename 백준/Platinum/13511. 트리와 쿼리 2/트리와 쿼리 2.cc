#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

const int mxN = 100001;

ll table[20][mxN][2];
vector<pii> arr[mxN];
int depth[mxN];

void dfs(int node, int h, int pre) {
    depth[node] = h;

    for (pii no : arr[node]) {
        if (no.second != pre) {
            table[0][no.second][0] = node;
            table[0][no.second][1] += no.first;
            dfs(no.second, h + 1, node);
        }
    }
}

void solve() {
    int n, m, u, v, k, w;

    cin >> n; 
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> w;
        arr[u].push_back({ w, v });
        arr[v].push_back({ w, u });
    }

    dfs(1, 0, -1);

    for (int i = 1; i < 20; i++) {
        for (int j = 1; j < mxN; j++) {
            table[i][j][0] = table[i - 1][table[i - 1][j][0]][0];
            table[i][j][1] = table[i - 1][j][1] + table[i - 1][table[i - 1][j][0]][1];
        }
    }

    cin >> m;
    int q;
    while (m--) {
        cin >> q;
        cin >> u >> v;

        if (q == 1) {  // 경로 길이
            if (depth[u] < depth[v]) {
                int tmp = u;
                u = v;
                v = tmp;
            } // a > b
            ll res = 0;

            for (int i = 20 - 1; i >= 0; i--) {
                if (pow(2, i) <= depth[u] - depth[v]) {
                    res += table[i][u][1];
                    u = table[i][u][0];
                }
            }

            if (u == v) {
                cout << res << "\n";
                continue;
            }

            for (int i = 19; i >= 0; i--) {
                if (table[i][u][0] == table[i][v][0]) continue;
                res += table[i][u][1];
                res += table[i][v][1];
                u = table[i][u][0];
                v = table[i][v][0];
            }

            res += table[0][u][1];
            res += table[0][v][1];

            cout << res << "\n";
        } 
        else { // k번째 정점
            cin >> k;
            //int pv = v, pu = u;
            int res = 1;

            auto f = [&](int u, int v) {
                if (depth[u] < depth[v]) {
                    int tmp = u;
                    u = v;
                    v = tmp;
                } // a > b
                for (int i = 20 - 1; i >= 0; i--) {
                    if (pow(2, i) <= depth[u] - depth[v]) {
                        u = table[i][u][0];
                    }
                }

                if (u == v) {
                    return u;
                }

                for (int i = 19; i >= 0; i--) {
                    if (table[i][u][0] == table[i][v][0]) continue;
                    u = table[i][u][0];
                    v = table[i][v][0];
                }

                return (int)table[0][u][0];
            };
            
            int par = f(u, v);
            for (int i = 20 - 1; i >= 0; i--) {
                int p = pow(2, i);
                if (p <= depth[u] - depth[par] && k >= res + p) {
                    res += p;
                    u = table[i][u][0];
                }
            }
            if (res == k) {
                cout << u << "\n";
                continue;
            }
            
            //cout << res << " ";
            k = depth[v] - depth[par] - (k - res);
            res = 0;
            for (int i = 20 - 1; i >= 0; i--) {
                int p = pow(2, i);
                if (p <= depth[v] - depth[par] && k >= res + p) {
                    res += p;
                    v = table[i][v][0];
                }
            }

            cout << v << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}