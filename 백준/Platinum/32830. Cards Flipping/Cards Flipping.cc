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

vector<int> p(1000001);
vector<pii> c(1000001, pii(0, 1));
// (개수, 집합 크기)

int Find(int x) {
    if (x == p[x]) return p[x];
    else return p[x] = Find(p[x]);
}

void Union(int a, int b) {
    int pa = Find(a);
    int pb = Find(b);

    if (pa == pb) {
        if (c[pb].first < c[pb].second) c[pb].first++;
        return;
    }

    p[pb] = pa;
    c[pa].second += c[pb].second;
    c[pa].first = min(c[pa].second, c[pa].first + 1 + c[pb].first);
}

void solve(int CASE = -1) {
    int n;
    vector<pii> arr;

    cin >> n;
    arr.resize(n);
    iota(p.begin(), p.end(), 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i].second;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        Union(arr[i].first, arr[i].second);
    }

    for (int i = 0; i <= 1000000; i++)
        if (p[i] == i) count += c[i].first;

    cout << count;
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