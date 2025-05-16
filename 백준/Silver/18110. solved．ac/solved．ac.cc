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

vector<int> F;


void solve() {
    int n;
    vector<int> arr;

    cin >> n;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());
    int b = floor(arr.size() * 0.15+0.5);
    long double sum = 0;
    //cout << b;
    for (int i = b; i < arr.size() - b; i++) {
        sum += arr[i];
    }

    if (n == 0) cout << 0;
    else cout << floor(sum / (n-2*b)+0.5);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}