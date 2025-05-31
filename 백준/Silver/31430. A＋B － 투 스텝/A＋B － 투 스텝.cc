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
    int t;
    ll a, b;

    cin >> t;
    if (t == 1) {
        cin >> a >> b;
        ll s = a + b;
        string outp = "";
        int n = 0;
        while (s) {
            outp = (char)('a' + (s % 26)) + outp;
            s /= 26;
            n++;
        }

        for (int i = n; i < 13; i++) {
            outp = 'a' + outp;
        }

        cout << outp << endl;
    }
    else {
        string inp;
        ll s = 0;
        cin >> inp;

        for (int i = 0; i < inp.size(); i++) {
            s *= 26;
            s += (inp[i] - 'a');
        }


        cout << s << endl;
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