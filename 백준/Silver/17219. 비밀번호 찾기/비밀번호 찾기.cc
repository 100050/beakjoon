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

const int mxN = 100001;

void solve() {
    map<string, string> note;
    string password, site;
    int n, m;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> site >> password;
        note[site] = password;
    }
    for (int i = 0; i < m; i++) {
        cin >> site;
        cout << note[site] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}