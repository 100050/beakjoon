#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int mxN = 1001;
const int mxD = 1000 * 100000 + 1;

vector<pii> arr[mxN];
vector<int> dist;
vector<int> link;
priority_queue<pii, vector<pii>, greater<pii>> pq;

void d(int start, int end) {
    pq.push({ 0, start });
    dist[start] = 0;
    link[start] = -1;

    while (pq.size()) {
        auto n = pq.top();
        pq.pop();

        if (n.second == end) {
            break;
        }
           // cout << n.first << " " << n.second << "\n";

        for (auto& i : arr[n.second]) {
            if (dist[i.first] > n.first + i.second) {
                dist[i.first] = n.first + i.second;
                link[i.first] = n.second;
                pq.push({ dist[i.first], i.first });
            }
        }
    }

}

void solve() {
    int n, m;
    int start, end;

    cin >> n >> m;
    dist = vector<int>(n+1, mxD);
    link = vector<int>(n+1, -1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        arr[a].push_back({ b, c });
        //arr[b].push_back({ a, c });
    }
    cin >> start >> end;

    d(start, end);

    cout << dist[end] << "\n";
    stack<int> s;
    int next = end;
    while (next != -1) {
        s.push(next);
        next = link[next];
    }

    cout << s.size() << "\n";
    while (s.size()) {
        cout << s.top() << " ";
        s.pop();
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();


    return 0;
}