#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;


void solve() {
    string a, b, c;

    cin >> a >> b >> c;
    
    int num = 0;
    if (isdigit(a[0])) {
        num = stoi(a) + 3;
    }
    else if (isdigit(b[0])) {
        num = stoi(b) + 2;
    }
    else if (isdigit(c[0])) {
        num = stoi(c) + 1;
    }

    if (num % 5 == 0 && num % 3 == 0) {
        cout << "FizzBuzz";
    }
    else if (num % 5 == 0) {
        cout << "Buzz";
    }
    else if (num % 3 == 0) {
        cout << "Fizz";
    }
    else {
        cout << num;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}