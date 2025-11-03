#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
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
constexpr T INF = numeric_limits<T>::max();
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

void solve(int CASE = -1) {
    int n;
    vector<int> arr;

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    
    vector<int> diff;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            diff.push_back(arr[j] - arr[i]);
        }
    }

    int g = diff[0];
    for (int i = 1; i < diff.size(); i++) {
        g = gcd(g, diff[i]);
    }

    // g의 약수 구하기
    set<int> s;
    s.insert(g);
    for (int i = 2; i * i <= g; i++) {
        if (g % i == 0) s.insert(i), s.insert(g / i);
    }

    for (auto iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << " ";
    }
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