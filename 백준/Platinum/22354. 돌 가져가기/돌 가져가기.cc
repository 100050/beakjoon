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


void solve() {
    int N;
    cin >> N;

    char ch;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> ch;
        vec[i] = (ch == 'B' ? 1 : 0);
    }

    ll buf;
    deque<ll> dq;
    for (int i = 0; i < N; i++) {
        cin >> buf;
        dq.push_back(buf);
    }

    int lo = 0, hi = N - 1;
    for (; lo < N and vec[lo] == vec[0]; lo++) dq.pop_front();
    if (lo == N) {
        cout << 0;
        return;
    }
    for (; hi >= 0 and vec[hi] == vec.back(); hi--) dq.pop_back();
    if (lo > hi) {
        cout << 0;
        return;
    }

    int preC = vec[lo];
    ll preV = 0;
    vector<ll> V;
    for (int i = lo; i <= hi; i++) {
        ll cur = dq.front();
        dq.pop_front();

        if (preC == vec[i]) {
            preV = max(preV, cur);
        }
        else {
            V.push_back(preV);
            preC = (preC + 1) % 2;
            preV = cur;
        }
    }
    V.push_back(preV);

    sort(V.begin(), V.end());
    ll sum = 0;
    for (int i = (int)V.size()-1; i >= (int)V.size()/2; i--) {
        sum += V[i];
    }

    cout << sum;
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