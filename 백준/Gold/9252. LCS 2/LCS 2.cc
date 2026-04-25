#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

vector<vector<int>> dp;
vector<int> dir;


void solve() {
	string a, b;
	cin >> a >> b;

	int al, bl;
	al = a.length();
	bl = b.length();

	dp = vector<vector<int>>(al+1, vector<int>(bl+1));
	dir = vector<int>(al+1);
	vector<char> res;

	for (int i = 1; i <= al; i++) {
		for (int j = 1; j <= bl; j++) {
			if (a[i-1] == b[j-1]) {
				dp[i][j]  = dp[i-1][j-1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			//cout << dp[i][j] << "\n";
		}
	}

	int l = dp[al][bl];
	int i = al, j = bl;
	cout << l << "\n";
	while (dp[i][j]) {
		if (dp[i][j] == dp[i - 1][j]) {
			i--;
		}
		else if (dp[i][j] == dp[i][j - 1]) {
			j--;
		}
		else {
			res.push_back(a[i-1]);
			i--;
			j--;
		}
		
	}

	reverse(res.begin(), res.end());
	for (auto r : res) {
		cout << r;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

    solve();

	return 0;
}