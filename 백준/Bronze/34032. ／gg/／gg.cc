#include <iostream>
using namespace std;

int main() {
    int n;
    char c;
    int O = 0, X;
    cin >> n;
    X = n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == 'O') O++;
    }
    X -= O;
    if (X > O) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }
}