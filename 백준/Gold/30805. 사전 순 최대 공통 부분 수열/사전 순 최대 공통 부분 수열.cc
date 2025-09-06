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

//const ll MOD = 1000000007;
const ll MOD = 10007;
const ld PI = acos(-1.0L);
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };


void solve(int CASE = -1) {
    int n, m, sz = 0;
    vector<int> a, b, res;
    vector<bool> v;

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    b.resize(m);
    v.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    res.resize(min(n, m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j] && !v[j]) {
                int k;
                for (k = 0; k < sz; k++) {
                    // 현재 값보다 크다면 그 값으로 교체
                    if (b[res[k]] < a[i]) {
                        if ((k ? res[k - 1] >= j : 0)) {
                            continue;
                        }
                        for (int g = k; g < sz; g++) {
                            v[res[g]] = false;
                        }
                        res[k] = j;
                        v[j] = true;
                        sz = k + 1;
                        break;
                    }
                }

                if (k == sz) {
                    // 뒤에 값을 추가하려고 하는데 그럴 때는 부분 수열의
                    // 가장 뒷값의 인덱스보다는 커야 함
                    if ((sz ? res[sz - 1] >= j : 0)) {
                        continue;
                    }
                    res[sz] = j;
                    v[j] = true;
                    sz++;
                }
                break;
            }
        }
    }

    cout << sz << "\n";
    for (int i = 0; i < sz; i++)
        cout << b[res[i]] << " ";
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