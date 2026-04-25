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

const ll MOD = 1000000007;
//const ll MOD = 10007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void solve(int CASE = -1) {
    string v, res;
    int arr[26] = { 0, };

    cin >> v;
    for (int i = 0; i < v.size(); i++) {
        arr[v[i] - 'A']++;
    }

    res = "";
    if ((arr['U' - 'A'] + arr['C' - 'A']) > (arr['D' - 'A'] + arr['P' - 'A'] + 1)/2) {
        res = res + 'U';
    }
    if (arr['D' - 'A'] != 0) res = res + "DP";
    else if (arr['P' - 'A'] != 0) res = res + "DP";

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