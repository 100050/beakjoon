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
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<ld, ld>;

const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int n, m;
set<vector<int>> s;
vector<int> arr;

void dfs(int d, vector<int>& cur) {

    if (d == m) {
        s.insert(cur);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (cur.back() <= arr[i]) {
            cur.push_back(arr[i]);
            dfs(d+1, cur);
            cur.pop_back();
        }
    }
}

void solve(int CASE = -1) {

    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> t;
    t.push_back(numeric_limits<int>::min());
    dfs(0, t);

    for (const vector<int>& a : s) {
        for (int i = 1; i < a.size(); i++) {
            cout << a[i] << " ";
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