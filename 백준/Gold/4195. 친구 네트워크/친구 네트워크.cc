#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

unordered_map<string, int> m;
vector<pii> root;

int Find(int n) {
    if (root[n].first == n)
        return n;
    else {
        root[n].first =  Find(root[n].first);
        root[n].second = root[root[n].first].second;
        return root[n].first;
    }
}

void Union(int a, int b) {

    int aa = Find(a);
   // cout << "27\n";
    int bb = Find(b);
    if (aa != bb) {
        root[bb].first = aa;
        root[aa].second += root[bb].second;
    }
}

void solve() {
    int n, idx = 0;
    string a, b;
    cin >> n;

    for (int i = 0; i < n*2; i++) {
        root.push_back({ i, 1 });
    }
    for (int i = 0; i < n; i++) {
        cin >> a >> b;

        if (m.find(a) == m.end()) m[a] = idx++;
        if (m.find(b) == m.end()) m[b] = idx++;
        int ma = m[a], mb = m[b];
        Union(ma, mb);

        cout << root[Find(ma)].second << "\n";
    }
    root.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();


    return 0;
}