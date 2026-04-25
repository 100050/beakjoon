#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;


void solve() {
    int n;
    int arr[301][301];
    int a, b;
    int an = 0;

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;

        if (a == 1 || b == 1) an++;
    }

    // 1번 정점이랑 모든 정점 연결
    // 최소 거리는 2, n <= 4일 때는 k = 1
    if (n == 2) {
        cout << 0 << "\n" << 1;
    }
    else if (n <= 4) {
        cout << ((n-1)*(n-2)/2) << "\n";
        cout << 1 << "\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (arr[i][j] == 0) {
                    cout << i << " " << j << "\n";
                    arr[i][j] = 1;
                    arr[j][i] = 1;
                }
            }
        }
    }
    else {
        cout << (n - 1 - an) << "\n";
        cout << 2 << "\n";
        for (int i = 2; i <= n; i++) {
            if (arr[1][i] == 0) {
                cout << 1 << " " << i << "\n";
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