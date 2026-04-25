#include <iostream>
#include <vector>
#include <string>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int mxN = 501;
int v, e;

void dfs(int node, vector<int> arr[], vector<int>& visited) {
    for (int n : arr[node]) {
        if (visited[n]) {
            e++;
            continue;
        }

        visited[n] = 1;
        v++;
        dfs(n, arr, visited);
    }
}

void solve() {
    int n, m;
    int a, b;
    int c = 1;

    while (true) {
        cin >> n >> m;

        if (n == 0) break;

        vector<int> arr[mxN];
        vector<int> visited(n+1);
        int t = 0;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;

            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;

            t++;
            visited[i] = 1;
            v = 1;
            e = 0;
            dfs(i, arr, visited);
            if (v - 1 != e) t--;
            //cout << i << " " << v << " " << e << "\n";
        }   
    
        cout << "Case " << c << ": ";

        if (t == 0) {
            cout << "No trees.\n";
        }
        else if (t == 1) {
            cout << "There is one tree.\n";
        }
        else {
            cout << "A forest of "<< t << " trees.\n";
        }

        c++;
    }
    //    traversal(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();


    return 0;
}