#include <iostream>
using namespace std;

int n;

void dfs(int d) {
    if (d == n) {
        for (int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << "\n";
        return;
    }
    
    for (int i = 0; i < n - d; i++) {
        cout << " ";
    }
    for (int i = 0; i < d; i++) {
        cout << "*";
    }
    cout << "\n";
    dfs(d + 1);
    
    for (int i = 0; i < n - d; i++) {
        cout << " ";
    }
    for (int i = 0; i < d; i++) {
        cout << "*";
    }
    cout << "\n";
}

int main() {
    
    cin >> n;
    
    dfs(1);
}