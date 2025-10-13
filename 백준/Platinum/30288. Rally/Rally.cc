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
#include <cstring>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

constexpr ll MOD = 1000000007;
//const ll MOD = 10007;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max();
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int n, m;
vector<int> adj[5000+1];
int adjn[5001][5001];

void solve(int CASE = -1) {

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // 모든 i, j 쌍에 대하여 이 둘과 직접적으로 연결된 정점이 2개가 있는지 확인
    int res[4] = { 0, };
    for (int i = 1; i <= n; i++) {
        for (int next : adj[i]) {
            for (int nnext : adj[next]) {
                if (i == nnext) continue;

                if (adjn[i][nnext] == 0) {
                    adjn[i][nnext] = next;
                    adjn[nnext][i] = next;
                }
                else if (adjn[i][nnext] != next) {
                    res[0] = i;
                    res[1] = next;
                    res[2] = nnext;
                    res[3] = adjn[i][nnext];

                    cout << "TAIP\n";
                    for (int i = 0; i < 4; i++)
                        cout << res[i] << " ";

                    return;
                }
            }
        }
    }

    cout << "NE";
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