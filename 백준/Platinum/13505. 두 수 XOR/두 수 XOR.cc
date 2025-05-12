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
    Trie* node[2];
    Trie() {
        finish = false;
        for (int i = 0; i < 2; i++) {
            node[i] = nullptr;
        }
    }
};

void insert(Trie* node, string s, int d) {
    if (node->node[s[d] - '0'] == nullptr) {
        node->node[s[d] - '0'] = new Trie();
    }
    if (d == s.size() - 1) {
        node->node[s[d] - '0']->finish = true;
        return;
    }
    insert(node->node[s[d] - '0'], s, d+1);
}

unsigned int dfs(int d, string str, Trie* node) {
    unsigned int ret = 0;
    if (node->finish) {
        return 0;
    }
    if (node->node[0] != nullptr && node->node[1] != nullptr) {
        if (str[d] == '0') {
            ret = (1 << (str.size() - d - 1)) | dfs(d + 1, str, node->node[1]);
        }
        else {
            ret = dfs(d + 1, str, node->node[0]);
        }
    }
    else if (node->node[0] != nullptr) {
        ret =  dfs(d + 1, str, node->node[0]);
    }
    else if (node->node[1] != nullptr) {
        ret = (1<<(str.size()-d-1)) | dfs(d + 1, str, node->node[1]);
    }
    //cout << d << " " << ret << "\n";
    
    return ret;
}

string to_binary(unsigned int n) {
    string binary = "";
    while (n) {
        binary = (n & 1 ? "1" : "0") + binary;
        n = n >> 1;
    }
    while (binary.size() < 32) {
        binary = "0" + binary;
    }

    return binary;
}

void fini(Trie* node) {
    for (Trie* n : node->node) {
        if (n != nullptr)
            fini(n);
    }
    delete node;
}

void solve() {
    vector<unsigned int> arr;
    unsigned int k, n;
    string str;
    string mxB;
    Trie* root = new Trie();
    unsigned int mxN = 0;

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> n;
        arr.push_back(n);
    }

    for (int i = 0; i < k; i++) {
        str = to_binary(arr[i]);
        //cout << str << "\n";
        insert(root, str, 0);
    }
    
    for (int i = 0; i < k; i++) {
        str = to_binary(arr[i]);
        Trie* node = root;

        unsigned int res = dfs(0, str, node);
        //cout << (arr[i] ^ res) << "\n";
        if ((arr[i] ^ res) > mxN) mxN = arr[i] ^ res;
    }
    // 1101 = 1010 ^ 0100
    cout << mxN << "\n";
    
    fini(root);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}