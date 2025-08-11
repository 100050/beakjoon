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
#include <numeric>
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

int n, m;
vector<pii> home, chicken;

int dfs(int depth, int pre, vector<int> l) {
    if (depth == m) {
        int s = 0;
        for (int i : l) {
            s += i;
        }
        return s;
    }

    int s = 1000000000;
    for (int i = pre+1; i < chicken.size(); i++) {
        vector<int> nl(l.size());
        for (int j = 0; j < home.size(); j++) {
            nl[j] = min(l[j], abs(chicken[i].first - home[j].first) + abs(chicken[i].second - home[j].second));
        }
        s = min(dfs(depth + 1, i, nl),s);
        //cout << depth << " " << s << "\n";
    }

    return s;
}

void solve(int CASE = -1) {
    vector<int> l;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int t;
            cin >> t;
            if (t == 1) {
                home.push_back(make_pair(i, j));
                l.push_back(100000000);
            }
            else if (t == 2) {
                chicken.push_back(make_pair(i, j));
            }
        }
    }

    int res = dfs(0, -1, l);

    cout << res;
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