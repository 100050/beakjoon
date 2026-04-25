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
    string str;

    cin >> n >> str;
    
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < str.length(); i++) {
            cout << str[(i+j) % str.length()];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}