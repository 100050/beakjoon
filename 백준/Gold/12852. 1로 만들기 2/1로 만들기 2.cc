#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <climits>
using namespace std;

#define ll long long

vector<pair<int, int>> arr(1000000, { 0, INT_MAX });

void calc(int x) {
	if (x == 1) {
		return;
	}

	if (x % 3 == 0) {
		if (arr[x / 3].second > arr[x].second + 1) {
			arr[x / 3].second = arr[x].second + 1;
			arr[x / 3].first = x;
			calc(x / 3);
		}
	}
	if (x % 2 == 0) {
		if (arr[x / 2].second > arr[x].second + 1) {
			arr[x / 2].second = arr[x].second + 1;
			arr[x / 2].first = x;
			calc(x / 2);
		}
	}
	
	if (arr[x - 1].second > arr[x].second + 1) {
		arr[x - 1].first = x;
		arr[x - 1].second = arr[x].second + 1;
		calc(x - 1);
	}

}

void solve() {
	int x;

	cin >> x;
	
	arr[x].second = 0;
	calc(x);

	cout << arr[1].second << "\n";
	
	int next = 1;
	vector<int> list;

	while (next != 0) {
		list.push_back(next);
		next = arr[next].first;
	}

	auto compare = [](int a, int b) { return a > b; };

	sort(list.begin(), list.end(), compare);

	for (int i : list) {
		cout << i << " ";
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

    solve();

	return 0;
}