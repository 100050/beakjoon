#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;

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
    
    while (true) {
        int n, m;
        int a, b, c;
        int ans = 0;
        int all = 0;
        vector<tuple<int, int, int>> edge;
        cin >> n >> m;

        if (n == 0) break;

        uf = vector<int>(n + 1);
        for (int i = 0; i < n; i++) {
            uf[i] = i;
        }
        for (int i = 1; i <= m; i++) {
            cin >> a >> b >> c;

            all += c;
            edge.push_back({ c ,a, b });
        }
sort(edge.begin(), edge.end(),[](tuple<int, int, int> &a, tuple<int, int, int> &b){return get<0>(a) < get<0>(b);});

        for (auto e : edge) {
            int a = Find(get<1>(e));
            int b = Find(get<2>(e));
            if (a == b) continue;

            Union(a, b);
            ans += get<0>(e);
            //cout << get<0>(e) << " " << a << " " << b << "\n";
        }

        cout << all - ans << "\n";
        uf.clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}