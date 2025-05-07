#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

void solve() {
    int n, m;
    int x, y, k;
    vector<pii> arr[101];
    int num[101] = { 0, };
    int deg[101] = { 0, };

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> k;
        arr[x].push_back(pii(y, k));
        deg[y]++;
    }

    queue<pii> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.push({ i, 1 });
        }
    }

    while (!q.empty()) {
        pii f = q.front();
        q.pop();

        if (arr[f.first].empty()) {
            num[f.first] = f.second;
        }
        for (pii next : arr[f.first]) {
            deg[next.first]--;
            num[next.first] += next.second * f.second;
            if (deg[next.first] == 0) {
                q.push({ next.first, num[next.first] });
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        if (arr[i].empty()) {
            cout << i << " " << num[i] << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}