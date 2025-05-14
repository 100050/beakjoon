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
    int len;
    vector<int> idx;
    string t, p;
    getline(cin, t);
    getline(cin, p);

    len = p.size();
	F = vector<int>(len+1);
	FailureFunction(p);
	
	int i = 0;
	int j = 0;
	for (int i = 0; i < t.size(); i++) {
		while (j > 0 and p[j] != t[i])
			j = F[j - 1];
		if (t[i] == p[j])
			if (j == len - 1) {
				idx.push_back(i - j+1);
				j = F[j];
			}
			else {
				j++;
			}
	}

	cout << idx.size() << "\n";
	for (int id : idx) {
		cout << id << "\n";
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}