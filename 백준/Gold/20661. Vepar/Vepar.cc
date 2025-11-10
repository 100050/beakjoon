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

bool sieve[10000001];

void get_factors(ll a, ll b, vector<pil>& factor) {
    for (ll i = 2; i <= b; i++) {
        if (sieve[i] != 0) continue;
        
        ll ee = 0;
        for (ll x = i; x <= b; x *= i) {
            ee += b / x;
        }
        //cout << iter->first << " " << ee << "\n";
        factor.push_back(make_pair(i, ee));
    }
    
    int idx = 0;
    a--;
    for (ll i = 2; i <= a; i++) {
        if (sieve[i] != 0) continue;

        ll ee = 0;
        for (ll x = i; x <= a; x *= i) {
            ee += a / x;
        }
        //cout << i << " " << ee << "\n";
        factor[idx].second -= ee;
        idx++;
    }
}

void solve(int CASE = -1) {
    ll a, b, c, d;
    vector<pil> h, l;
    cin >> a >> b >> c >> d;

    // a~b까지의 곱의 소인수분해 구하기
    get_factors(a, b, h);

    // c~d까지의 곱의 소인수분해 구하기
    get_factors(c, d, l);

    // a ... b가 c .. d의 약수인지 확인
    bool flag = true;
    int idx = 0;
    for (int i = 0; i < l.size(); i++) {
        while (idx != h.size() && l[i].first != h[idx].first) idx++;
        if (idx == h.size()) {
            break;
        }
        if (l[i].second < h[idx].second) {
            flag = false;
            break;
        }
        //cout << idx << " " << h.size() << " " << l[i].second << " " << h[idx].second << "\n";
        idx++;
    }
    if (idx != h.size()) {
        while (idx != h.size() && h[idx].second == 0) idx++;
        if (idx != h.size()) flag = false;
    }

    cout << (flag ? "DA" : "NE") << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (ll i = 2; i < 10000001; i++) {
        if (sieve[i]) continue;

        for (ll j = i * i; j < 10000001; j += i) {
            if (sieve[j] != 0) continue;
            sieve[j] = 1;
        }
    }

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}