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


    for (int i = 1; i <= n; i+=2) // 홀수 1, 3, 5 ...
        cout << i << " ";
    for (int i = (n>>1)<<1; i > 0; i-=2) // 짝수 n, n-2, ...
        cout << i << " ";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}