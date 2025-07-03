#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

const ll divisor = 1e9 + 7;
vector<ll> fact(3e5 + 10, 1);

ll power(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % divisor;
        a = (a * a) % divisor;
        b >>= 1;
    }
    return ret;
}

ll inv(ll n) {
    return power(n, divisor - 2); // 역원
}

ll ncr(ll n, ll r) {
    return (fact[n] * inv((fact[r] * fact[n - r]) % divisor)) % divisor;
}


ll catalan(ll n) {
    return (ncr(2*n, n) * inv(n + 1)) % divisor;
}

void solve() {
    // a ? b : c ? d : e ? f : h
    // (()())() -> 4가지 경우(곱)
    // 1 2 6 24
    // n!
    string expr;
    ll ans;
    stack<char> s;

    cin >> expr;

    for (int i = 1; i <= 3e5 + 10; i++) {
        fact[i] = (i * fact[i - 1]) % divisor;
    }

    ans = 1;
    for (char c : expr) {
        if (c == ':') {
            if (!s.empty() && s.top() == ':') {
                
                ll cnt = 0;
                while (s.size() >= 3) {
                    char p = s.top();
                    s.pop();
                    char pp = s.top();
                    
                    if (pp == '?' && p == ':') {
                        s.pop();
                        cnt++;
                    }
                    else {
                        s.push(p);
                        break;
                    }
                }

                //cout << catalan(1) << endl;
                ans = (ans * catalan(cnt)) % divisor;
            }
        }

        if (c == ':' || c == '?') s.push(c);
    }

    ll cnt = 0;
    while (s.size()) {
        char p = s.top();
        s.pop();
        char pp = s.top();

        if (pp == '?' && p == ':') {
            s.pop();
            cnt++;
        }
        else {
            s.push(p);
            break;
        }
    }

    //cout << catalan(2) << endl;
    ans = (ans * catalan(cnt) % divisor) % divisor;

    cout << ans;

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