#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;

ll dp[11] = {
	0, 9, 9, 90, 90, 900, 900, 9000, 9000, 90000, 90000 
};

ll digit(ll x) {
	int cnt = 0;
	while (x) {
		x /= 1LL *10;
		cnt++;
	}

	return cnt;
}
int main() {
	ll N; cin >> N;
	ll d = digit(N);
	ll ans = 0;
	if (d == 1) {
		cout << N;
		return 0;
	}
	for (int i = 1; i <= d - 1; i++) {
		ans += dp[i];
	}
	ll ld = d / 2;
	ll num = pow(10, ld-1);

	ll last = d % 2 == 0 ? N/(num*10): N/(num*100);
	//cout << num << " " << last << "\n";
	for (ll i = num; i <= last; i++) {
		ll n = i * num * (d % 2 == 0 ? 10 : 100);
		ll n2 = 0, i2 = i;
		while (i2) {
			n2 *= 10;
			n2 += i2 % 10;
			i2 /= 10;
		}

		if (n + n2 <= N) {
			if (d % 2 == 1) {
				for (int i = 0; i <= 9; i++) {
					if (n2 + n + i * num * 10 <= N) ans++;
				}
			}
			else {
				ans++;
			}
		}
	}

	cout << ans;
}