#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;
const ll mod = 1000000007;


struct V {
    int x, y;
    ll w;
};

vector<ll> ans;
vector<V> v;
vector<int> parent;
vector<int> _size;
vector<map<ll, ll>> vec;

int Find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y, ll w) {
    int xx = Find(x);
    int yy = Find(y);

    if (xx == yy) return;
    
    if (_size[xx] < _size[yy]) {
        int tmp = xx;
        xx = yy;
        yy = tmp;
    }
    parent[yy] = xx;
    _size[xx] += _size[yy];
    _size[yy] = 0;

    for (auto itr : vec[yy]) {
        if (vec[xx].find(itr.first) != vec[xx].end()) {
            ans[itr.first] += vec[xx][itr.first] * itr.second * w;
        }
        else vec[xx][itr.first] = 0;

        vec[xx][itr.first] += itr.second;
        vec[yy].erase(itr.first);
    }

}

void solve() {
    int n, k, m;

    cin >> n >> k >> m;
    parent.resize(n + 1);
    _size.resize(n + 1);
    v.resize(m);
    ans.resize(k + 1);
    vec.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        parent[i] = i;
        _size[i] = 1;
        vec[i][tmp] = 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> v[i].x >> v[i]. y >> v[i].w;
    }

    sort(v.begin(), v.end(), [&](const V& a, const V& b) { return a.w > b.w; });

    for (int i = 0; i < m; i++) {
        Union(v[i].x, v[i].y, v[i].w);
    }

    for (int i = 1; i <= k; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}