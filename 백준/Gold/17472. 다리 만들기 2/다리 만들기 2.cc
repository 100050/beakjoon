#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;

vector<int> uf;
int n, m;

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

void bfs(int x, int y, int map[10][10], int& lands) {
    int dx[] = { 0, -1, 1, 0 };
    int dy[] = { -1, 0, 0, 1 };
    queue<pii> que;
    que.push({ x, y });
    map[x][y] = lands;
    while (que.size()) {
        pii f = que.front();
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nx = f.first + dx[i];
            int ny = f.second + dy[i];
            if (0 > nx || nx >= n || 0 > ny || ny >= m) continue;
            if (map[nx][ny] != 1) continue;

            map[nx][ny] = lands;
            //cout << nx << " " << ny << "\n";
            que.push({ nx, ny });
        }
    }
    lands++;
}

void solve() {
    int a;
    int lands = 2;
    int map[10][10] = { 0, };
    int ans = 0;
    vector<tuple<int, int, int>> edge;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    // bfs로 모든 섬 탐색
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] != 1) continue;

            bfs(i, j, map, lands);
            //cout << i << " " << j << " " << lands << "\n";
        }
    }

    // 간선 찾기
    int dx[] = {0, -1, 1, 0};
    int dy[] = {-1, 0, 0, 1};        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) continue;

            int x = i;
            int y = j;

            int land = map[x][y];
            if (land == 0) continue;
            for (int k = 0; k < 4; k++) {
                int nx = x;
                int ny = y; 

                int bridge = 0;

                while (true) {
                    //if (map[nx][ny] == land) break;

                    if (0 > nx + dx[k] || nx + dx[k] >= n || 0 > ny + dy[k] || ny + dy[k] >= m) break;
                    nx += dx[k];
                    ny += dy[k];

                    if (map[nx][ny] != 0) break;
                    bridge++;

                }

                if (map[nx][ny] == 0) continue;
                if (map[nx][ny] == land) continue;

                if (bridge >= 2) {
                   //cout << bridge  << " " << map[nx][ny] << " " << land << "\n";
                    edge.push_back(make_tuple(bridge, map[nx][ny], land));
                }
            }
        }
    }

    uf = vector<int>(lands);
    for (int i = 2; i < lands; i++) {
        uf[i] = i;
    }

    sort(edge.begin(), edge.end());

    for (auto e : edge) {
        int a = Find(get<1>(e));
        int b = Find(get<2>(e));
        if (a == b) continue;

        Union(a, b);
        ans += get<0>(e);
        //cout << get<0>(e) << " " << a << " " << b << "\n";
    }

    int root = Find(2);
    int i;
    for (i = 3; i < lands; i++) {
        if (root != Find(i)) {
            break;
        }
    }

    if (i == lands)
        cout << ans << "\n";
    else
        cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}