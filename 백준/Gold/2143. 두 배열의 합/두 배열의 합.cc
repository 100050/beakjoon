#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <ranges>
#include <numeric>
#include <cstring>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

constexpr ll MOD = 1000000007;
//const ll MOD = 10007;
const ld PI = acos(-1.0L);
template<typename T>
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };


void solve(int CASE = -1) {
    ll t;
    int n, m;
    vector<ll> a, b;

    cin >> t;
    cin >> n;
    a.resize(n); 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    b.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    unordered_map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        ll sm = 0;
        for (int j = i; j < n; j++) {
            sm += a[j];
            mp[sm]++;
        }
    }

    
    ll res = 0;
    for (int i = 0; i < m; i++) {
        ll sm = 0;
        for (int j = i; j < m; j++) {
            sm += b[j];
            res += mp[t - sm];
        }
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);

    }

    return 0;
}