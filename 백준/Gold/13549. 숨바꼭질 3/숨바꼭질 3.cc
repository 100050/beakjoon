#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define ll long long

const int mxN = 200001;
int n, k;

vector<int> point(mxN, INT_MAX);
deque<int> que;

void solve() {
    cin >> n >> k;
    
    point[n] = 0;
    que.push_back(n);
    while (!que.empty()) {
        n = que.front();
        que.pop_front();
        
        //cout << n << " " << point[n] << "\n";
        if (n == k)
            break;
        
        if (n != 0 && n * 2 < 100001 && point[2 * n] > point[n] && n < k) {
            point[2 * n] = point[n];
            que.push_front(n * 2);

        }
        if (n - 1 >= 0 && point[n - 1] > point[n] + 1) {
            point[n - 1] = point[n] + 1;
            que.push_back(n - 1);
        }
        if (n + 1 < 100001 && point[n + 1] > point[n] + 1) {
            point[n + 1] = point[n] + 1;
            que.push_back(n + 1);
        }


    }

    cout << point[k];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	solve();


	return 0;
}