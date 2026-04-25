#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

const int mxN = 10001;
vector<pil> arr;

void solve() {
    int n;
    
    ll x, y;
    ll S = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        //cin >> x >> y;
        scanf("%ld %ld", &x, &y);
        arr.push_back({ x, y });
    }
    for (int i = 0; i < n; i++) {
        S += (arr[i].first + arr[(i + 1) % n].first) * (arr[i].second - arr[(i + 1) %n].second);
    }

    if (S < 0) S *= -1;
    printf("%.1lf", S / 2.0);
//    cout << S / 2.0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}