#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <cstdlib>   
#include <ctime> 
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;


void solve() {
    ll x;
    ll left = 1, right = (long long)1e9;
    while (true) {
        cin >> x;

        if (left == right) {
            if (x == left) {
                cout << "=" << endl;
                break;
            }
            else if (x > left) {
                cout << "<" << endl;
            }
            else {
                cout << ">" << endl;
            }
            continue;
        }
        if (x < left) {
            cout << ">" << endl;
            continue;
        }
        if (x > right) {
            cout << "<" << endl;
            continue;
        }
        if (x - left > right - x) {
            right = x-1;
            cout << "<" << endl;
        }
        else {
            left = x+1;
            cout << ">" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}