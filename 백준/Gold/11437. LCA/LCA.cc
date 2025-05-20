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

int table[20][100001];
int d[100001];
vector<int> arr[100001];

void dfs(int node, int h, int pred) {

    d[node] = h;
    for (int next : arr[node]) {
        if (next != pred) {
        //cout << node << " " << pred << "\n";
            table[0][next] = node;
            dfs(next, h + 1, node);
        }
    }
}

void solve() {
    int m, n, a, b;

    cin >> n; 
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs(1, 0, -1); // depth 채우기

    // 테이블 채우기
    for (int k = 1; k < 20; k++) {
        for (int i = 1; i <= n; i++) {
            table[k][i] = table[k - 1][table[k - 1][i]];
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

        for (int i = 20 - 1; i >= 0; i--) {
            if (pow(2, i) <= d[a] - d[b])
                a = table[i][a];
        }

        if (a == b) {
            cout << a << "\n";
            continue;
        }

        for (int i = 19; i >= 0; i--) {
            if (table[i][a] == table[i][b]) continue;
            a = table[i][a];
            b = table[i][b];
        }

        cout << table[0][a] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}