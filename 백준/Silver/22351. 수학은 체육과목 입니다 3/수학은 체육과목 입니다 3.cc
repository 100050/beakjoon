#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <cstdlib>   
#include <ctime> 
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;


void solve() {
    string s;
    int a = 10000, b;

    cin >> s;

    int num = 0, num2 = 0;
    int ii, i;
    int ss;
    int beg = s.size() >= 3 ? 3 : s.size();
    for (i = beg; i >= 1; i--) {
        num = 0;
        num2 = 0;
        ii = i;
        for (int k = 0; k < ii; k++) {
            num *= 10;
            num += s[k] - '0';
        }


        int k = 0;
        //num = a;
        int aa = num;
        bool flag = false;
        for (; k < s.size();) {
            //cout << to_string(num) << " " << s.substr(k, ii) << endl;
            if (to_string(num) != s.substr(k, ii)) {
                flag = true;
                break;
            }
            num++;
            k += ii;
            if (num / (int)pow(10, ii) != 0) ii++;
        }
        if (flag) continue;

        if (aa < a) {
            a = aa;
            b = num - 1;
        }
    }


    cout << a << " " << b;
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