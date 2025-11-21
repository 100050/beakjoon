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
    int n;

    cin >> n;
    vector<int> index;
    vector<int> a, b;
    vector<array<int, 2>> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        arr[i] = { n - i + 1, n - i + 1 };
    }

    int target = n;
    bool flag = false;
    for (int i = 1; i <= n && target != 0; i++) {
        int t;
        if (arr[i][0] == target) {
            t = 0;
        }
        else if (arr[i][1] == target) {
            t = 1;

        }
        else {
            continue;
        }
        for (int j = i; j <= n - 1 && target != j; j++) {
            if (arr[j + 1][0] >= arr[j + 1][1]) {
                index.push_back(j);
                a.push_back(arr[j][t]);
                b.push_back(arr[j + 1][1]);
                swap(arr[j][t], arr[j + 1][1]);
                t = 1;
            }
            else {
                index.push_back(j);
                a.push_back(arr[j][t]);
                b.push_back(arr[j + 1][0]);
                swap(arr[j][t], arr[j + 1][0]);
                t = 0;
            }
        }
        i = 0;
        if (flag)
            target--, flag = false;
        else
            flag = true;
    }

    //for (int i = 1; i <= n; i++) {
    //    cout << arr[i][0] << " " << arr[i][1] << "\n";
    //}
    //if (index.size()*10 > 7 * n * n) cout << n << "\n";
    cout << index.size() << "\n";
    for (int i = 0; i < index.size(); i++) {
        cout << index[i] << " " << a[i] << " " << b[i] << "\n";
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