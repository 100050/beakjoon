#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;

void solve() {
    int n, num, mid;
    priority_queue<int, vector<int>, greater<int>> max;
    priority_queue<int> min;
    vector<int> mids;

    cin >> n;
    cin >> num;
    mid = num;
    mids.push_back(num);
    for (int i = 2; i <= n; i++) {
        cin >> num;

        if (num < mid) {
            min.push(num);
        }
        else {
            max.push(num);
        }

       // cout << mid << " " << num << "\n";
        if (i % 2 == 1) {
            if (max.size() > min.size()) {
                /*int count = 1 + min.size();
                while (i / 2  != count) {
                    min.push(max.top());
                    max.pop();
                    count++;
                }*/
                min.push(mid);
                mid = max.top();
                max.pop();
            }
            else if (max.size() < min.size()){
                /*int count = 1 + max.size();
                while (i / 2 != count) {
                    max.push(-min.top());
                    min.pop();
                    count++;
                }*/
                max.push(mid);
                mid = min.top();
                min.pop();
            }
            mids.push_back(mid);
        }
    }
        
    cout << mids.size();
    for (int i = 0; i < mids.size(); i++) {
        if (i % 10 == 0) {
            cout << "\n";
        }
        cout << mids[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}