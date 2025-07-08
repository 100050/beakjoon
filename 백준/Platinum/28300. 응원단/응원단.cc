#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

const ll MOD = 1000000007;
const ld PI = acos(-1.0L);

int n, q;
int r1, c1, r2, c2;
string pattern; // 응원 패턴
int arr[1001][1001]; // 초기 위치
pii g[2][2]; // 홀짝 그룹의 y, x
// 0,0 짝짝 0,1 짝홀 1,0 홀짝 1,1 홀홀

void solve() {
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = n * (i-1) + j;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            g[i][j] = pii(0, 0);
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> pattern;

        if (pattern == "S") { // 교체
            cin >> r1 >> c1 >> r2 >> c2;
            
            pii& p1 = g[r1 % 2][c1 % 2];
            pii& p2 = g[r2 % 2][c2 % 2];
            auto cal = [&](int a, int b) { return (a + n - b) % n ? (a + n - b) % n : n; };
            r1 = cal(r1, p1.first);
            c1 = cal(c1, p1.second);
            r2 = cal(r2, p2.first);
            c2 = cal(c2, p2.second);
            swap(arr[r1][c1], arr[r2][c2]);
        }
        else if (pattern == "RO") { // 홀수 행 이동
            g[1][0].second = (g[1][0].second + 1) % n;
            g[1][1].second = (g[1][1].second + 1) % n;
            swap(g[1][0], g[1][1]);
        }
        else if (pattern == "RE") { // 짝수 행 이동
            g[0][0].second = (g[0][0].second + 1) % n;
            g[0][1].second = (g[0][1].second + 1) % n;
            swap(g[0][0], g[0][1]);
        }
        else if (pattern == "CO") { // 홀수 열 이동
            g[0][1].first = (g[0][1].first + 1) % n;
            g[1][1].first = (g[1][1].first + 1) % n;
            swap(g[0][1], g[1][1]);
        }
        else if (pattern == "CE") { // 짝수 열 이동
            g[0][0].first = (g[0][0].first + 1) % n;
            g[1][0].first = (g[1][0].first + 1) % n;
            swap(g[0][0], g[1][0]);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pii& p = g[i % 2][j % 2];
            //cout << p.first << " " << p.second << "\n";
            auto cal = [&](int a, int b) { return (a + n - b) % n ? (a + n - b) % n : n; };
            int r = cal(i, p.first);
            int c = cal(j, p.second);
            cout << arr[r][c] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}