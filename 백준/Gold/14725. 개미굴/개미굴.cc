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
    map<string, Trie*> node;
    Trie() {
        finish = true;
        node = map<string, Trie*>();
    }
};

void dfs(int d, Trie* node) {
    if (node->finish) {
        delete node;
        return;
    }
    for (auto n : node->node) {
        for (int i = 0; i < d; i++) {
            cout << "--";
        }
        cout << n.first << "\n";
        dfs(d + 1, n.second);
    }
    delete node;
}

void solve() {
    int n;
    int k;
    string s;
    Trie* root = new Trie();

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        Trie* node = root;
        for (int j = 0; j < k; j++) {
            cin >> s;
            if (node->finish) {
                node->node.insert(pair<string, Trie*>(s, new Trie()));
                node->finish = false;
                node = node->node[s];   
            }
            else {
                bool flag = false;
                for (auto n : node->node) {
                    if (n.first == s) {
                        flag = true;
                        node = n.second;
                        break;
                    }
                }
                if (flag) continue;
                auto it = node->node.insert(pair<string, Trie*>( s, new Trie() ));
                node = node->node[s];
                
            }
        }
    }

    Trie* node = root;
    
    dfs(0, node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}