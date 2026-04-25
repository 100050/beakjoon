#include <iostream>
using namespace std;

int main() {
    int n, f;
    
    cin >> n >> f;
    
    int nn = (n / 100) * 100;
    int i = 0;
    for (i = 0; i <= 99; i++) {
        if ((nn + i) % f == 0) {
            break;
        } 
    }
    
    if (i / 10 == 0) cout << "0";
    cout << i << "\n";
    return 0;
    
}