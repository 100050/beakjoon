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

vector<int> prime;
int p[1000001];

void solve(int CASE = -1) {

    for (int i = 2; i <= 1000000; i++) {
        if (p[i] == 1) continue;
        
        if (i * 2 > 1000000) continue;
        for (int j = i * 2; j <= 1000000; j += i) {
            p[j] = 1;
        }
        //cout << i << "\n";
    }
    for (int i = 2; i <= 1000000; i++) {
        if (p[i] == 0)
            prime.push_back(i);
    }

    while (true) {
        int n;

        cin >> n;

        if (n == 0) break;

        int a, b;
        for (int pp : prime) {
            if (pp * 2 > n) break;
            a = pp;
            b = n - pp;
            if (p[b] == 0) break;
        }

        if (a + b == n && p[b] == 0)
            cout << n << " = " << a << " + " << b << "\n";
        else
            cout << "Goldbach's conjecture is wrong.\n";
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