#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ranges>
#include <numeric>
#include <cstring>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

constexpr ll MOD = 1000000007;
//const ll MOD = 10007;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max();
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

// a/b
void print(ll a, ll b) {
    if (b < 0) {
        a *= -1; b *= -1;
    }
    if (a == 0) {
        cout << 0 << "\n";
        return;
    }

    ll g = abs(gcd(a, b));
    a /= g, b /= g;


    if (b == 1) {
        cout << a << "\n";
        return;
    }
    if (a == 1) {
        cout << 0 << " " << b << "\n";
        return;
    }

    while (a != 1) {
        //cout << a << " " << b << "\n";
        if (a < 0) {
            cout << (a - b) / b << " ";
            a %= b;
            a = b + a;
        }
        else {
            cout << a / b << " ";
            a %= b;
        }

        swap(a, b);
    }
    cout << "\n";
}

void solve(int CASE = -1) {
    CASE = 0;
    while (true) {
        CASE++;
        int n, m;
        stack<int> x;

        cin >> n >> m;
        if (n == 0) return;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            x.push(t);
        }

        ll a1 = x.top(), b1 = 1; // c+b/a
        x.pop();
        while (x.size()) {
            ll c = x.top(); x.pop();
            c = c * a1 + b1;
            ll g = abs(gcd(c, a1));
            b1 = a1 / g;
            a1 = c / g;
        }

        for (int i = 0; i < m; i++) {
            int t;
            cin >> t;
            x.push(t);
        }

        ll a2 = x.top(), b2 = 1; // c+b/a
        x.pop();
        while (x.size()) {
            ll c = x.top(); x.pop();
            c = c * a2 + b2;
            ll g = abs(gcd(c, a2));
            b2 = a2 / g;
            a2 = c / g; 
        }

        // a2/b2

        cout << "Case " << CASE << ":\n";
        ll a, b;
        // 덧셈
        if (b1 == b2) {
            a = a1 + a2;
            b = b1;
        }
        else {
            ll g = abs(gcd(b1, b2));
            a = a1 * b2 / g + a2 * b1 / g;
            b = b1 * b2 / g;
        }
        print(a, b);

        // 뺄셈
        if (b1 == b2) {
            a = a1 - a2;
            b = b1;
        }
        else {
            ll g = abs(gcd(b1, b2));
            a = a1 * b2 / g - a2 * b1 / g;
            b = b1 * b2 / g;
        }
        print(a, b);
        //cout << "log\n";
        // 곱셈
        a = a1 * a2; b = b1 * b2;
        print(a, b);

        // 나눗셈
        a = a1 * b2; b = b1 * a2;
        print(a, b);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}