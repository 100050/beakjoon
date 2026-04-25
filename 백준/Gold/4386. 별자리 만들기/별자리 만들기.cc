#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;

vector<pil> point;
vector<int> visited;
priority_queue<pil,
    vector<pil>,
    greater<pil>> pq;

void mst(double& ans) {
    pq.push({ 0, 0 });
    while (pq.size()) {
        int idx = pq.top().second;
        if (visited[idx]) {
            pq.pop();
            continue;
        }
        auto top = point[idx];
        ans += sqrt(pq.top().first);
        visited[idx] = 1;
        pq.pop();
        
        for (int i = 0; i < point.size(); i++) {
            if (visited[i]) continue;
            auto& node = point[i];
            long long d = pow(node.first-top.first, 2) + pow(node.second - top.second, 2);
            pq.push({ d, i });
        }
    }
}

void solve() {
    int n;
    double a, b;
    double ans = 0;
    cin >> n;

    visited = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;

        point.push_back({ a * 100, b * 100 });
    }

    mst(ans);

    cout.precision(3);
    cout << ans / 100;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();


    return 0;
}