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

class Trie {
public:
    bool finish;
    int child;
    Trie* node[26];
    Trie() {
        finish = false;
        child = 0;
        for (int i = 0; i < 26; i++) {
            node[i] = nullptr;
        }
    }
};

int s = 0;

void insert(Trie* node, string s, int d) {
    if (node->node[s[d] - 'a'] == nullptr) {
        node->child++;
        node->node[s[d] - 'a'] = new Trie();
    }
    if (d == s.size() - 1) {
        node->node[s[d] - 'a']->finish = true;
        return;
    }
    insert(node->node[s[d] - 'a'], s, d+1);
}

void dfs(int d, int count, Trie* node) {
    //cout << d << " " <<  count << "\n";
    if (node->finish) {
        s += count;
    }
    for (auto n : node->node) {
        if (n != nullptr) {
            if (d == 0 || node->child > 1 || node->finish)
                dfs(d + 1, count+1, n);
            else
                dfs(d + 1, count, n);
        }
    }
    delete node;
}

void solve() {

    while (true) {
        int k;
        string str;
        Trie* root = new Trie();
        s = 0;
        cin >> k;
        if (cin.eof()) return;
        for (int j = 0; j < k; j++) {
            cin >> str;

            insert(root, str, 0);
        }
        Trie* node = root;

        dfs(0, 0, node);

        cout << fixed;
        cout.precision(2);
        cout << (long double)s / k << "\n";
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}