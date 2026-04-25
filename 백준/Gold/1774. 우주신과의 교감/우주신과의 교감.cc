#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;

vector<pii> point;
vector<int> uf;

int Find(int x) {
    if (x == uf[x]) return x;
    else {
        return uf[x] = Find(uf[x]);
    }
}

void Union(int a, int b) {
    int aa = Find(a);
    int bb = Find(b);

    if (aa == bb) return;

    uf[bb] = aa;
}

void solve() {
    int n, m;
    int a, b;
    double ans = 0;
    vector<tuple<long long, int, int>> edge;
    
    cin >> n >> m;

    uf = vector<int>(n+1);
    point.push_back({ 0,0 });
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
      
        point.push_back({ a, b });
        uf[i] = i;
    }

    for (int i = 1; i < point.size(); i++) {
        for (int j = i+1; j < point.size(); j++) {
            long long d = pow(point[i].first - point[j].first, 2) + pow(point[i].second - point[j].second, 2);
            edge.push_back(make_tuple(d, i, j));
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        Union(a, b);
        
    }

    sort(edge.begin(), edge.end());

    for (auto e : edge) {
        int a = Find(get<1>(e));
        int b = Find(get<2>(e));
        if (a == b) continue;

        Union(a, b);
        ans += sqrt(get<0>(e));
        //cout << get<0>(e) << " " << a << " " << b << "\n";
    }

    cout << fixed;
    cout.precision(2); 
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();


    return 0;
}