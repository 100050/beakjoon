#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

using ll = long long;
using vii = vector<int, int>;

const int mxN = 100001;
int n, k;

vector<int> point(mxN, INT_MAX);
vector<int> link(mxN + 1, -1);
deque<int> que;

void solve() {
    cin >> n >> k;

    point[n] = 0;
    int start = n;
    que.push_back(n);
    while (!que.empty()) {
        n = que.front();
        que.pop_front();

        //cout << n << " " << point[n] << "\n";
        if (n == k)
            break;

        if (n != 0 && n * 2 < 100001 && point[2 * n] > point[n] + 1 && n < k) {
            link[2 * n] = n;
            point[2 * n] = point[n] + 1;
            que.push_back(n * 2);

        }
        if (n - 1 >= 0 && point[n - 1] > point[n] + 1) {
            link[n - 1] = n;
            point[n - 1] = point[n] + 1;
            que.push_back(n - 1);
        }
        if (n + 1 < 100001 && point[n + 1] > point[n] + 1) {
            link[n + 1] = n;
            point[n + 1] = point[n] + 1;
            que.push_back(n + 1);
        }


    }

    cout << point[k] << "\n";

    int next = k;
    stack<int> ans;
    while (next != -1) {
        ans.push(next);
        next = link[next];
    }

    while (ans.size()) {
        cout << ans.top() << " ";
        ans.pop();
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();


    return 0;
}