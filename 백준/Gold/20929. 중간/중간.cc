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
    int ab, ae, bb, be;

    cin >> n;
    ab = bb = 1;
    ae = be = n;
    int a, b;

    while (ab <= ae && bb <= be) {
        int am = (ab + ae) / 2, bm = (bb + be) / 2;
        cout << "? A " << am << endl;
        cin >> a;
        cout << "? B " << bm << endl;
        cin >> b;
        if (a > b) {
            bb = bm + 1;
            ae = am;
        }
        else if (a < b) {
            ab = am + 1;
            be = bm;
        }
        else {
            break;
        }
    }

    cout << "! " << min(a, b) << endl;
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