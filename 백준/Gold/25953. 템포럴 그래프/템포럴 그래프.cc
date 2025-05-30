#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;


void solve() {
    int n, t, m;
    int s, e, w, a, b;
    const int mx = 1000 * 10000 + 1;
    vector<pii> arr[10001];

    cin >> n >> t >> m;
    cin >> s >> e;
    vector<vector<int>> dist(2, vector<int>(n+1, mx));
    dist[0][s] = 0;
    for (int i = 0; i < t; i++) {
        //dist[(i + 1) % 2] = vector<int>(n + 1, mx);
        for (int j = 0; j < m; j++) {
            cin >> a >> b >> w;

            dist[(i+1)%2][b] = min(dist[i%2][a] + w, dist[(i+1)%2][b]);
            dist[(i+1)%2][a] = min(dist[i%2][b] + w, dist[(i+1)%2][a]);
            //cout << dist[i + 1][b]  << "\n";
        }
        for (int j = 0; j < n; j++) {
            dist[(i+1)%2][j] = min(dist[(i+1)%2][j], dist[i%2][j]);
        }
        
    }

    if (dist[t%2][e] == mx) dist[t%2][e] = -1;
    cout << dist[t%2][e];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}