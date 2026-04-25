#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

void solve() {
    unsigned int s = 0;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        string oper;
        int x;
        cin >> oper;

        if (oper == "add") {
            cin >> x;
            s |= 1 << x;
        }
        else if (oper == "remove") {
            cin >> x;
            s &= ~(1 << x);
        }
        else if (oper == "check") {
            cin >> x;
            if (s & (1 << x))
                cout << 1;
            else
                cout << 0;
            cout << "\n";
        }
        else if (oper == "toggle") {
            cin >> x;
            if (s & (1 << x))
                s &= ~(1 << x);
            else
                s |= 1 << x;
        }
        else if (oper == "all") {
            s = 0b111111111111111111111;
        }
        else if (oper == "empty") {
            s = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}