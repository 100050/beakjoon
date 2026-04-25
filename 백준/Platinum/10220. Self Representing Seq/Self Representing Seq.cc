#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;

int arr[101] = { 0, 0, 0, 0, 2, 1, 0};

void solve() {
    int t, n;
    
    cin >> t;
    while (t--) {
        cin >> n;
        if (n <= 6)    
            cout << arr[n] << "\n";
        else
            cout << 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}