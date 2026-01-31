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

int ccw(const pil& a, const pil& b, const pil& c) {
    ll op = a.first * b.second + b.first * c.second + c.first * a.second;
    op -= (a.second * b.first + b.second * c.first + c.second * a.first);

    if (op > 0) return 1;
    else if (op == 0)return 0;
    else return -1;
}

void solve(int CASE = -1) {
    int n;
    vector<pair<pil, int>> arr;

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first.first >> arr[i].first.second;
        arr[i].second = i;
    }

    swap(arr[0], *min_element(arr.begin(), arr.end()));
    // 정렬
    sort(arr.begin() + 1, arr.end(), [&](const pair<pil, int>& a, const pair<pil, int>& b) {
        int res = ccw(arr[0].first, a.first, b.first);
        auto dist = [](const pil& a, const pil& b) {
            return (a.first - b.first) * (a.first - b.first)
                + (a.second - b.second) * (a.second - b.second);
            };
        // 일직선이라면 거리를 기준으로 정렬
        if (res == 0) return dist(arr[0].first, a.first) < dist(arr[0].first, b.first);
        else          return res > 0;
        });

    // 마지막 점들이 시작점과 일적선인 경우 reverse
    int i = n - 1, j = n - 2;
    while (j >= 0) {
        if (ccw(arr[0].first, arr[i].first, arr[j].first) != 0) {
            break;
        }
        i--;
        j--;
    }

    reverse(arr.begin()+i, arr.end());

    for (int i = 0; i < n; i++) {
        cout << arr[i].second;
        if (i != n - 1) cout << " ";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);

        if (i != t)
            cout << "\n";
    }

    return 0;
}