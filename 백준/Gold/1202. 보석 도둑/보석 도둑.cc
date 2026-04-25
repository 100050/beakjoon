#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;

void solve() {
    int n, k, t, m, v;
    vector<int> c;
    
    vector<pil> j;

    cin >> n >> k;
    //vector<bool> chk(k);
    for (int i = 0; i < n; i++) {
        cin >> m >>v;
        j.push_back({ m, v });
    }
    for (int i = 0; i < k; i++) {
        cin >> t;
        c.push_back(t);
    }
    // 가치(v) 순으로 우선순위 큐
    // 가방 최대 무게 정렬
    // 이진 탐색으로 가방 크기에 최대한 맞는 보석 넣기
    sort(c.begin(), c.end());
    sort(j.begin(), j.end());

    long long total = 0;
    priority_queue<int> pq;
    auto cit = c.begin();
    auto jit = j.begin();
    while (cit != c.end()) {
        
        while (jit != j.end() && jit->first <= *cit) {
            pq.push(jit->second);
            jit++;
        }

        if (pq.size()) {
            total += pq.top();
            pq.pop();
        }
        
        cit++;
    }

    cout << total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}