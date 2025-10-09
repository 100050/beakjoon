#include <iostream>
#include <string>
#include <sstream>
// c

using namespace std;

string happy = "HAPPY";
string sad = "SAD";

bool is_in(string a, char b) {
	for (char x : a) {
		if (x == b) return true;
	}
	return false;
}
int main() {
	int Ph = 0, Pg = 0;
	int ans = 0;

	string tmp;
	getline(cin, tmp);


	for (char a : tmp) {
		if (a == ' ' || a == '\n') continue;

		if (is_in(happy, a)) Ph += 1;
		if (is_in(sad, a)) Pg += 1;
	}
	//cout << tmp << " ";

	cout.precision(2);
	cout << fixed;
	//cout << Ph << " " << Pg;
	if (!Ph && !Pg) cout << "50.00" << '\n';
	else {
		int c = Ph, p = Ph + Pg;

		for (int i = 0; i < 6; i++) {
			//cout << c / p << " ";
			ans += c / p;
			ans *= 10;
			c = (c % p) * 10;
		}

		//cout << ans << " ";

		int aans = ans / 10000;
		int bans = (ans % 10000) / 100 + ((ans % 100) >= 50);
		cout << aans << ".";
		if (bans < 10) cout << "0";
		cout << bans;
	}

	return 0;
}