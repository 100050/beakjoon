#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;
using pii = pair<int, int>;
#define x first
#define y second
int main() {

	pii stars[3000];


	map<pii, int> mp;

	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> stars[i].x >> stars[i].y;
	}

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			int nx = stars[i].x + stars[j].x;
			int ny = stars[i].y + stars[j].y;

			pii p(nx, ny);
			
			mp[p] += (i == j ? 1 : 2);
		}
	}

	int max = 0;
	for (auto iter = mp.begin(); iter != mp.end(); iter++) {
		if (max < iter->second) {
			max = iter->second;
		}
	}

	cout << max;

}