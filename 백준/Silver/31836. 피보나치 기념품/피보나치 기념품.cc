#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;


void solve() {
    int n;
    vector<int> A, B;

    cin >> n;
    while (n >= 3) {
        A.push_back(n);
        B.push_back(n-1);
        B.push_back(n-2);
        n -= 3;
    }
    if (n == 2) {
        A.push_back(2);
        B.push_back(1);
    }

    cout << A.size() << "\n";
    for (int a : A)
        cout << a << " ";
    cout << "\n";
    cout << B.size() << "\n";
    for (int b : B)
        cout << b << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}