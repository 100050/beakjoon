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

int table[20][100001][3]; // parent, min, max
int d[100001]; // depth, length
vector<pii> arr[100001]; // distance, node

void dfs(int node, int h, int pred) {

    d[node] = h;
    for (pii& next : arr[node]) {
        if (next.second != pred) {
        //cout << node << " " << pred << "\n";
            table[0][next.second][0] = node;
            table[0][next.second][1] = next.first;
            table[0][next.second][2] = next.first;
            dfs(next.second, h + 1, node);
        }
    }
}

void solve() {
    int m, n, a, b, c;

    cin >> n; 
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b >> c;
        arr[a].push_back(pii(c, b));
        arr[b].push_back(pii(c, a));
    }

    dfs(1, 0, -1); // depth 채우기
    table[0][1][1] = 1000001;

    // 테이블 채우기, 이 때 최대최저 같이 구하기
    for (int k = 1; k < 20; k++) { 
        for (int i = 1; i <= n; i++) {
            table[k][i][0] = table[k - 1][table[k - 1][i][0]][0];
            table[k][i][1] = min(table[k - 1][i][1], table[k - 1][table[k - 1][i][0]][1]);
            table[k][i][2] = max(table[k - 1][i][2], table[k - 1][table[k - 1][i][0]][2]);
        }
    }
    cin >> m;
    while (m--) {
        cin >> a >> b;
        
        if (d[a] < d[b]) {
            int tmp = a;
            a = b;
            b = tmp;
        } // a > b
        //cout << table[0][a][1] << " t " << table[0][b][1] << "\n";
        int mx = 0, mn = 1000001;
        if (d[a] == d[b]) {
            mx = max(table[0][a][2], table[0][b][2]), mn = min(table[0][a][1], table[0][b][1]);
        }
        for (int i = 20 - 1; i >= 0; i--) {
            if (pow(2, i) <= d[a] - d[b]) {
                mn = min(mn, table[i][a][1]);
                mx = max(mx, table[i][a][2]);
                a = table[i][a][0];
                //cout << a << " " << mn << " " << mx << "\n";
            }
        }

        if (a == b) {
            cout << mn << " " << mx << "\n";
            continue;
        }

        for (int i = 19; i >= 0; i--) {
            if (table[i][a][0] == table[i][b][0]) continue;
            mn = min(mn, table[i][a][1]);
            mn = min(mn, table[i][b][1]);
            mx = max(mx, table[i][a][2]);
            mx = max(mx, table[i][b][2]);
            a = table[i][a][0];
            b = table[i][b][0];
        }
        mn = min(mn, table[0][a][1]);
        mn = min(mn, table[0][b][1]);
        mx = max(mx, table[0][a][2]);
        mx = max(mx, table[0][b][2]);

        // 최소 최대 출력
        cout << mn << " " << mx << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}