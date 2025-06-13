#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <cstdlib>   
#include <ctime> 
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

vector<ll> s;
ll dp[100001];
priority_queue<pil, vector<pil>, less<pil>> pq;

void solve() {
    int n, k;

    cin >> n >> k;

    s.push_back(0);
    for (int i = 1; i <= n; i++) {
        ll t;
        cin >> t;

        s.push_back(t + s[i - 1]);
    }

    for (int i = 1; i <= n; i++) {
        while (pq.size() && pq.top().second < i - k) {
            pq.pop();
        }

        pq.push({ dp[i - 1] - s[i], i});

        dp[i] = s[i] + pq.top().first;
        if (i <= k) dp[i] = max(s[i], dp[i]);
        //cout << s[i]<< " " << dp[i] << "\n";
    }

    cout << dp[n];

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}