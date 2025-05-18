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


int nca(int a, int b, int arr[], bool visited[]) {
    while (arr[a] != 0) {
        visited[a] = true;
        a = arr[a];
    }
    while (arr[b] != 0 && visited[b] == false) {
        visited[b] = true;
        b = arr[b];
    }
    
    return b;
}

void solve() {
    int arr[10001] = { 0, };
    bool visited[10001] = { 0, };
    int n, a, b;

    cin >> n; 
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        arr[b] = a;
    }
    cin >> a >> b;

    cout << nca(a, b, arr, visited) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}