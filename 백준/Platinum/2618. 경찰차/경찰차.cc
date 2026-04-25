#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

vector<pii> v;
int dp[1001][1001], cache[1001][1001];
int n, w;

int d(int a, int b) {
	return abs(v[a].first - v[b].first) + abs(v[a].second - v[b].second);
}

int dfs(int a, int b) {
	if (a == w + 1 or b == w + 1)
		return 0;
	
	if (dp[a][b] != 0)
		return dp[a][b];

	int nextCase = max(a, b) + 1;

	int g = dfs(a, nextCase) + d(b, nextCase);
	int h = dfs(nextCase, b) + d(a, nextCase);

	if (g < h) {
		cache[a][b] = 2;
	}
	else {
		cache[a][b] = 1;
	}

	dp[a][b] = min(g, h);

	return dp[a][b];
}

void back() {
	int a = 0, b = 1;

	for (int i = 2; i < w + 2; i++) {
		int nextCase = max(a, b) + 1;
		if (cache[a][b] == 1) {
			cout << "1\n";
			a = i;
		}
		else {
			cout << "2\n";
			b = i;
		}
	}
}

void solve() {
	int a, b;

	cin >> n >> w;

	v.push_back({ 1, 1 });
	v.push_back({ n, n });
	for (int i = 0; i < w; i++) {
		cin >> a >> b;

		v.push_back({ a, b });

	}

	cout<< dfs(0, 1) << "\n";

	back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

    solve();

	return 0;
}