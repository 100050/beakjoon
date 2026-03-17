#include <iostream>
using namespace std;

int main() {
    int a, b;
    int t;
    
    cin >> t;
    while (t--) {
    
    cin >>a >> b;
        b %= 4;
        b += 4;
        int x = 1;
        while (b--) {
            x = (x * a) % 10;
        }
        cout << (x == 0 ? 10 : x) << "\n";
    }
}