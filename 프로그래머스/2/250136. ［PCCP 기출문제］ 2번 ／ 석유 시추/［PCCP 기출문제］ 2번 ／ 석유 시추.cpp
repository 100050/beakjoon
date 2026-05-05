#include <string>
#include <vector>

using namespace std;

int dx[4] = {0 ,1, 0, -1};
int dy[4] = {-1 ,0, 1, 0};
int n, m;
int cnt = 2;
vector<int> c(cnt);

int dfs(int y, int x, vector<vector<int>>& land) {
    land[y][x] = cnt;
    int cc = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (0 <= ny && ny < n && 0 <= nx && nx < m
           && land[ny][nx] == 1) {
            cc += dfs(ny, nx, land);
        }
    }
    return cc;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    n = land.size(); m = land[0].size();
    // bfs로 모든 석유 덩어리를 저장
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (land[i][j] != 1) continue;
            
            c.push_back(dfs(i, j, land));
            cnt++;
        }
    }
    // 각 열에 대하여 시추관을 삽입해보며 얻을 수 있는 가장 많은 석유량을 저장
    int mx = 0;
    for (int i = 0; i < m; i++) {
        int cc = 0;
        vector<bool> visited(c.size());
        for (int j = 0; j < n; j++) {
            if (land[j][i] != 0 && !visited[land[j][i]]) {
                visited[land[j][i]] = true;
                cc += c[land[j][i]];
            }
        }
        mx = max(mx, cc);
    }
    
    return answer = mx;
}