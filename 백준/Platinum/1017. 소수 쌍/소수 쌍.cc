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
constexpr T INF = numeric_limits<T>::max(); // 오버플로우 조심
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };

int n, m;
vector<int> adj[1001];
vector<int> visited, match, sieve(2001);

bool dfs(int v) {
    
    visited[v] = 1;
    for (int nxt : adj[v]) {
        if (match[nxt] != 0 && visited[match[nxt] - 1]) continue;
        if (match[nxt] == 0 || dfs(match[nxt] - 1)) {
            match[nxt] = v + 1;
            match[v] = nxt + 1;

            return true;
        }
    }

    return false;
}

void solve(int CASE = -1) {
    vector<int> arr;

    cin >> n;
    arr.resize(n);
    match.resize(n);
    visited.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 2; i * i <= 2000; i++) {
        if (sieve[i]) continue;

        for (int j = i * i; j <= 2000; j += i) {
            sieve[j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!sieve[arr[i] + arr[j]]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    bool flag = true;
    vector<int> result;
    for (int nxt : adj[0]) {
        fill(match.begin(), match.end(), 0);
        int res = 1;
        match[nxt] = 1;
        match[0] = nxt + 1;
        for (int i = 1; i < n; i++) {
            if (nxt == i) continue;
            if (match[i] != 0) continue;
            fill(visited.begin(), visited.end(), 0);
            visited[nxt] = 1; visited[0] = 1;
            if (dfs(i)) res++;
            //cout << nxt << " " << arr[i] << " " << arr[match[i] - 1] << " " << res << "\n";
        }
        if (res == n / 2) {
            flag = false;
            result.push_back(arr[nxt]);
        }
    }

    if (flag) {
        cout << -1;
    }
    else {
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
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