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

vector<int> parent;
int res, g;

int Find(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(pair<int, pii>& x) {
    int a = Find(x.second.first), b = Find(x.second.second);

    if (a == b) return;

    parent[b] = a;
    res += x.first;
    g--;
}

void solve(int CASE = -1) {
    int n, m;
    vector<pair<int, pii>> arr;

    cin >> n >> m;
    arr.resize(m);
    parent.resize(n + 1);
    g = n;
    iota(parent.begin(), parent.end(), 0);
    for (int i = 0; i < m; i++) {
        cin >> arr[i].second.first >> arr[i].second.second >> arr[i].first;
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < m; i++) {
        if (g == 2) break;
        Union(arr[i]);
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