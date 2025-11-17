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

void solve(int CASE = -1) {
    string str;
    vector<int> a(26, 0);
    vector<pii> aa(26, pii(0, 0));
    cin >> str;

    auto ctoi = [](const char& c) -> int {
        return c - 'A';
        };

    for (int i = 0; i < str.size(); i++) {
        if (a[ctoi(str[i])] == 0) {
            a[ctoi(str[i])] = 1;
            aa[ctoi(str[i])].first = i;
        }
        else {
            aa[ctoi(str[i])].second = i;
        }
    }

    int res = 0;
    for (int i = 0; i < 26; i++) {
        vector<int> count(26, 0);
        for (int j = aa[i].first; j <= aa[i].second; j++) {
            if (count[ctoi(str[j])] == 0) {
                count[ctoi(str[j])] = 1;
                res++;
            }
            else {
                res--;
            }
        }
    }

    cout << res / 2;
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