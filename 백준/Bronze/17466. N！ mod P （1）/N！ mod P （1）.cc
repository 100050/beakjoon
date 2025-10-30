#include <iostream>
using namespace std;

using ll = long long;

int main() {
    ll n, p, res = 1;
    
    cin >> n >> p;
    for (ll i = 2; i <= n; i++) {
        res *= i;
        res %= p;
    }
    cout << res;
}