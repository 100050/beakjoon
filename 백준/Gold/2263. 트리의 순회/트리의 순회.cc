#include <iostream>
#include <vector>
#include <string>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

vector<int> in, post;

void rTree(int inIdx, int postIdx, int size) {
    //cout << inIdx << " " << size << "\n";
    if (size == 0) return;
    else if (size == 1) {
        cout << in[inIdx] << " ";

        return;
    }

    int i;
    int root = post[postIdx + size - 1];
    for (i = 0; i < size; i++) {
        if (root == in[i + inIdx]) {
            break;
        }
    }
    cout << root << " ";
    // 0, i-1   i, post.size() - 2

    rTree(inIdx, postIdx, i);
    rTree(inIdx + i + 1, postIdx + i, size - i - 1);
}

void solve() {
    int n, a;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        in.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        cin >> a;
        post.push_back(a);
    }

    rTree(0, 0, n);



    //    traversal(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();


    return 0;
}