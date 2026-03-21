#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    vector<int> s, arr;

    cin >> n >> m;
    arr.resize(n + 1); s.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        s[i] = s[i - 1] + arr[i];
    }

    while (m--) {
        int i, j;
        cin >> i >> j;

        cout << s[j] - s[i-1] << "\n";
    }

    return 0;
}