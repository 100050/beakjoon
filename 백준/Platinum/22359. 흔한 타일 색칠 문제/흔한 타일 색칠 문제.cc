#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <cstdlib>   
#include <ctime> 
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

vector<vector<char>> arr;

bool isNotDrain(int x, int y, int s) {
    for (int i = x; i < x + s; i++) {
        for (int j = y; j < y + s; j++) {
            if (arr[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}


void tile(int x, int y, int s, char color) {
    int half = s / 2;
    if (isNotDrain(x, y, half)) arr[x + half - 1][y + half - 1] = color;
    if (isNotDrain(x, y + half, half)) arr[x + half - 1][y + half] = color;
    if (isNotDrain(x + half, y, half)) arr[x + half][y + half - 1] = color;
    if (isNotDrain(x + half, y + half, half)) arr[x + half][y + half] = color;

    if (s == 2)return;

    if (s == 4) color = color + 1;

    tile(x, y, half, color);
    tile(x + half, y + half, half, color);

    if (s == 4) color = color + 1;

    tile(x + half, y, half, color);
    tile(x, y + half, half, color);
}

void solve() {
    int t, k;

    cin >> t >> k;

    k = 1 << k;

    while (t--) {
        int a, b;
        arr = vector<vector<char>>(k + 1, vector<char>(k + 1, 0));

        cin >> a >> b;

        arr[a - 1][b - 1] = '@';

        tile(0, 0, k, 'a');
        
        for (int j = 0; j < k; j++) {
            for (int i = 0; i < k; i++) {
                cout << arr[j][i];
            }
            cout << "\n";
        }
        
        arr.clear();
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