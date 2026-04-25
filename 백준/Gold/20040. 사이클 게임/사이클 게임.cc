#include <iostream>
#include <vector>
#include <string>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

vector<int> root;

int Find(int n) {
    if (root[n] == n)
        return n;
    else {
        root[n] = Find(root[n]);
        return root[n];
    }
}

bool Union(int a, int b) {

    int aa = Find(a);
   // cout << "27\n";
    int bb = Find(b);
    if (aa == bb) {
        return true;
    }
    root[bb] = aa;
    return false;
}

void solve() {
    int n, m;
    int a, b;
    int ans = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        root.push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;

        if (Union(a, b) and ans == 0) {
            ans = i;
            break;
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();


    return 0;
}