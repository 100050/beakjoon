#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
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
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

const int MAX = 10000;

int n, A[MAX], B[MAX], dist[MAX];
bool used[MAX];
vector<int> adj[MAX];

// 호프크로프트 카프 전용 bfs 함수: A그룹의 각 정점에 레벨을 매김
void bfs() {
    queue<int> q;
    // 매칭에 안 속한 A그룹의 정점만 레벨 0인 채로 시작
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dist[i] = 0;
            q.push(i);
        }
        else dist[i] = INF<int>;
    }

    // BFS를 통해 A그룹 정점에 0, 1, 2, 3, ... 의 레벨을 매김
    while (!q.empty()) {
        int f = q.front(); q.pop();
        for (int b : adj[f]) {
            if (B[b] != -1 && dist[B[b]] == INF<int>) {
                dist[B[b]] = dist[f] + 1;
                q.push(B[b]);
            }
        }
    }
}

// 호프크로프트 카프 전용 dfs 함수: 새 매칭을 찾으면 true
bool dfs(int a) {
    for (int b : adj[a]) {
        // 이분 매칭 코드와 상당히 유사하나, dist 배열에 대한 조건이 추가로 붙음
        if (B[b] == -1 || dist[B[b]] == dist[a] + 1 && dfs(B[b])) {
            // used 배열 값도 true가 됨
            used[a] = true;
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}

void solve(int CASE = -1) {

    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            int dummy1, len;
            char dummy2;
            cin >> dummy1 >> dummy2 >> dummy2 >> len >> dummy2;
            for (int j = 0; j < len; j++) {
                int t;
                cin >> t;
                adj[i].push_back(t);
            }
        }

        int match = 0;
        fill(A, A + MAX, -1);
        fill(B, B + MAX, -1);
        while (1) {
            // 각 정점에 레벨을 매기고 시작
            bfs();

            // 이분 매칭과 비슷하게 A그룹 정점을 순회하며 매칭 증가량 찾음
            int flow = 0;
            for (int i = 0; i < n; i++)
                if (!used[i] && dfs(i)) flow++;

            // 더 이상 증가 경로를 못 찾으면 알고리즘 종료
            if (flow == 0) break;
            // 찾았을 경우 반복
            match += flow;
        }

        cout << match << "\n";

        fill(used, used + MAX, false);
        for (int i = 0; i < n; i++)
            adj[i].clear();
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