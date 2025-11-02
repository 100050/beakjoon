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

using ll = unsigned long long;
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
    int n, m;
    vector<pii> arr;
    priority_queue<tuple<int, int, int>, 
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>> pq;
    
    cin >> n;
    arr.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first;
        arr[i].second = 0;
        pq.push(make_tuple(arr[i].first, i, 0));
    }

    cin >> m;
    while (m--) {
        int q;

        cin >> q;

        if (q == 1) {
            int i, v;
            cin >> i >> v;

            arr[i].first = v;
            arr[i].second++;
            pq.push(make_tuple(arr[i].first, i, arr[i].second));
        }
        else {
            tuple<int, int, int> top = pq.top();
            auto& [value, idx, version] = top;
            while (arr[idx].second != version) {
                pq.pop();
                top = pq.top();
                auto& [value, idx, version] = top;
            }
            cout << get<1>(top) << "\n";
        }
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