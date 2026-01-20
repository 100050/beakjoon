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
constexpr T INF = numeric_limits<T>::max();
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

void solve(int CASE = -1) {
    int n;
    vector<pii> parr, narr;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (a <= b) {
            parr.push_back(make_pair(a, b));
        }
        else {
            narr.push_back(make_pair(a, b));
        }
    }

    sort(parr.begin(), parr.end(), [](const pii& a, const pii& b) {
        return a.first < b.first;
        });

    ll s = 0;
    ll extra = 0;
    for (int i = 0; i < parr.size(); i++) {
        //cout << parr[i].first << " " << parr[i].second << "\n";
        if (parr[i].first <= s) {
            s += parr[i].second - parr[i].first;
        }
        else {
            extra += parr[i].first - s;
            s += parr[i].second - s; // b-a에 extra로 추가한 것까지 포함
        }
    }

    sort(narr.begin(), narr.end(), [](const pii& a, const pii& b) {
        return a.second > b.second;
        });

    for (int i = 0; i < narr.size(); i++) {
        if (narr[i].first <= s) {
            s += narr[i].second - narr[i].first;
        }
        else {
            extra += narr[i].first - s;
            s += narr[i].second - s;
        }
    }

    cout << extra;
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