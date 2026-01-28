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

int ccw(const pil& a, const pil& b, const pil& c) {
    ll op = a.first * b.second + b.first * c.second + c.first * a.second;
    op -= (a.second * b.first + b.second * c.first + c.second * a.first);

    if (op > 0) return 1;
    else if (op == 0)return 0;
    else return -1;
}

ld angle(const pil& a, const pil& b, const pil& c) {
    double aa, bb, cc;
    double ang, temp;

    aa = sqrt(pow(a.first - c.first, 2) + pow(a.second - c.second, 2));
    bb = sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
    cc = sqrt(pow(b.first - c.first, 2) + pow(b.second - c.second, 2));

    temp = (pow(bb, 2) + pow(cc, 2) - pow(aa, 2)) / (2 * bb * cc);
    ang = acos(temp);

    return ang;
}

void solve(int CASE = -1) {
    int n;
    ld l;
    vector<pil> arr;

    cin >> n >> l;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    sort(arr.begin() + 1, arr.end(), [&](const pil& a, const pil& b) {
        int res = ccw(arr[0], a, b);
        auto dist = [](const pil& a, const pil& b) {
            return (a.first - b.first) * (a.first - b.first) 
                + (a.second - b.second) * (a.second - b.second);
            };
        if (res == 0) return dist(arr[0], a) < dist(arr[0], b);
        else          return res > 0;
        });

    stack<int> s;
    s.push(0); s.push(1);

    for (int i = 2; i < n; i++) {
        while (s.size() >= 2) {
            const int b = s.top(); s.pop();
            const int a = s.top();
            if (ccw(arr[i], arr[a], arr[b]) > 0) {
                s.push(b);

                break;
            }
        }
        s.push(i);
    }

    auto dist = [](const pil& a, const pil& b) {
        return (a.first - b.first) * (a.first - b.first)
            + (a.second - b.second) * (a.second - b.second);
        };



    int a, b, c, last;
    last = s.top();
    s.push(0);
    a = s.top(); s.pop();
    b = s.top(); s.pop();
    ld res = 0;
    while (s.size()) {
        c = s.top(); s.pop();

        ld theta = angle(arr[a], arr[b], arr[c]);
        //cout << PI - theta << "\n";
        res += (PI - theta) * l;
        res += sqrt(static_cast<ld>(dist(arr[a], arr[b])));

        a = b;
        b = c;
    }

    res += sqrt(static_cast<ld>(dist(arr[a], arr[b])));
    //res += sqrt(static_cast<ld>(dist(arr[last], arr[b])));

    ld theta = angle(arr[a], arr[b], arr[last]);

    res += (PI - theta) * l;


    cout.precision(0);
    cout << fixed;
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