#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

using ll = long long;
using vii = vector<int, int>;

const int mxN = 10000;
int n, k;

//vector<int> point(mxN, INT_MAX);

void solve() {
    int a, b;
    queue<int> que;
    vector<int> link(mxN, -1);
    vector<char> c(mxN);

    cin >> a >> b;

    que.push(a);
    link[a] = 20000;
    while (que.size()) {
        int n = que.front();
        que.pop();

        //cout << n << " " << link[n] << "\n";
        if (n == b) break;


        // D
        if (n != 0) {
            if (link[(n * 2) % 10000] == -1) {
                que.push((n * 2) % 10000);
                c[(n * 2) % 10000] = 'D';
                link[(n * 2) % 10000] = n;
            }
        }
        // S
        if (n == 0) {
            if (link[9999] == -1) {
                que.push(9999);
                c[9999] = 'S';
                link[9999] = 0;
            }
        }
        else {
            if (link[n - 1] == -1) {
                que.push(n - 1);
                c[n - 1] = 'S';
                link[n - 1] = n;
            }
        }

        if (n != 0) {
            int d1 = n / 1000;
            int d4 = n % 10;
            // L
            if (link[(n - d1 * 1000) * 10 + d1] == -1) {
                que.push((n - d1 * 1000) * 10 + d1);
                c[(n - d1 * 1000) * 10 + d1] = 'L';
                link[(n - d1 * 1000) * 10 + d1] = n;
            }

            // R
            if (link[(n / 10) + d4 * 1000] == -1) {
                que.push((n / 10) + d4 * 1000);
                c[(n / 10) + d4 * 1000] = 'R';
                link[(n / 10) + d4 * 1000] = n;
            }
        }
    }
    // 9999 
    string ans = "";
    int next = b;
    while (next != a) {
        //cout << c[next] << " " << next << " " << link[next] << "\n";
        ans += c[next];

        next = link[next];
    }

    reverse(ans.begin(), ans.end());

    cout << ans;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }


    return 0;
}