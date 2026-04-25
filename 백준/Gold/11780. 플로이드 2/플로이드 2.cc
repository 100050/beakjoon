#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int mxN = 101;
const int mxD = 100 * 100000 + 1;

int arr[mxN][mxN];
int dist[mxN][mxN];
int link[mxN][mxN];

void f(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    link[i][j] = link[i][k];
                }
            }
        }
    }
}

void findPath(int s, int e, vector<int>& tmp) {
    if (s != e) {
        int next = link[s][e];
        if (next == 0) return;
        tmp.push_back(s);
        findPath(next, e, tmp);
    }
}

void solve() {
    int n, m;
    int a, b, c;

    cin >> n >> m;
    fill(&dist[0][0], &dist[n][n], mxD);
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        link[i][i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (dist[a][b] > c) {
            arr[a][b] = c;
            link[a][b] = b;
            dist[a][b] = c;
        }
    }

    f(n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mxD == dist[i][j]) {
                cout << "0 ";
                continue;
            }
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            vector<int> tmp;
            
            findPath(i, j, tmp);
            
            //tmp.push_back(j);
            if (tmp.empty()) {
                cout << "0\n";
                continue;
            }
            cout << tmp.size()+1 << " ";
            for (int t : tmp)
                cout << t << " ";

            cout << j << "\n";
        }
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();


    return 0;
}