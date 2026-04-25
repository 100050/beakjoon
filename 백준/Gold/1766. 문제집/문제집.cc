#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;

const int mxN = 32001;
vector<int> arr[mxN];
vector<int> deg;

// 바뀐 부분 연결
// 위상 정렬을 하는데 같은 위상일 시 우선순위 큐로 처리

void solve() {
    int n, m;
    int a, b;
    
    cin >> n >> m;
    deg = vector<int>(n+1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a].push_back(b);
        deg[b]++;
    }

    priority_queue<int, vector<int> ,greater<int>> q;

    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        int x = q.top();
        q.pop();
        
        cout << x << " ";

        for (int y : arr[x]) {
            if (--deg[y] == 0) {
                q.push(y);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}