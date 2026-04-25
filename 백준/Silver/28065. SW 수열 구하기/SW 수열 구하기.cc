#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;

void solve() {
    int n;

    cin >> n;

    int up = n, down = 1;
    while (up > down) {
        cout << up << " " << down << " ";
        up--;
        down++;
    }
    if (up == down) cout << up;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}