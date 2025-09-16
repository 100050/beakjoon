#include <iostream>
using namespace std;

using ll = long long;

int main() {
    ll s;
    
    cin >> s;
    s *= 2;
    ll i = 1;
    while (true) {
        if (i*(i+1) > s) {
            cout << i-1;
            break;
        }
        i++;
    }
    
    return 0;
}