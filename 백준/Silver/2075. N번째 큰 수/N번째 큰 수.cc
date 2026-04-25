#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;

void solve() {
    int n, num;
    priority_queue<int> pq;

    cin >> n;
    for (int i = 0; i < n * n; i++) {
        cin >> num;

        pq.push(-num);
        if (pq.size() > n)
            pq.pop();
    }


    cout << -pq.top();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}