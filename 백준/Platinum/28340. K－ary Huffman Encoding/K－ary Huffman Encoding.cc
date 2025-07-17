#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

struct Node {
    ll v = 0;
    vector<Node*> child;

    Node() = default;
    Node(int c) : v(c) {}
};

struct compare {
    bool operator()(Node* a, Node* b) {
        return a->v > b->v;
    }
};

void dfs(Node* node, ll length, ll& res) {
    
    if (node->child.empty()) {
        res += node->v * length;
    }

    for (Node* next : node->child) {
        dfs(next, length + 1, res);
    }
}

void solve() {
    int n, k, c;
    priority_queue<Node*, vector<Node*>, compare> pq;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> c;
        pq.push(new Node(c));
    }


    while (k != 2 && pq.size() % (k-1) != 1) pq.push(new Node(0));

    Node* root = nullptr;

    // 2 * sum
    // 1 * (a), 2 * sum

    // make tree
    while (true) {
        Node* node = new Node();

        for (int i = 0; i < k; i++) {
            Node* c = pq.top(); pq.pop();

            node->v += c->v;
            node->child.push_back(c);
            if (pq.empty()) {
                root = node;

                break;
            }
        }

        if (pq.empty()) {
            root = node;

            break;
        }

        pq.push(node);
        
    }


    ll res = 0;
    // dfs
    dfs(root, 0, res);


    cout << res << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}