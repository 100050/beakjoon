#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

void solve() {
    int n, s, t, p;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < 6; i++) {
        cin >> s;
        arr.push_back(s);
    }
    cin >> t >> p;
    int T = 0, P = 0, PP = 0;
    for (int i = 0; i < 6; i++) {
        T += arr[i] / t + (arr[i] % t != 0);
    }

    P = n / p;
    PP = n % p;

    cout << T << "\n";
    cout << P << " " << PP;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}