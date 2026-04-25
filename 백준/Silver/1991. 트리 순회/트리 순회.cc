#include <iostream>
#include <vector>
#include <string>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

vector<pii> tree(27);
string pret, inot, post;

void traversal(int node) {
    if (node == -1) return;

    pret += (node + 'A');
    
    traversal(tree[node].first);

    inot += (node + 'A');

    traversal(tree[node].second);

    post += (node + 'A');
}

void solve() {
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b, c;
        cin >> a >> b >> c;


        tree[a - 'A'] = { b - 'A', c - 'A' };

        if (b == '.') {
            tree[a - 'A'].first = -1;
        }
        if (c == '.') {
            tree[a - 'A'].second = -1;
        }
    }

    traversal(0);

    cout << pret << "\n" << inot << "\n" << post << "\n";



}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();


    return 0;
}