#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pil = pair<ll, ll>;
using pid = pair<double, double>;

vector<int> F;

void FailureFunction(string pattern)
{
	F[0] = 0;
	
	int j = 0;
	for (int i = 1; i < pattern.size(); i++) {
		while (j > 0 and pattern[j] != pattern[i])
			j = F[j - 1];

		if (pattern[i] == pattern[j])
		{
			F[i] = j + 1;
			j++;
		}
		
	}
}

void solve() {
    int n;
    vector<int> idx;
    string p;
	cin >> n;
	cin >> p;

	F = vector<int>(n+1);
	FailureFunction(p);

	if (F[n - 1] == n) cout << 1;
	else			   cout << n - F[n - 1];
	
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}