#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;

const int mxK = 129;

int arr[mxK][mxK];
int idx;

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


void tile(int x, int y, int s) {
    ++idx;
    int half = s / 2;
    if (isNotDrain(x, y, half)) arr[x + half - 1][y + half - 1] = idx;
    if (isNotDrain(x, y + half, half)) arr[x + half - 1][y + half] = idx;
    if (isNotDrain(x + half, y, half)) arr[x + half][y + half - 1] = idx;
    if (isNotDrain(x + half, y + half, half)) arr[x + half][y + half] = idx;

    if (s == 2)return;

    tile(x, y, half);
    tile(x + half, y, half);
    tile(x, y + half, half);
    tile(x + half, y + half, half);
}

void solve() {
    int k, x, y;

    cin >> k >> x >> y;

    arr[y-1][x-1] = -1;
    int s = 1 << k;
    tile(0, 0, s);


    for (int j = s-1; j >= 0; j--) {
        for (int i = 0; i < s; i++) {
            cout << arr[j][i] << " ";
        }
        cout << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}