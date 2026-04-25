#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;

const int mxN = 501;

// 처음 행렬을 그래프의 간선으로 전부 표현
// 바뀐 등수를 보고 간선을 수정
// 최종적으로 사이클이 있는지 체크

void solve() {
    int n, m;
    int a, b;
    vector<int> teams;
    vector<int> arr[mxN];
    queue<int> q;

    cin >> n;
    vector<int> degree(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        teams.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            arr[teams[i]].push_back(teams[j]);
            degree[teams[j]]++;
        }
    }

    cin >> m;
    for (int i = 1; i <= m; i++) {
        bool flag = false;
        cin >> a >> b;

        for (int j = 0; j < arr[b].size(); j++) {
            if (arr[b][j] == a) {
                arr[a].push_back(b);
                arr[b].erase(arr[b].begin()+j);
                degree[a]--;
                degree[b]++;
                flag = true;
                break;
            }
        }
        if (flag) continue;
        for (int j = 0; j < arr[a].size(); j++) {
            if (arr[a][j] == b) {
                arr[b].push_back(a);
                arr[a].erase(arr[a].begin() + j);
                degree[b]--;
                degree[a]++;
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (q.empty()) {
            cout << "IMPOSSIBLE\n";
            return;
        }

        int x = q.front();
        q.pop();

        //cout << x << " ";
        res.push_back(x);
        for (int y : arr[x]) {
            if (--degree[y] == 0) {
                q.push(y);
            }
        }
    }

    for (int r : res) {
        cout << r << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}