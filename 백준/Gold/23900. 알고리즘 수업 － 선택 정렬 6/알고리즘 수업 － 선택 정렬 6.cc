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
    int cnt = 0, flag = 0;
    vector<int> arr;
    vector<int> arr2;

    cin >> n;
    arr.resize(n);
    arr2.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
        if (arr[i] != arr2[i]) cnt++;
    }

    if (cnt == 0) flag = 1;
    // 좌표압축
    vector<int> ans(arr);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    vector<int> m(ans.size()); // 각 정수의 위치
  
    for (int i = 0; i < n; i++) {
        arr[i] = distance(ans.begin(), lower_bound(ans.begin(), ans.end(), arr[i]));
        m[arr[i]] = i;
        arr2[i] = distance(ans.begin(), lower_bound(ans.begin(), ans.end(), arr2[i]));
    }


    for (int i = n - 1; i >= 1; i--) {

        int idx = m[i];
        //cout << i << " " << idx << "\n";

        

        cnt += (arr[idx] == arr2[idx]) + (arr[i] == arr2[i]);
        m[arr[idx]] = i;
        m[arr[i]] = idx;
        swap(arr[idx], arr[i]);
        cnt -= (arr[idx] == arr2[idx]) + (arr[i] == arr2[i]);

        if (cnt == 0) {
            flag = 1;
            break;
        }
    }
    

    cout << flag;
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