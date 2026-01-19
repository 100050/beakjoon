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
    priority_queue<pii, vector<pii>, less<pii>> pq; // (b_i-a_i, a_i)

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (a <= b) {
            parr.push_back(make_pair(a, b));
        }
        else {
            pq.push(make_pair(b, b - a));
        }
    }
    
    // a_i가 작은 것부터
    sort(parr.begin(), parr.end());
    
    ll s = 0;
    
    // parr
    int i = 0;
    while (i != parr.size() && parr[i].first <= s) {
        s += parr[i].second - parr[i].first;
        i++;
    }

    // narr
    while (pq.size()) {
        if (pq.top().first - pq.top().second <= s) {
            //cout << pq.top().first << " " << pq.top().second << "\n";
            s += pq.top().second; pq.pop();
        }
        else {
            break;
        }
    }

    if (s < 0 || i != parr.size() || pq.size()) {
        cout << 0;
    }
    else {
        cout << 1;
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