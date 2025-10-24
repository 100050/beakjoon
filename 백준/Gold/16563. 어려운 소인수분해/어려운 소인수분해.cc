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

vector<int> primes;
int p[5000001];

void solve(int CASE = -1) {
    p[1] = 1;
    for (ll i = 2; i <= 5000000; i++) {
        if (p[i] != 0) continue;
        primes.push_back(i);

        if (i * i > 5000000) continue;
        for (ll j = i * i; j <= 5000000; j += i) {
            p[j] = 1;
        }
        //cout << i << "\n";
    }

    int n;
    cin >> n;
    while (n--) {
        int k;
        cin >> k;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int p : primes) {
            if (k < p*p) break;
            bool flag = false;
            while (k % p == 0) {
                pq.push(p);
                k /= p;
                flag = true;
            }
            if (k == 1) break;
        }
        if (p[k] == 0) pq.push(k);

        while (pq.size()) {
            if (p[pq.top()] == 0)
                cout << pq.top() << " ";
            pq.pop();
        }
        cout << "\n";
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