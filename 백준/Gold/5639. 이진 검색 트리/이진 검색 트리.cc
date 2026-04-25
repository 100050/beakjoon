#include <iostream>
#include <vector>
#include <string>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

vector<int> pre;

void rTree(int idx, int size) {
    //cout << inIdx << " " << size << "\n";
    if (size == 0) return;
    else if (size == 1) {
        cout << pre[idx] << "\n";

        return;
    }

    int i;
    int root = pre[idx];
    for (i = 1; i < size; i++) {
        if (root < pre[i + idx]) {
            break;
        }
    }
    // 0, i-1   i, post.size() - 2

    rTree(idx+1, i - 1);
    rTree(idx + i, size - i);
    cout << root << "\n";

}

void solve() {
    int n, a;

    while(true){
        cin >> a;
        if (cin.eof()) break;

        pre.push_back(a);
    }

    rTree(0, pre.size());



    //    traversal(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();


    return 0;
}