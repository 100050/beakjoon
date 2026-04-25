#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <ranges>
#include <numeric>
#include <cstring>
#include <bit>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

constexpr ll MOD = 1000000007;
//constexpr ll MOD = 1000000000;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

int n, m;
int adj[1000][1000], res[1000][1000];
int cnt = 2;
int c[1000*1000 + 2];

void dfs(int i, int j) {
    c[cnt]++;
    adj[i][j] = cnt;

    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];

        if (0 <= ni && ni < n && 0 <= nj && nj < m && !adj[ni][nj])
            dfs(ni, nj);
    }
}

void solve(int CASE = -1) {
    cin >> n >> m;
    cin.get();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            adj[i][j] = cin.get() - '0';
        }
        cin.get();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (adj[i][j] == 0) dfs(i, j), cnt++;
        }
    }

    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (adj[i][j] == 1) {
                res[i][j] = 1;
                unordered_map<int, bool> visited;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (0 <= ni && ni < n && 0 <= nj && nj < m && adj[ni][nj] >= 2 && !visited[adj[ni][nj]])
                        res[i][j] += c[adj[ni][nj]], visited[adj[ni][nj]]=true;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j] % 10;  
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    //pre();
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}