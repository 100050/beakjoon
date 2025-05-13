#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

struct node {
    int sz;
    node* c[2];
    node() { sz = 0; c[0] = c[1] = nullptr; }
    void insert(ll v, int d) {
        sz++; if (d == 60) return;
        if (!c[v % 2]) c[v % 2] = new node();
        c[v % 2]->insert(v / 2, d + 1);
    }
};

int DFS(node* T, int take) {
    if (!T || T->sz == take) return 0;
    if (!T->c[0] && !T->c[1]) return T->sz - take;
    auto l = T->c[0], r = T->c[1];
    if (!l) return DFS(r, take + 1) + 1;
    if (!r) return DFS(l, take + 1) + 1;
    return max(DFS(l, max(0, take - r->sz) + 1), DFS(r, max(0, take - l->sz) + 1)) + 1;
}

void fini(node* n) {
    if (n->c[0] != nullptr) {
        fini(n->c[0]);
    }
    if (n->c[1] != nullptr) {
        fini(n->c[1]);
    }
    delete n;
}

void solve() {
    ll a, n;
    cin >> n;
    node* T = new node;
    for (int i = 0; i < n; i++) {
        cin >> a;
        T->insert(a, 0);
    }
    cout << DFS(T, 0);

    fini(T);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}