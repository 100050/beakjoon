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

vector<int> parent;

int Find(int x) {
    if (parent[x] == -1) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    int aa = Find(a);
    int bb = Find(b);

    if (aa == bb) return; 

    parent[bb] = aa;
}

void solve() {
    int r, c, R, C;
    char d;

    cin >> r >> c;
    R = 2 * r;
    C = 2 * c;
    parent.resize(R * C * 2, -1);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> d;

            int arr[8] = { 
                2 * i * C + 2 * j,
                2 * i * C + 2 * j + 1,
                (2 * i + 1) * C + 2 * j,
                (2 * i + 1)* C + 2 * j + 1,
                C * R + 2 * i * C + 2 * j,
                C * R + 2 * i * C + 2 * j + 1,
                C * R + (2 * i + 1)* C + 2 * j,
                C * R + (2 * i + 1)* C + 2 * j + 1
            };

            if (d == 'O') {
                Union(arr[0], arr[4]);
                Union(arr[1], arr[5]);
                Union(arr[2], arr[6]);
                Union(arr[3], arr[7]);
            }
            else if (d == 'I') {
                Union(arr[0], arr[2]);
                Union(arr[1], arr[3]);
                Union(arr[4], arr[6]);
                Union(arr[5], arr[7]);
            }
            else {
                Union(arr[0], arr[1]);
                Union(arr[2], arr[3]);
                Union(arr[4], arr[5]);
                Union(arr[6], arr[7]);
            }
            if (0 < i) {
                Union(arr[0], arr[0] - C);
                Union(arr[1], arr[1] - C);
                Union(arr[4], arr[4] - C);
                Union(arr[5], arr[5] - C);
            }

            //cout << i << " " << j << endl;
            if (0 < j) {
                Union(arr[0], arr[0] - 1);
                Union(arr[2], arr[2] - 1);
                Union(arr[4], arr[4] - 1);
                Union(arr[6], arr[6] - 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < R * C * 2; i++) {
        if (parent[i] == -1) ans++;
    }

    cout << ans;
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