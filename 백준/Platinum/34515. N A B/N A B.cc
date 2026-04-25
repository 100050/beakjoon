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

int nrr[19], arr[20], brr[20];
ll dp[19][2][2][2][2][20][20];
ll ia, ib;

ll dfs(int pos, bool same, bool same2, bool same3, bool zero, int a, int b, ll num) {
    if (pos == -1) {
        //cout << a << " " << b << " " << num << "\n";
        if (a == 0 && b == 0 && (num != ia && num != ib)) return 1;
        else return 0;
    }

    ll& ret = dp[pos][same][same2][same3][zero][a][b];
    //cout << pos << " " << a << " " <<  b << " " << ret << "\n";
    if (ret != -1) return ret;

    ret = 0;
    // 아직 수를 구성하지 않았을 때
    if (zero && pos != 0) {
        ret += dfs(pos - 1, same && nrr[pos] == 0, same2, same3, zero, a, b, num);
    }
    // zero==true일 경우 위에서 처리함, 아닐 경우 여기서 처리해야 함
    for (int i = zero; i < 10; i++) {
        int na = max(a - (arr[a] == i), 0);
        int nb = max(b - (brr[b] == i), 0);
        ll r;
        if (same) {
            if (i < nrr[pos]) {
                r = dfs(pos - 1, false, same2 && (na == a - 1), same3 && (nb == b - 1), zero && !i,
                    na, nb, num * 10 + i);
                ret = ret + r;
            }
            else if (i == nrr[pos]) {
                r = dfs(pos - 1, true, same2 && (na == a - 1), same3 && (nb == b - 1), zero && !i,
                    na, nb, num * 10 + i);
                ret = ret + r;
            }
        }
        else {
            r = dfs(pos - 1, false, same2 && (na == a - 1), same3 && (nb == b - 1), zero && !i,
                na, nb, num * 10 + i);
            ret = ret + r;
        }
        //if (r != 0)
            //cout << pos << " " << i << " " << a - (arr[a] == i) 
            //<< " " << b - (brr[b] == i) << " " << ret << "\n";
    }

    return ret;

}

void solve(int CASE = -1) {
    string n, a, b;

    cin >> n >> a >> b;
    ia = stoll(a);
    ib = stoll(b);
    if (a == n || b == n) {
        cout << "0\n";
        return;
    }
    int nl = n.length();
    for (int i = 0; i < nl; i++) {
        nrr[nl - i - 1] = n[i] - '0';
    }
    for (int i = nl; i < 19; i++) {
        nrr[i] = 0;
    }
    int al = a.length();
    for (int i = 0; i < al; i++) {
        arr[al - i] = a[i] - '0';
    }
    for (int i = al + 1; i <= 19; i++) {
        arr[i] = 0;
    }
    int bl = b.length();
    for (int i = 0; i < bl; i++) {
        brr[bl - i] = b[i] - '0';
    }
    for (int i = bl + 1; i <= 19; i++) {
        brr[i] = 0;
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(18, true, true, true, true, al, bl, 0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}