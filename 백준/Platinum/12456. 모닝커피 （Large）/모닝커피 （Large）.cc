#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
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

void solve(int CASE = -1) {
    ll n, k, c, t, s;
    vector<tuple<ll, ll, ll>> arr;
    priority_queue<pil> pq;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> c >> t >> s;
        arr.push_back(make_tuple(t, s, c));
    }

    sort(arr.begin(), arr.end(), 
        [](const tuple<ll, ll, ll>& a, const tuple<ll, ll, ll>& b) { return  get<0>(a) > get<0>(b); });
    arr.push_back(make_tuple(0, 0, 0));

    int i = 0;
    ll day = get<0>(arr[i]);
    pq.push(make_pair(get<1>(arr[i]), get<2>(arr[i])));
    ll res = 0;
    i++;
    for (; i <= n; i++) {
        auto& [t, s, c] = arr[i];
        if (day != t) {
            if (day - t > pq.top().second) {
                while (true) {
                    res += pq.top().first * pq.top().second;
                    day -= pq.top().second;
                    pq.pop();

                    if (pq.empty()) break;
                    else if (day - t <= pq.top().second) break;
                }
            }

            if (day == t || pq.empty());
            else if (day - t == pq.top().second) {
                res += pq.top().first * pq.top().second;
                pq.pop();
            }
            else {
                res += pq.top().first * (day - t);
                pil tmp = pq.top(); pq.pop();
                tmp.second -= day - t;
                pq.push(tmp);
            }
            day = t;
        }
        pq.push(make_pair(s, c));
    }


    cout << "Case #" << CASE << ": " << res << "\n";
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