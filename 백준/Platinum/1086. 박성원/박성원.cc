#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

int n, k;
vector<string> arr;
vector<int> nums;
int cache[51];
vector<vector<ll>> dp((1 << 15), vector<ll>(101, -1));

ll dfs(ll bit, ll now) {
    if (bit == (1 << n) - 1) {
        if (now % k == 0) return 1;
        return 0;
    }
    ll& ret = dp[bit][now];
    if (ret != -1) return ret;

    ret = 0;

    for (ll i = 0; i < n; i++) {
        if (bit & (1 << i)) continue;
        ll next_bit = bit | (1 << i);
        ll next = ((now * cache[arr[i].size()]) % k + nums[i]) % k;
        ret += dfs(next_bit, next);
    }

    return ret;
}

ll gcd(ll a, ll b) {
    ll r;
    while (true) {
        r = a % b;
        if (r == 0)
            return b;
        a = b;
        b = r;
    }
}

void solve() {

    cin >> n;
    string a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    cin >> k;
    
    cache[0] = 1 % k;
    for (int i = 1; i < 51; i++) cache[i] = (cache[i - 1] * 10) % k;

    for (int i = 0; i < n; i++) {
        ll res = 0;
        for (char ch : arr[i]) {
            res *= 10;
            res += ch - '0';
            res %= k;
        }
        nums.push_back(res);
    }

    ll all, correct;
    all = 1;
    for (int i = 1; i <= n; i++) {
        all *= i;
    }

    correct = dfs(0, 0);

    if (correct == 0) {
        cout << 0 << "/" << 1;
        return;
    }
    if (correct == all) {
        cout << 1 << "/" << 1;
        return;
    }

    // 최대공약수로 나누기
    ll l = gcd(all, correct);
    all /= l;
    correct /= l;
    cout << correct << "/" << all;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}