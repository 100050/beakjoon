    #include <iostream>
    #include <vector>
    #include <array>
    #include <algorithm>
    #include <string>
    #include <cmath>
    #include <map>
    #include <set>
    #include <queue>
    #include <stack>
    #include <ranges>
    using namespace std;

    using ll = long long;
    using ld = long double;
    using pii = pair<int, int>;
    using pil = pair<ll, ll>;
    using pid = pair<ld, ld>;

    const ll MOD = 1000000007;
    const ld PI = acos(-1.0L);
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, -1, 0, 1 };

    vector<int> par, sz;
    vector<ll> e, d, sum;
    vector<int> node;
    vector<vector<int>> graph;
    int pv;

    int Find(int x) {
        if (par[x] == x) return x;
        else return par[x] = Find(par[x]);
    }

    void Union(int a, int b) {
        int aa = Find(a);
        int bb = Find(b);
        pv++;
        graph[pv].push_back(node[aa]);
        graph[pv].push_back(node[bb]);
        //cout << aa << " " << bb << "\n";
        par[bb] = aa;
        sz[aa] += sz[bb];
        sz[bb] = 0;

        node[aa] = pv;
    }

    void Use(int x, ll c) {
        e[x] += c;
        d[node[Find(x)]] += c / sz[Find(x)];
    }

    void dfs(int no) {
        sum[no] += d[no];
        //cout << no << " " << sum[no] << "\n";
        for (int next : graph[no]) {
            sum[next] += sum[no];
            dfs(next);
        }
    }

    void solve(int CASE = -1) {
        int n, m;

        cin >> n >> m;
        par.resize(n + 1);
        sz.resize(n + 1);
        e.resize(n + 1);
        d.resize(2 * n + 1);
        sum.resize(2 * n + 1);
        node.resize(n + 1);
        graph.resize(2 * n + 1);
        pv = n;
        for (int i = 1; i <= n; i++) par[i] = i, node[i] = i, sz[i] = 1;
        while (m--) {
            int q, x, y, c;
            cin >> q;
            if (q == 1) {
                cin >> x >> y;

                Union(x, y);
            }
            else {
                cin >> x >> c;

                Use(x, c);
            }
        }

        dfs(node[Find(1)]);

        vector<array<ll, 3>> res;
        for (int i = 2; i <= n; i++) {
            ll v = sum[i] - e[i];
            if (v > 0) res.push_back({ i, 1LL, v });
            else if (v < 0) res.push_back({ 1LL, i, -v });
            //cout << i << " " << v << "\n";
        }

        cout << res.size() << "\n";
        for (array<ll, 3> r : res) {
            cout << r[0] << " " << r[1] << " " << r[2] << "\n";
        }
    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL), cout.tie(NULL);

        int t = 1;
        //cin >> t;
        for (int i = 1; i <= t; i++) {
            solve(i);
        }

        return 0;
    }