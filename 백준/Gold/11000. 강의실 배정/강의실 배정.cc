#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
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
    int n;
    vector<pii> arr;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;

        arr.push_back(make_pair(s, 1));
        arr.push_back(make_pair(e, -1));
    }

    sort(arr.begin(), arr.end(), [](const pii& a, const pii& b) {
        if (a.first == b.first) return a.second < b.second;
        else return a.first < b.first;
        });

    int res = 0, mx = 0;    
    for (pii& t : arr) {
        if (t.second == 1) {
            res++;
            mx = max(mx, res);
        }
        else {
            res--;
        }
    }

    cout << mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    //pre();
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}