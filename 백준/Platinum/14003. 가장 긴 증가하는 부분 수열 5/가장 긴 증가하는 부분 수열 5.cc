#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

vector<int> original;
vector<int> sequence;
vector<int> dir;

void solve() {
	int n;
	int i, d;

	cin >> n;
	dir = vector<int>(n, -1);
	for (i = 0; i < n; i++) {
		cin >> d;
		original.push_back(d);
	}

	for (i = 0; i < n; i++) {
		int idx = lower_bound(sequence.begin(), sequence.end(), original[i]) - sequence.begin();
		
		dir[i] = idx + 1;
		// -50 -40 -30 20 -100 -45
	//cout << i << " " << idx;
		if (sequence.size() <= idx) {
			sequence.push_back(original[i]);
			continue;
		}
		sequence[idx] = original[i];
	}

	cout << sequence.size() << "\n";
	int ans = sequence.size();
	vector<int> result;

	for (int i = n - 1; i >= 0; i--) {
		if (dir[i] == ans) {
			ans--;
			result.push_back(original[i]);
		}
	}
	reverse(result.begin(), result.end());
	for (auto a : result) {
		cout << a << " ";
	}
	/*
	벡터에 삽입 -> lower_bound로 인덱스 찾기 -> 그 인덱스에 넣기
	10 20 10 30 20 50

	10 
	10 20
	10 20
	*/
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

    solve();

	return 0;
}