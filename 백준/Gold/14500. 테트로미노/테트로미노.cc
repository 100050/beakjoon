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

pii t[5][4] = {
    {pii(0, 0), pii(0, 1), pii(0, 2), pii(0, 3)},
    {pii(0, 0), pii(0, 1), pii(1, 0), pii(1, 1)},
    {pii(0, 0), pii(1, 0), pii(2, 0), pii(1, 1)},
    {pii(0, 0), pii(0, 1), pii(0, 2), pii(1, 2)},
    {pii(0, 0), pii(0, 1), pii(1, 1), pii(1, 2)},
};

void solve(int CASE = -1) {
    int n, m;
    int res = 0;
    vector<vector<int>> arr;

    cin >> n >> m;
    arr.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    pii s[4] = {
        pii(1, 1), pii(1, -1), pii(-1, 1), pii(-1, -1),
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int type = 0; type < 5; type++) {
                t[type];
                for (int rotate = 0; rotate < 2; rotate++) {
                    for (int symmetry = 0; symmetry < 4; symmetry++) {
                        pii& sy = s[symmetry];

                        int tmp = 0;
                        for (int k = 0; k < 4; k++) {
                            int y, x;
                            if (rotate == 1) {
                                y = i + sy.second * t[type][k].second;
                                x = j + sy.first * t[type][k].first;
                            }
                            else {
                                x = j + sy.second * t[type][k].second;
                                y = i + sy.first * t[type][k].first;
                            }
                            if (0 <= y && y < n && 0 <= x && x < m)
                                tmp += arr[y][x];
                        }
                        res = max(res, tmp);
                    }
                }
            }
        }
    }

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