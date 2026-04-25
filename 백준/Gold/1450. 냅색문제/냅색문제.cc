#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int n, c;
int w[31];
vector<int> l, r;

void calc(int idx, int end, vector<int>& arr, int sum) {
	if (c < sum) {
		return;
	}
	//cout << idx << " " << end << "\n";
	if (idx == end) {
		arr.push_back(sum);
		return;
	}

	calc(idx+1, end, arr, sum + w[idx]);
	calc(idx+1, end, arr, sum);
}

void solve() {

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}

	calc(0, n/2, l, 0);
	calc(n/2, n, r, 0);

	sort(r.begin(), r.end());

	ll res = 0;
	for (int val : l) {
		res += upper_bound(r.begin(), r.end(), c - val) - r.begin();
		//cout << res << "\n";
	}

	cout << res;
}
/*
* 4 7
* 1 2 3 4 w
* 0 2 1 3 l
* 0 3 4 7 r
* 4
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	solve();


	return 0;
}